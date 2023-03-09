/*
 * CAmkES tutorial part 2: events and dataports
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include <camkes/dataport.h>
#include <sel4utils/sel4_zf_logif.h>

/* generated header for our component */
#include <camkes.h>

/* hepler function to modify a string to make it all uppercase */
void uppercase(char *str) {
    while (*str != '\0') {
        *str = toupper(*str);
        str++;
    }
}

void callback_handler_2(void *a);

/* this callback handler is meant to be invoked when the first event
 * arrives on the "consumes" event interface.
 * Note: the callback handler must be explicitly registered before the
 * callback will be invoked.
 * Also the registration is one-shot only, if it wants to be invoked
 * when a new event arrives then it must re-register itself.  Or it can
 * also register a different handler.
 */
void callback_handler_1(void *a) {
    /* TASK 19: read some data from the untyped dataport */
    /* hint 1: use the "Buf" dataport as defined in the Echo.camkes file
     * hint 2: to access the dataport use the interface name as defined in Echo.camkes.
     * For example if you defined it as "dataport Buf d" then you would use "d" to refer to the dataport in C.
     * hint 3: first read the number of strings from the dataport
     * hint 4: then print each string from the dataport
     * hint 5: look at https://github.com/seL4/camkes-tool/blob/master/docs/index.md#an-example-of-dataports
     */
    e1_acquire();

    int n = *(int*)e1;
    printf("Echo: %d\n", n);

    str_buf_t echo_str_buf;
    echo_str_buf.n = n;

    char *p = (char*) e1 + 4;

    for (int i=0; i < n - 1; i++) {
        // e1_acquire();
        printf("%s ", p);
        strncpy(echo_str_buf.str[i], p, STR_LEN - 1);
        p += strlen(p) + 1;
    }
    // e1_acquire();
    printf("%s\n", p);
    strncpy(echo_str_buf.str[n-1], p, STR_LEN - 1);

    /* TASK 20: put a modified copy of the data from the untyped dataport into the typed dataport */
    /* hint 1: modify each string by making it upper case, use the function "uppercase"
     * hint 2: read from the "Buf" dataport as above
     * hint 3: write to the "str_buf_t" dataport as defined in the Echo.camkes file
     * hint 4: to access the dataport use the interface name as defined in Echo.camkes.
     * For example if you defined it as "dataport str_buf_t d_typed" then you would use "d_typed" to refer to the dataport in C.
     * hint 5: for the definition of "str_buf_t" see "str_buf.h"
     * hint 6: use the "n" field to specify the number of strings in the dataport
     * hint 7: copy the specified number of strings from the "Buf" dataport to the "str" field
     * hint 8: look at https://github.com/seL4/camkes-tool/blob/master/docs/index.md#an-example-of-dataports
     * hint 9: you could combine this TASK with the previous one in a single loop if you want
     */
    for (int i=0; i < n; i++) {
        uppercase(echo_str_buf.str[i]);
    }
    *(str_buf_t*) e2 = echo_str_buf;
    e2_release();

    /* TASK 21: register the second callback for this event. */
    /* hint 1: use the function <interface name>_reg_callback()
     * hint 2: register the function "callback_handler_2"
     * hint 3: pass NULL as the extra argument to the callback
     * hint 4: look at https://github.com/seL4/camkes-tool/blob/master/docs/index.md#an-example-of-events
     */
    consume_Echo_reg_callback(&callback_handler_2, NULL);

    /* TASK 22: notify the client that there is new data available for it */
    /* hint 1: use the function <interface_name>_emit
     * hint 2: look at https://github.com/seL4/camkes-tool/blob/master/docs/index.md#an-example-of-events
     */
    puts("Echo emit 1");
    emit_Echo_emit();
}

/* this callback handler is meant to be invoked the second time an event
 * arrives on the "consumes" event interface.
 * Note: the callback handler must be explicitly registered before the
 * callback will be invoked.
 * Also the registration is one-shot only, if it wants to be invoked
 * when a new event arrives then it must re-register itself.  Or it can
 * also register a different handler.
 */
void callback_handler_2(void *a) {
    /* TASK 23: read some data from the dataports. specifically:
     * read a dataport pointer from one of the typed dataports, then use
     * that pointer to access data in the untyped dataport.
     */
    /* hint 1: for the untyped dataport use the "Buf" dataport as defined in the Echo.camkes file
     * hint 2: for the typed dataport use the "ptr_buf_t" dataport as defined in the Echo.camkes file
     * hint 3: for the definition of "ptr_buf_t" see "str_buf.h".
     * hint 4: the "n" field of the typed dataport specifies the number of dataport pointers
     * hint 5: the "ptr" field of the typed dataport contains the dataport pointers
     * hint 6: use the function "dataport_unwrap_ptr()" to create a regular pointer from a dataport pointer
     * hint 7: for more information about dataport pointers see: https://github.com/seL4/camkes-tool/blob/master/docs/index.md
     * hint 8: print out the string pointed to by each dataport pointer
     */
    e3_acquire();
    ptr_buf_t echo_ptr_buf = *(ptr_buf_t*) e3;
    for (int i=0; i < echo_ptr_buf.n - 1; i++) {
        printf("%s ", (char*) (dataport_unwrap_ptr(echo_ptr_buf.ptr[i])));
    }
    printf("%s\n", (char*) (dataport_unwrap_ptr(echo_ptr_buf.ptr[echo_ptr_buf.n - 1])));

    /* TASK 24: register the original callback handler for this event */
    /* hint 1: use the function <interface name>_reg_callback()
     * hint 2: register the function "callback_handler_1"
     * hint 3: pass NULL as the extra argument to the callback
     * hint 4: look at https://github.com/seL4/camkes-tool/blob/master/docs/index.md#an-example-of-events
     */
    consume_Echo_reg_callback(&callback_handler_1, NULL);

    /* TASK 25: notify the client that we are done reading the data */
    /* hint 1: use the function <interface_name>_emit
     * hint 2: look at https://github.com/seL4/camkes-tool/blob/master/docs/index.md#an-example-of-events
     */
    puts("Echo emit 2");
    emit_Echo_emit();
}

/* this function is invoked to initialise the echo event interface before it
 * becomes active. */
/* TASK 17: replace "echo" with the actual name of the "consumes" event interface */
/* hint 1: use the interface name as defined in Echo.camkes.
 * For example if you defined it as "consumes TheEvent c_event" then you would use "c_event".
 */
void consume_Echo__init(void) {
    /* TASK 18: register the first callback handler for this interface */
    /* hint 1: use the function <interface name>_reg_callback()
     * hint 2: register the function "callback_handler_1"
     * hint 3: pass NULL as the extra argument to the callback
     * hint 4: look at https://github.com/seL4/camkes-tool/blob/master/docs/index.md#an-example-of-events
     */
    consume_Echo_reg_callback(&callback_handler_1, NULL);
}