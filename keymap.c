#include QMK_KEYBOARD_H

#define _DEFAULT 0
#define _CMNDS 1
// #define _MEDIA 2

enum custom_keycodes {
  UP_URL = SAFE_RANGE,
  CMDCLEAR,
  SCRNSHOT,
  RUNDEV,
  COMMIT,
  FU,
  COMMENT,
  CUT,
  UNDO,
  SLCTALL

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT_ortho_4x4(
        KC_7,   KC_8,   KC_9,   KC_ASTR,
        KC_4,   KC_5,   KC_6,   KC_SLSH,
        KC_1,   KC_2,   KC_3,   KC_MINS,
        KC_ENT, KC_0,   KC_BSPC, TO(1)
    ),

    [_CMNDS] = LAYOUT_ortho_4x4(
       KC_MUTE,   KC_VOLD,  KC_VOLU,   KC_MPLY,
       KC_MRWD,   KC_MFFD,  FU,        SCRNSHOT,
       CMDCLEAR,  RUNDEV,   COMMIT,    COMMENT,
       SLCTALL,   CUT,      UNDO,     TO(0)
    )

    // [_MEDIA] = LAYOUT_ortho_4x4(
    //    KC_MUTE,   KC_VOLD,  KC_VOLU,   KC_MPLY,
    //    KC_MRWD,   KC_MFFD,  COMMENT,   CMDCLEAR,
    //    SCRNSHOT,  RUNDEV,   COMMIT,    FU,
    //    KC_ENT,    KC_CUT,   KC_BSPC,   TO(0)
    // )

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
                  SEND_STRING("git commit -am ");
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
