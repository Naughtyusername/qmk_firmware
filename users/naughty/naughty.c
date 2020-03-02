#include "naughty.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {}

//**************** LEADER *********************//
#ifdef LEADER_ENABLE
LEADER_EXTERNS();
#    ifdef RGBLIGHT_ENABLE
#    endif

void matrix_scan_user(void) {
  // leaderkeys in here
}
#endif  // LEADER

/* __attribute__ ((weak)) */
/* bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { */
/*   return true; */
/* } */

/* __attribute__ ((weak)) */
/* void matrix_init_user(void) { */
/*   } */

/* __attribute__ ((weak)) */
/* void matrix_scan_keymap(void) {} */

/* __attribute__ ((weak)) */
/* void matrix_scan_user(void){ */

/* #ifdef TAP_DANCE_ENABLE  // run */
/* #endif // !TAP_DANCE_ENABLE */

/*   __attribute__ ((weak)) */
/* void matrix_scan_keymap(); { */
/* } */
