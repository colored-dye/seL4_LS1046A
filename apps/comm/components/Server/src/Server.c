#include "Server.h"
#include <string.h>
#include <camkes.h>

static bool occurred_periodic_dispatcher;
static int64_t time_periodic_dispatcher;

bool periodic_dispatcher_write_int64_t(const int64_t * arg) {
    occurred_periodic_dispatcher = true;
    time_periodic_dispatcher = *arg;
    MUTEXOP(dispatch_sem_post());
    return true;
}

void timer_complete_callback(void *_ UNUSED) {
   // we want time in microseconds, not nanoseconds, so we divide by 1000.
   int64_t tb_time_periodic_dispatcher = timer_time() / 1000LL;
   (void)periodic_dispatcher_write_int64_t(&tb_time_periodic_dispatcher);
   CALLBACKOP(timer_complete_reg_callback(timer_complete_callback, NULL));
}

bool tb_self2encrypt_enqueue(const SMACCM_DATA__GIDL * tb_self2encrypt) {
    bool tb_result = true ; 

    tb_result &= self2encrypt0_enqueue((SMACCM_DATA__GIDL_container *)tb_self2encrypt);

    return tb_result;
}

void component_entry(const int64_t *n_var0) {
    SMACCM_DATA__GIDL_container n_local0;
    SMACCM_DATA__GIDL_container *n_ref1 = &n_local0;
    bool n_r2 = decrypt2self0_dequeue(n_ref1);
    
    if (n_r2) {
        // callback_input_decrypt2self_dequeue_handler(n_ref1);
        printf("Server:\n");
        printf("Enter: %s:%s\n", __FILE__, __FUNCTION__);
        printf("Arg: %ld\n", *n_var0);
    }
    return;
}

void component_init(const int64_t *n_var0)
{ }

void entrypoint_Server_periodic_dispatcher(const int64_t * in_arg) {
    component_entry((int64_t *) in_arg);
}

void entrypoint_Server_decrypt2self(const SMACCM_DATA__GIDL * in_arg) {
}

int run(void) {

    // Port initialization routines

    // tb_timer_periodic(0, ((uint64_t)5)*NS_IN_MS);
    CALLBACKOP(timer_complete_reg_callback(timer_complete_callback, NULL));


    // Initial lock to await dispatch input.
    MUTEXOP(dispatch_sem_wait());
    while (1) {
        MUTEXOP(dispatch_sem_wait());

        // Drain the queues
        if (occurred_periodic_dispatcher) {
            occurred_periodic_dispatcher = false;
            entrypoint_Server_periodic_dispatcher(&time_periodic_dispatcher);
        }

    }

    // Won't ever get here, but form must be followed
    return 0;
}

