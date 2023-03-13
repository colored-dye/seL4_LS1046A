#ifndef __Server_types_H__
#define __Server_types_H__

#include <smaccm_types.h>

void component_entry(const int64_t *periodic_dispatcher);
void component_init(const int64_t *arg);

bool self2encrypt_enqueue(const SMACCM_DATA__GIDL *self2encrypt);
bool decrypt2self_dequeue(SMACCM_DATA__GIDL_container *decrypt2self);

#ifdef __cplusplus
extern "C" {
#endif

// #include "ivory.h"
// #include "input_tb_decrypt2self_dequeue_monitor.h"

#ifdef __cplusplus
}
#endif

#endif
