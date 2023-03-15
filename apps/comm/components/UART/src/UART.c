#include <stdio.h>
#include <string.h>

#include <camkes.h>
#include <camkes/dataport.h>

#include <top_types.h>

int run(void) {
    printf("Starting %s\n", get_instance_name());

    strcpy(send_UART_Data_UART2Decrypt->raw_data, "Hello, this is UART");

    send_UART_Data_UART2Decrypt_release();

    printf("%s: Emit data ready", get_instance_name());
    emit_UART2Decrypt_DataReadyEvent_emit();
    
    return 0;
}
