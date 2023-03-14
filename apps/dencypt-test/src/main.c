#include <stdint.h>
#include <stdio.h>
#include "gec.h"

struct Person {
    struct gec_sym_key sym_key;
    struct gec_sym_key_conf sym_key_conf;
    struct gec_privkey priv_key;
    struct gec_pubkey pub_key;
};

void print_ct(uint8_t ct[GEC_CT_LEN]) {
    for (int i=0; i<GEC_CT_LEN; i++) {
        printf("%X ", ct[i]);
        if ((i+1)%12 == 0) {
            putchar('\n');
        }
    }
}

int main() {
    struct Person P1;
    struct Person P2;

    uint8_t raw_key1[GEC_RAW_KEY_LEN];
    for(int i=0; i<GEC_RAW_KEY_LEN; i++) {
        raw_key1[i] = i + 1;
    }

    gec_init_sym_key_conf_auth(&P1.sym_key, raw_key1);

    uint8_t pt1[GEC_PT_LEN];
    for(int i=0; i<GEC_PT_LEN; i++) {
        pt1[i] = GEC_PT_LEN - i;
    }
    uint8_t ct[GEC_CT_LEN];
    gec_encrypt(&P1.sym_key, pt1, ct);

    print_ct(ct);

    return 0;
}
