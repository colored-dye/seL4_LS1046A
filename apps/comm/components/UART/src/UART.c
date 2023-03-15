#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <camkes.h>
#include <camkes/dataport.h>

#include <top_types.h>

#define lock() \
    do { \
        if (uart_lock()) { \
            printf("%s failed to lock: %d\n", get_instance_name(), __LINE__); \
        } \
    } while (0)

#define unlock() \
    do { \
        if (uart_unlock()) { \
            printf("%s failed to unlock: %d\n", get_instance_name(), __LINE__); \
        } \
    } while (0)

void send_to_decrypt(int i) {
    lock();
    // Wait for Decrypt to receive previous data and send ACK
    consume_UART2Decrypt_DataReadyAck_wait();

    sprintf(send_UART_Data_UART2Decrypt->raw_data, "UART data: %03d", i);

    send_UART_Data_UART2Decrypt_release();

    printf("%s: Emit data ready", get_instance_name());
    emit_UART2Decrypt_DataReadyEvent_emit();

    unlock();
}

int run(void) {
    printf("Starting %s\n", get_instance_name());

    for (int i=0; i<256; i++) {
        send_to_decrypt(i);
    }
    
    return 0;
}
