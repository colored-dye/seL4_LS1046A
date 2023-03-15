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
    consume_Decrypt2Server_DataReadyEvent_reg_callback(&consume_Decrypt2Server_callback, NULL);

    recv_FC_Data_Decrypt2Server_acquire();

    printf("%s: %s\n", get_instance_name(), (char*)recv_FC_Data_Decrypt2Server->raw_data);

    emit_Decrypt2Server_DataReadyAck_emit();
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
