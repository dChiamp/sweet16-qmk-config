#include QMK_KEYBOARD_H

#define _MEDIA 0
#define _CMNDS 1
#define _NMPD  2



enum custom_keycodes {
  UP_URL = SAFE_RANGE,
  CMDCLEAR,
  SCRNSHOT,
  RUNDEV,
  COMMIT,
  PUSH,
  LOG,
  STATUS,
  FU,
  COMMENT,
  CUT,
  UNDO,
  SLCTALL,
  COPY,
  PASTE,
  DEL

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MEDIA] = LAYOUT_ortho_4x4(
       KC_MUTE,   KC_VOLD,    KC_VOLU,   KC_MPLY,
       KC_ESC,    SCRNSHOT,   KC_MRWD,   KC_MFFD,
       COPY,      PASTE,      DEL,       TO(2),
       KC_ENT,    KC_BSPC,    COMMENT,   MO(1)
    ),

    [_CMNDS] = LAYOUT_ortho_4x4(
       SLCTALL,   COPY,     PASTE,     UNDO,
       CUT,       CMDCLEAR, KC_ESC,    SCRNSHOT,
       RUNDEV,    COMMIT,   PUSH,      KC_NO,
       STATUS,    LOG,      FU,        KC_NO
    ),

    [_NMPD] = LAYOUT_ortho_4x4(
        KC_7,   KC_8,   KC_9,    KC_ASTR,
        KC_4,   KC_5,   KC_6,    KC_EQL,
        KC_1,   KC_2,   KC_3,    KC_MINS,
        KC_ENT, KC_0,   KC_SLSH, TO(0)
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
          case SCRNSHOT:
              if (record->event.pressed) {
                  register_code(KC_LSHIFT);
                  register_code(KC_LGUI);
                  tap_code(KC_4);
                  unregister_code(KC_LSHIFT);
                  unregister_code(KC_LGUI);
              }
              return false;
              break;

          case RUNDEV:
              if(record->event.pressed){
                  SEND_STRING("npm run dev");
              }
              return false;
              break;
          case COMMIT:
              if(record->event.pressed){
                  SEND_STRING("git commit -am \"");
              }
              return false;
              break;
          case PUSH:
              if(record->event.pressed){
                  SEND_STRING("git push origin ");
              }
              return false;
              break;
          case LOG:
              if(record->event.pressed){
                  SEND_STRING("git log");
              }
              return false;
              break;
          case STATUS:
              if(record->event.pressed){
                  SEND_STRING("git status");
              }
              return false;
              break;
          case COMMENT:
              if(record->event.pressed){
                  register_code(KC_LGUI);
                  tap_code(KC_SLSH);
                  unregister_code(KC_LGUI);
              }
              return false;
              break;
          case FU:       // t(-_-t)
              if(record->event.pressed){
                  SEND_STRING("t(-_-t)");
              }
              return false;
              break;
          case CMDCLEAR:
              if (record->event.pressed) {
                  register_code(KC_LGUI);
                  tap_code(KC_A);
                  unregister_code(KC_LGUI);
                  tap_code(KC_DEL);
              }
              return false;
              break;
          case CUT:
              if (record->event.pressed) {
                  register_code(KC_LGUI);
                  tap_code(KC_X);
                  unregister_code(KC_LGUI);
              }
              return false;
              break;
          case UNDO:
              if (record->event.pressed) {
                  register_code(KC_LGUI);
                  tap_code(KC_Z);
                  unregister_code(KC_LGUI);
              }
              return false;
              break;
          case SLCTALL:
              if (record->event.pressed) {
                  register_code(KC_LGUI);
                  tap_code(KC_A);
                  unregister_code(KC_LGUI);
              }
              return false;
              break;
          case COPY:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_C);
                unregister_code(KC_LGUI);
            }
            return false;
            break;
          case PASTE:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_V);
                unregister_code(KC_LGUI);
            }
            return false;
            break;
          case DEL:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_BSPC);
                unregister_code(KC_LGUI);
            }
            return false;
            break;
      }

    }
    return true;
}

#ifdef ENCODER_ENABLE
#include "encoder.h"
void encoder_update_user(int8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  }
}
#endif
