#include "utils/attribute.h"
#include <stdio.h>
#include <string.h>

#include <camkes.h>

#include <top_types.h>

static int counter = 0;
#define MAX_UART_COUNTER 256

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

    sprintf(send_UART_Data_UART2Decrypt->raw_data, "UART data: %03d", i);

    send_UART_Data_UART2Decrypt_release();

    printf("%s: Emit data ready", get_instance_name());
    emit_UART2Decrypt_DataReadyEvent_emit();

    unlock();
}

void consume_UART2Decrypt_DataReadyAck_callback(void *in_arg UNUSED) {
    if (counter == MAX_UART_COUNTER) {
        printf("%s: Stop sending to Decrypt\n", get_instance_name());
        return;
    }
    send_to_decrypt(counter++);

    if (consume_UART2Decrypt_DataReadyAck_reg_callback(&consume_UART2Decrypt_DataReadyAck_callback, NULL)) {
        printf("%s failed to register callback", get_instance_name());
    }
}

void consume_UART2Decrypt_DataReadyAck__init(void) {
    if (consume_UART2Decrypt_DataReadyAck_reg_callback(&consume_UART2Decrypt_DataReadyAck_callback, NULL)) {
        printf("%s failed to register callback", get_instance_name());
    }
}

int run(void) {
    printf("Starting %s\n", get_instance_name());

    send_to_decrypt(counter++);
    
    return 0;
}
