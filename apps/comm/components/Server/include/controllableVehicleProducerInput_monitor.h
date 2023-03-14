/* This file has been autogenerated by Ivory
 * Compiler version  0.1.0.5
 */
#ifndef __CONTROLLABLEVEHICLEPRODUCERINPUT_MONITOR_H__
#define __CONTROLLABLEVEHICLEPRODUCERINPUT_MONITOR_H__
#ifdef __cplusplus
extern "C" {
#endif
#include "ivory.h"
#include "heartbeat_types.h"
#include "time_micros_types.h"
#include "arming_mode_types.h"
#include "sequence_numbered_packed_status_types.h"
#include "sequence_num_types.h"
#include "packed_status_types.h"
#include "gps_fix_types.h"
#include "tristate_types.h"
#include "control_modes_types.h"
#include "control_source_types.h"
#include "yaw_mode_types.h"
#include "throttle_mode_types.h"
#include "sequence_numbered_control_law_types.h"
#include "control_law_types.h"
#include "sequence_numbered_rc_input_types.h"
#include "rc_input_types.h"
#include "sequence_numbered_user_input_result_types.h"
#include "user_input_result_types.h"
#include "user_input_types.h"
#include "sequence_numbered_sensors_result_types.h"
#include "sensors_result_types.h"
#include "xyz_types.h"
#include "quaternion_types.h"
#include "sequence_numbered_gyroscope_sample_types.h"
#include "gyroscope_sample_types.h"
#include "sequence_numbered_accelerometer_sample_types.h"
#include "accelerometer_sample_types.h"
#include "sequence_numbered_barometer_sample_types.h"
#include "barometer_sample_types.h"
#include "sequence_numbered_lidarlite_sample_types.h"
#include "lidarlite_sample_types.h"
#include "sequence_numbered_magnetometer_sample_types.h"
#include "magnetometer_sample_types.h"
#include "sequence_numbered_px4flow_integral_sample_types.h"
#include "px4flow_integral_sample_types.h"
#include "sequence_numbered_px4flow_sample_types.h"
#include "px4flow_sample_types.h"
#include "sequence_numbered_position_sample_types.h"
#include "position_sample_types.h"
#include "sequence_numbered_control_setpoint_types.h"
#include "control_setpoint_types.h"
#include "sequence_numbered_control_output_types.h"
#include "control_output_types.h"
#include "sequence_numbered_quadcopter_motors_types.h"
#include "quadcopter_motors_types.h"
#include "sequence_numbered_att_control_debug_types.h"
#include "att_control_debug_types.h"
#include "pid_state_types.h"
#include "sequence_numbered_alt_control_debug_types.h"
#include "alt_control_debug_types.h"
#include "sequence_numbered_px4io_state_types.h"
#include "px4io_state_types.h"
#include "px4io_status_types.h"
#include "px4io_alarms_types.h"
#include "sequence_numbered_arming_status_types.h"
#include "arming_status_types.h"
#include "sequence_numbered_float_types.h"
#include "sequence_numbered_pid_config_types.h"
#include "pid_config_types.h"
#include "sequence_numbered_throttle_ui_types.h"
#include "throttle_ui_types.h"
#include "sequence_numbered_stab_config_types.h"
#include "stab_config_types.h"
#include "sequence_numbered_tristate_types.h"
#include "sequence_numbered_control_modes_types.h"
#include "sequence_numbered_user_input_types.h"
#include "sequence_numbered_rgb_led_setting_types.h"
#include "rgb_led_setting_types.h"
#include "sequence_numbered_camera_target_types.h"
#include "camera_target_types.h"
#include "sequence_numbered_reboot_req_types.h"
#include "reboot_req_types.h"
#include "reboot_magic_types.h"
#include "smaccm_camera_module.h"
#include "towerCameraVMDeps.h"
#include "output_self2encrypt_enqueue_monitor.h"
void callback_rebootReqSetRespProducer(const uint32_t *n_var0);
void callback_nominalThrottleSetRespProducer(const uint32_t *n_var0);
void callback_nominalThrottleGetRespProducer(const struct sequence_numbered_float *n_var0);
void callback_altitudeRatePidSetRespProducer(const uint32_t *n_var0);
void callback_altitudeRatePidGetRespProducer(const struct sequence_numbered_pid_config *n_var0);
void callback_altitudePositionPidSetRespProducer(const uint32_t *n_var0);
void callback_altitudePositionPidGetRespProducer(const struct sequence_numbered_pid_config *n_var0);
void callback_throttleUiSetRespProducer(const uint32_t *n_var0);
void callback_throttleUiGetRespProducer(const struct sequence_numbered_throttle_ui *n_var0);
void callback_attitudeRollStabSetRespProducer(const uint32_t *n_var0);
void callback_attitudeRollStabGetRespProducer(const struct sequence_numbered_stab_config *n_var0);
void callback_attitudePitchStabSetRespProducer(const uint32_t *n_var0);
void callback_attitudePitchStabGetRespProducer(const struct sequence_numbered_stab_config *n_var0);
void callback_yawRatePidSetRespProducer(const uint32_t *n_var0);
void callback_yawRatePidGetRespProducer(const struct sequence_numbered_pid_config *n_var0);
void callback_yawPositionPidSetRespProducer(const uint32_t *n_var0);
void callback_yawPositionPidGetRespProducer(const struct sequence_numbered_pid_config *n_var0);
void callback_armingRequestSetRespProducer(const uint32_t *n_var0);
void callback_armingRequestGetRespProducer(const struct sequence_numbered_tristate *n_var0);
void callback_controlModesRequestSetRespProducer(const uint32_t *n_var0);
void callback_controlModesRequestGetRespProducer(const struct sequence_numbered_control_modes *n_var0);
void callback_userInputRequestSetRespProducer(const uint32_t *n_var0);
void callback_userInputRequestGetRespProducer(const struct sequence_numbered_user_input *n_var0);
void callback_rgbLedSetRespProducer(const uint32_t *n_var0);
void callback_rgbLedGetRespProducer(const struct sequence_numbered_rgb_led_setting *n_var0);
void callback_cameraTargetInputGetRespProducer(const struct sequence_numbered_camera_target *n_var0);
void callback_heartbeatProducer(const struct heartbeat *n_var0);
void callback_packedStatusGetRespProducer(const struct sequence_numbered_packed_status *n_var0);
void callback_controlLawGetRespProducer(const struct sequence_numbered_control_law *n_var0);
void callback_rcInputGetRespProducer(const struct sequence_numbered_rc_input *n_var0);
void callback_userInputGetRespProducer(const struct sequence_numbered_user_input_result *n_var0);
void callback_sensorsOutputGetRespProducer(const struct sequence_numbered_sensors_result *n_var0);
void callback_gyroOutputGetRespProducer(const struct sequence_numbered_gyroscope_sample *n_var0);
void callback_accelOutputGetRespProducer(const struct sequence_numbered_accelerometer_sample *n_var0);
void callback_baroOutputGetRespProducer(const struct sequence_numbered_barometer_sample *n_var0);
void callback_lidarliteOutputGetRespProducer(const struct sequence_numbered_lidarlite_sample *n_var0);
void callback_magOutputGetRespProducer(const struct sequence_numbered_magnetometer_sample *n_var0);
void callback_px4flowIntOutputGetRespProducer(const struct sequence_numbered_px4flow_integral_sample *n_var0);
void callback_px4flowOutputGetRespProducer(const struct sequence_numbered_px4flow_sample *n_var0);
void callback_gpsOutputGetRespProducer(const struct sequence_numbered_position_sample *n_var0);
void callback_controlSetpointGetRespProducer(const struct sequence_numbered_control_setpoint *n_var0);
void callback_controlOutputGetRespProducer(const struct sequence_numbered_control_output *n_var0);
void callback_motorOutputGetRespProducer(const struct sequence_numbered_quadcopter_motors *n_var0);
void callback_attControlDebugGetRespProducer(const struct sequence_numbered_att_control_debug *n_var0);
void callback_altControlDebugGetRespProducer(const struct sequence_numbered_alt_control_debug *n_var0);
void callback_px4ioStateGetRespProducer(const struct sequence_numbered_px4io_state *n_var0);
void callback_armingStatusGetRespProducer(const struct sequence_numbered_arming_status *n_var0);
void callback_batteryVoltageGetRespProducer(const struct sequence_numbered_float *n_var0);

#ifdef __cplusplus
}
#endif
#endif /* __CONTROLLABLEVEHICLEPRODUCERINPUT_MONITOR_H__ */
