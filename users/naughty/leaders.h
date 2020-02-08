
// temp

/* // Leader key stuff */
/* LEADER_EXTERNS(); */
/* void matrix_scan_user(void) { */
/*     // use mnemonics, Leader f ... for file management, etc. */
/*     // todo: leader keys to do my display fusion window managment */
/*     // todo: ... */
/*     LEADER_DICTIONARY() { */
/*         leading = false; */
/*         leader_end(); */

/*         /\* */
/*           Display fusion keybinds */
/*           leader key W binds */

/*           ctrl win , - move window bottom left 25% */
/*           ctrl win . - move window bottom right 25% */
/*           ctrl win k - Move window top left 25% */
/*           ctrl win l - Move window top right 25% */
/*           ctrl win g - move window bottom 50% */
/*           ctrl win t - move window top 50% */

/*           shift alt T - move window left monitor, scale appropreiately */
/*           shift alt R - move window right monitor, scale appropreiately */

/*           shift alt ctrl left  - move window left, split 50% */
/*           shift alt ctrl right - move window right, split 50% */
/*           shift ctrl win g     - maximixe window */
/*          *\/ */

/*         SEQ_TWO_KEYS(KC_W, KC_DOT) { // move window bottom right 25% */
/*              SEND_STRING(SS_LCTL(SS_LGUI("."))); */
/*         } */

/*         SEQ_TWO_KEYS(KC_W, KC_COMM) { // move window bottom left 25% */
/*             SEND_STRING(SS_LCTL(SS_LGUI(","))); */
/*         } */

/*         SEQ_TWO_KEYS(KC_W, KC_K) { // move window top left 25% */
/*             SEND_STRING(SS_LCTL(SS_LGUI("k"))); */
/*         } */

/*         SEQ_TWO_KEYS(KC_W, KC_L) { // move window top right 25% */
/*             SEND_STRING(SS_LCTL(SS_LGUI("l"))); */
/*         } */

/*         SEQ_TWO_KEYS(KC_W, KC_G) { // move window bottom 50% */
/*             SEND_STRING(SS_LCTL(SS_LGUI("g"))); */
/*         } */

/*         SEQ_TWO_KEYS(KC_W, KC_T) { //move window top 50% */
/*             SEND_STRING(SS_LCTL(SS_LGUI("t"))); */
/*         } */

/*         SEQ_TWO_KEYS(KC_W, KC_I) { // move window left, scale appropreiately */
/*             SEND_STRING(SS_LSFT(SS_LALT("i"))); */
/*         } */

/*         SEQ_TWO_KEYS(KC_W, KC_O) { // move window right, scale appropreiately */
/*             SEND_STRING(SS_LSFT(SS_LALT("o"))); */
/*         } */
/*         // i3 - linux window manager commands (consider actually just making these the same as display fusion, or the opposit.) */

/*         // synergy commands */
/*         // .. Lead, a(pplications), s(ynergy), s(wap) - swap cursor/focus to other computer. */
/*         SEQ_THREE_KEYS(KC_A, KC_S, KC_Q) { // Swap To Laptop */
/*             SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT("t")))); */
/*         } */

/*         SEQ_THREE_KEYS(KC_A, KC_S, KC_W) { // Swap To Desktop */
/*             SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT("g")))); */
/*         } */

/*         // File system */
/*         SEQ_THREE_KEYS(KC_F, KC_A, KC_R) { // summon 'Everything' */
/*             SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT("r")))); */
/*         } */



/*     } */
/* } */
