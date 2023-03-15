#include "camkes-component-decrypt.h"
#include "utils/attribute.h"
#include <stdio.h>
#include <string.h>

#include <camkes.h>
#include <camkes/dataport.h>

#include <top_types.h>

void consume_UART2Decrypt_callback(void *in_arg UNUSED) {
    recv_UART_Data_UART2Decrypt_acquire();

    printf("%s: %s\n", get_instance_name(), (char*)recv_UART_Data_UART2Decrypt->raw_data);

    consume_UART2Decrypt_DataReadyEvent_reg_callback(&consume_UART2Decrypt_callback, NULL);
}

void consume_UART2Decrypt__init(void) {

}

int run(void) {
    printf("Starting %s\n", get_instance_name());

    if (consume_UART2Decrypt_DataReadyEvent_reg_callback(&consume_UART2Decrypt_callback, NULL)) {
        printf("%s failed to register callback\n", get_instance_name());
    }

    strcpy(send_FC_Data_Decrypt2Server->raw_data, "Hello, this is Decrypt");

    send_FC_Data_Decrypt2Server_release();

    printf("%s: Emit data ready\n", get_instance_name());
    emit_Decrypt2Server_DataReadyEvent_emit();

    while (1) {

    }
    
    return 0;
}
