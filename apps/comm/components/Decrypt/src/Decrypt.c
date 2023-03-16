#include <stdio.h>
#include <string.h>

#include <camkes.h>

#include <top_types.h>

static int counter = 0;
#define MAX_DECRYPT_COUNTER 256

#define lock() \
    do { \
        if (decrypt_lock()) { \
            printf("%s failed to lock: %d\n", get_instance_name(), __LINE__); \
        } \
    } while (0)

#define unlock() \
    do { \
        if (decrypt_unlock()) { \
            printf("%s failed to unlock: %d\n", get_instance_name(), __LINE__); \
        } \
    } while (0)

// Receive event from UART, signal data ready
void consume_UART2Decrypt_DataReadyEvent_callback(void *in_arg UNUSED) {
    lock();
    recv_UART_Data_UART2Decrypt_acquire();

    printf("%s: %s\n", get_instance_name(), (char*)recv_UART_Data_UART2Decrypt->raw_data);

    consume_UART2Decrypt_DataReadyEvent_reg_callback(&consume_UART2Decrypt_DataReadyEvent_callback, NULL);

    emit_UART2Decrypt_DataReadyAck_emit();
    unlock();
}

void send_to_server(int i) {
    lock();

    sprintf(send_FC_Data_Decrypt2Server->raw_data, "FC data: %03d", i);

    send_FC_Data_Decrypt2Server_release();

    printf("%s: Emit data ready\n", get_instance_name());
    emit_Decrypt2Server_DataReadyEvent_emit();
    unlock();
}

void consume_UART2Decrypt_DataReadyEvent__init(void) {
    if (consume_UART2Decrypt_DataReadyEvent_reg_callback(&consume_UART2Decrypt_DataReadyEvent_callback, NULL)) {
        printf("%s failed to register UART2Decrypt_DataReadyEvent callback\n", get_instance_name());
    }
}

void consume_Decrypt2Server_DataReadyAck_callback(void *in_arg UNUSED) {
    if (counter == MAX_DECRYPT_COUNTER) {
        printf("%s: Stop sending to Server\n", get_instance_name());
        return;
    }
    send_to_server(counter++);

    if (consume_Decrypt2Server_DataReadyAck_reg_callback(&consume_Decrypt2Server_DataReadyAck_callback, NULL)) {
        printf("%s failed to register Decrypt2Server_DataReadyAck callback\n", get_instance_name());
    }
}

void consume_Decrypt2Server_DataReadyAck__init(void) {
    if (consume_Decrypt2Server_DataReadyAck_reg_callback(&consume_Decrypt2Server_DataReadyAck_callback, NULL)) {
        printf("%s failed to register Decrypt2Server_DataReadyAck callback\n", get_instance_name());
    }
}

int run(void) {
    printf("Starting %s\n", get_instance_name());

    // Signal UART to start sending data
    emit_UART2Decrypt_DataReadyAck_emit();
    
    send_to_server(counter++);

    return 0;
}
