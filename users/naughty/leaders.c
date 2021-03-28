#include "leaders.h"

// Leader key stuff
/* LEADER_EXTERNS(); */
/* void matrix_scan_user(void) { */
/*     // use mnemonics, Leader f ... for file management, etc. */
/*     // todo: leader keys to do my display fusion window managment */
/*     // todo: ... */
/*     LEADER_DICTIONARY() { */
/*         leading = false; */
/*         /\* */
/*           Display fusion keybinds */
/*           leader key W binds */

/*           shift win , - move window bottom left 25% */
/*           shift win . - move window bottom right 25% */
/*           shift win k - Move window top left 25% */
/*           shift win l - Move window top right 25% */

/*           shift win j - move window bottom 50% */
/*           shift win k - move window top 50% */

/*           shift win n - move window left monitor, scale appropreiately */
/*           shift win b - move window right monitor, scale appropreiately */

/*           shift win h  - move window left, split 50% */
/*           shift win l - move window right, split 50% */
/*           shift win g     - maximixe window */
/*          *\/ */

/*         SEQ_TWO_KEYS(KC_W, KC_DOT) {  // move window bottom right 25% */
/*             SEND_STRING(SS_LCTL(SS_LGUI("."))); */
/*         } */

/*         SEQ_TWO_KEYS(KC_W, KC_COMM) {  // move window bottom left 25% */
/*             SEND_STRING(SS_LCTL(SS_LGUI(","))); */
/*         } */

/*         SEQ_TWO_KEYS(KC_W, KC_K) {  // move window top left 25% */
/*             SEND_STRING(SS_LCTL(SS_LGUI("k"))); */
/*         } */

/*         SEQ_TWO_KEYS(KC_W, KC_L) {  // move window top right 25% */
/*             SEND_STRING(SS_LCTL(SS_LGUI("l"))); */
/*         } */

/*         SEQ_TWO_KEYS(KC_W, KC_G) {  // move window bottom 50% */
/*             SEND_STRING(SS_LCTL(SS_LGUI("j"))); */
/*         } */

/*         SEQ_TWO_KEYS(KC_W, KC_T) {  // move window top 50% */
/*             SEND_STRING(SS_LCTL(SS_LGUI("k"))); */
/*         } */

/*         SEQ_TWO_KEYS(KC_W, KC_I) {  // move window left, scale appropreiately */
/*             SEND_STRING(SS_LSFT(SS_LALT("h"))); */
/*         } */

/*         SEQ_TWO_KEYS(KC_W, KC_O) {  // move window right, scale appropreiately */
/*             SEND_STRING(SS_LSFT(SS_LALT("l"))); */
/*         } */
/*         // Bspwm - linux window manager commands (consider actually just making these the same as display fusion, or the opposit.) */

/*         // synergy commands */
/*         // .. Lead, a(pplications), s(ynergy), s(wap) - swap cursor/focus to other computer. */
/*         // swap left alt ctrl shift t */
/*         // swap left alt ctrl shift g */
/*         SEQ_THREE_KEYS(KC_A, KC_S, KC_Q) {  // Swap To Laptop */
/*             SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT("t")))); */
/*         } */

/*         SEQ_THREE_KEYS(KC_A, KC_S, KC_W) {  // Swap To Desktop */
/*             SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT("g")))); */
/*         } */

/*         // File system */
/*         SEQ_THREE_KEYS(KC_F, KC_A, KC_R) {  // summon 'Everything' */
/*             SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT("r")))); */
/*         } */
/*         // general commands */
/*         // lead o w to send email string */
/*         SEQ_TWO_KEYS(KC_O, KC_W) {  // summon 'Everything' */
/*             SEND_STRING("whatsahardscope@gmail.com"); */

/*             matrix_scan_keymap(); */
/*             leader_end(); */
/*         } */
/*     } */

/*     void leader_start(void) {} */

/*     void leader_end(void) {} */
