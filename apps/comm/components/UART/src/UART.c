#include <stdio.h>
#include <string.h>

#include <camkes.h>
#include <camkes/dataport.h>

#include <top_types.h>

void send_to_decrypt(int i) {
    consume_UART2Decrypt_DataReadyAck_wait();

    sprintf(send_UART_Data_UART2Decrypt->raw_data, "Hello, this is UART [%03d]", i);

    send_UART_Data_UART2Decrypt_release();

    printf("%s: Emit data ready", get_instance_name());
    emit_UART2Decrypt_DataReadyEvent_emit();
}

int run(void) {
    printf("Starting %s\n", get_instance_name());

    for (int i=0; i<256; i++) {
        send_to_decrypt(i);
    }
    
    return 0;
}
