#include QMK_KEYBOARD_H

#define _DEFAULT 0
#define _CMNDS 1
#define _EMOJI 2

enum custom_keycodes {
  UP_URL = SAFE_RANGE,
  CMDCLEAR,
  SCRNSHOT,
  RUNDEV,
  COMMIT,
  FU,
  SHRUG,
  DISFACE,
  TFLIP,
  TFLIP2,
  SAD_EYES,
  TPUT,
  HAPPYFACE,
  HEARTFACE,
  CLOUD,
  CHANFACE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT_ortho_4x4(
        KC_7, KC_8,   KC_9,   KC_ASTR,
        KC_4, KC_5,   KC_6,   KC_SLSH,
        KC_1, KC_2,   KC_3,   KC_MINS,
        KC_0, KC_ENT, KC_DOT, TO(1)
    ),

    [_CMNDS] = LAYOUT_ortho_4x4(
       SCRNSHOT,  RUNDEV,   COMMIT,      FU,
       CLOUD,     KC_NO,    KC_NO,      CMDCLEAR,
       SHRUG,     DISFACE,  HEARTFACE,  HAPPYFACE,
       KC_ENT,    TFLIP,    TFLIP2,     KC_TRANSPARENT
    ),

    // [_EMOJI] = LAYOUT_ortho_4x4(
    //    TFLIP,   TFLIP2,   KC_NO,      FU,
    //    CLOUD,   KC_NO,    KC_NO,      CMDCLEAR,
    //    SHRUG,   DISFACE,  HEARTFACE,  HAPPYFACE,
    //    KC_ENT,  TFLIP,    TFLIP2,     KC_TRANSPARENT
    // ),
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
          case FU:       // t(-_-t)
              if(record->event.pressed){
                  SEND_STRING("t(-_-t)");
              }
              return false;
              break;

            case CLOUD:       // (っ◕‿◕)っ
                if(record->event.pressed){
                    send_unicode_hex_string("0028 3063 25D5 203F 25D5 0029 3063");
                }
                return false;
                break;
            case HAPPYFACE:       // ʘ‿ʘ
                if(record->event.pressed){
                     send_unicode_hex_string("0298 203F 0298");
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
            case SHRUG: // ¯\_(ツ)_/¯
                if (record->event.pressed) {
                    send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
                }
                return false;
                break;
            case HEARTFACE:       // ♥‿♥
                if(record->event.pressed){
                    send_unicode_hex_string("2665 203F 2665");
                }
                return false;
                break;
            case DISFACE:       // ಠ_ಠ
                if(record->event.pressed){
                    send_unicode_hex_string("0CA0 005F 0CA0");
                }
                return false;
                break;
            case TFLIP:         // (╯°□°)╯ ︵ ┻━┻
                if(record->event.pressed){
                    send_unicode_hex_string("0028 256F 00B0 25A1 00B0 0029 256F 0020 FE35 0020 253B 2501 253B");
                }
                return false;
                break;
            case TFLIP2:         // ┻━┻︵ \(°□°)/ ︵ ┻━┻
                if(record->event.pressed){
                    send_unicode_hex_string("253B 2501 253B FE35 0020 005C 0028 00B0 25A1 00B0 0029 002F 0020 FE35 0020 253B 2501 253B");
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
