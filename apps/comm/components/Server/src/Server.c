#include "camkes-component-server.h"
#include <stdio.h>
#include <string.h>

#include <camkes.h>
#include <camkes/dataport.h>

#include <top_types.h>

#define lock() \
    do { \
        if (server_lock()) { \
            printf("%s failed to lock: %d\n", get_instance_name(), __LINE__); \
        } \
    } while (0)

#define unlock() \
    do { \
        if (server_unlock()) { \
            printf("%s failed to unlock: %d\n", get_instance_name(), __LINE__); \
        } \
    } while (0)

void consume_Decrypt2Server_callback(void *in_arg UNUSED) {
    lock();
    consume_Decrypt2Server_DataReadyEvent_reg_callback(&consume_Decrypt2Server_callback, NULL);

    recv_FC_Data_Decrypt2Server_acquire();

    printf("%s: %s\n", get_instance_name(), (char*)recv_FC_Data_Decrypt2Server->raw_data);

    emit_Decrypt2Server_DataReadyAck_emit();
    unlock();
}

void consume_Decrypt2Server_DataReadyEvent__init() {
    if (consume_Decrypt2Server_DataReadyEvent_reg_callback(&consume_Decrypt2Server_callback, NULL)) {
        printf("%s failed to register callback", get_instance_name());
    }
}

int run(void) {
    printf("Starting %s\n", get_instance_name());

    // Signal Decrypt to start sending data
    emit_Decrypt2Server_DataReadyAck_emit();

    while (1) {

    }

    return 0;
}
