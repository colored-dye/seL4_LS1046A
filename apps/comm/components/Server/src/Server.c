#include "camkes-component-server.h"
#include <stdio.h>
#include <string.h>

#include <camkes.h>
#include <camkes/dataport.h>

#include <top_types.h>

// static FC_Data Decrypted_FC_Data;

// void recv_decrypted_data__init(void) {

// }

// void recv_decrypted_data_decrypt2server(const FC_Data *data) {
//     printf("Decrypt to Server: Receive\n");
//     printf("%s\n", data->raw_data);
// }

void consume_Decrypt2Server_callback(void *in_arg UNUSED) {
    recv_FC_Data_Decrypt2Server_acquire();

    printf("%s: %s\n", get_instance_name(), (char*)recv_FC_Data_Decrypt2Server->raw_data);

    consume_Decrypt2Server_DataReadyEvent_reg_callback(&consume_Decrypt2Server_callback, NULL);
}

void consume_Decrypt2Server__init(void) {
    
}

int run(void) {
    printf("Starting %s\n", get_instance_name());

    if (consume_Decrypt2Server_DataReadyEvent_reg_callback(&consume_Decrypt2Server_callback, NULL)) {
        printf("%s failed to register callback", get_instance_name());
    }

    // while (1) {
    //     if (consume_Decrypt2Server_DataReadyEvent_poll()) {
    //         puts("Server: consume event");
    //     } else {
    //         puts("Server: No event yet");
    //     }
    // }
    while (1) {

    }

    return 0;
}
