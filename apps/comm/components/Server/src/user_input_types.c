/* This file has been autogenerated by Ivory
 * Compiler version  0.1.0.5
 */
#include "user_input_types.h"

void user_input_get_le(const uint8_t *n_var0, uint32_t n_var1, struct user_input *n_var2)
{
    ivory_serialize_unpack_float_le(n_var0, n_var1, &n_var2->throttle);
    ivory_serialize_unpack_float_le(n_var0, (uint32_t) (n_var1 + (uint32_t) 4U), &n_var2->roll);
    ivory_serialize_unpack_float_le(n_var0, (uint32_t) (n_var1 + (uint32_t) 8U), &n_var2->pitch);
    ivory_serialize_unpack_float_le(n_var0, (uint32_t) (n_var1 + (uint32_t) 12U), &n_var2->yaw);
}

void user_input_get_be(const uint8_t *n_var0, uint32_t n_var1, struct user_input *n_var2)
{
    ivory_serialize_unpack_float_be(n_var0, n_var1, &n_var2->throttle);
    ivory_serialize_unpack_float_be(n_var0, (uint32_t) (n_var1 + (uint32_t) 4U), &n_var2->roll);
    ivory_serialize_unpack_float_be(n_var0, (uint32_t) (n_var1 + (uint32_t) 8U), &n_var2->pitch);
    ivory_serialize_unpack_float_be(n_var0, (uint32_t) (n_var1 + (uint32_t) 12U), &n_var2->yaw);
}

void user_input_set_le(uint8_t *n_var0, uint32_t n_var1, const struct user_input *n_var2)
{
    ivory_serialize_pack_float_le(n_var0, n_var1, &n_var2->throttle);
    ivory_serialize_pack_float_le(n_var0, (uint32_t) (n_var1 + (uint32_t) 4U), &n_var2->roll);
    ivory_serialize_pack_float_le(n_var0, (uint32_t) (n_var1 + (uint32_t) 8U), &n_var2->pitch);
    ivory_serialize_pack_float_le(n_var0, (uint32_t) (n_var1 + (uint32_t) 12U), &n_var2->yaw);
}

void user_input_set_be(uint8_t *n_var0, uint32_t n_var1, const struct user_input *n_var2)
{
    ivory_serialize_pack_float_be(n_var0, n_var1, &n_var2->throttle);
    ivory_serialize_pack_float_be(n_var0, (uint32_t) (n_var1 + (uint32_t) 4U), &n_var2->roll);
    ivory_serialize_pack_float_be(n_var0, (uint32_t) (n_var1 + (uint32_t) 8U), &n_var2->pitch);
    ivory_serialize_pack_float_be(n_var0, (uint32_t) (n_var1 + (uint32_t) 12U), &n_var2->yaw);
}
