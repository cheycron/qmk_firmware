#include QMK_KEYBOARD_H
#include "keychron_common.h"
#include "quantum.h"
#include "rgb_matrix.h"

// === === === === === === === === === === === === === ===
//  DECLARACIONES GLOBALES
// === === === === === === === === === === === === === ===
extern layer_state_t layer_state;

// === === === === === === === === === === === === === ===
//  DEFINICION DE COMBOS
// === === === === === === === === === === === === === ===
enum combos { ZX_CUT, XC_COPY, CV_PASTE, SD_SAVE, SLASHDOT_COMMENT };
const uint16_t PROGMEM zx_combo[]       = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM xc_combo[]       = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[]       = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM sd_combo[]       = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM slashdot_combo[] = {KC_DOT, KC_SLASH, SD_SAVE, COMBO_END};
// clang-format off
combo_t key_combos[] = {
    [ZX_CUT]           = COMBO(zx_combo, C(KC_X)),
    [XC_COPY]          = COMBO(xc_combo, C(KC_C)),
    [CV_PASTE]         = COMBO(cv_combo, C(KC_V)),
    [SD_SAVE]          = COMBO(sd_combo, C(KC_S)),
    [SLASHDOT_COMMENT] = COMBO(slashdot_combo, C(KC_SLASH)),
};
// clang-format on
// === === === === === === === === === === === === === ===
//  DEFINICION DE LAYERS
// === === === === === === === === === === === === === ===
enum layers { BASE, BASE_FN, GAMING, NUM_PAD };
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_tkl_ansi(
        KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,         KC_MUTE,    KC_NO,          TG(GAMING), TG(NUM_PAD),
        KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,         KC_BSPC,    KC_INS,         KC_HOME,    KC_PGUP,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,        KC_BSLS,    KC_DEL,         KC_END,     KC_PGDN,
        KC_CAPS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,                    KC_ENT,
        KC_LSFT,                KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,                    KC_RSFT,                    KC_UP,
        KC_LCTL,    KC_LCMD,    KC_LALT,                                        KC_SPC,                                         KC_RALT,    KC_RWIN,    MO(BASE_FN),    KC_RCTL,    KC_LEFT,        KC_DOWN,    KC_RGHT),
    [BASE_FN] = LAYOUT_tkl_ansi(
        KC_NO,      KC_BRID,    KC_BRIU,    KC_TASK,    KC_FILE,    KC_NO,      KC_NO,      KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_MUTE,    KC_VOLD,    KC_VOLU,        KC_NO,      KC_NO,          KC_NO,      KC_NO,
        P2P4G,      BT_HST1,    BT_HST2,    BT_HST3,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO,      KC_NO,          KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO,      KC_NO,          KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                      KC_NO,
        KC_NO,                  KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                      KC_NO,                      QK_BOOT,
        KC_NO,      KC_NO,      KC_NO,                                          KC_NO,                                          KC_NO,      KC_NO,      KC_NO,          KC_NO,      KC_NO,          KC_NO,      KC_NO),
    [GAMING] = LAYOUT_tkl_ansi(
        KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,         KC_MUTE,    KC_NO,          TG(GAMING), TG(GAMING),
        KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,         KC_BSPC,    KC_INS,         KC_HOME,    KC_PGUP,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,        KC_BSLS,    KC_DEL,         KC_END,     KC_PGDN,
        KC_CAPS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,                    KC_ENT,
        KC_LSFT,                KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,                    KC_RSFT,                    KC_UP,
        KC_LCTL,    KC_NO,      KC_LALT,                                        KC_SPC,                                         KC_RALT,    KC_NO,      MO(BASE_FN),    KC_RCTL,    KC_LEFT,        KC_DOWN,    KC_RGHT),
    [NUM_PAD] = LAYOUT_tkl_ansi(
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO,      KC_NO,          TG(NUM_PAD),TG(NUM_PAD),
        KC_NO,      KC_NO,      KC_PSLS,    KC_PAST,    KC_EQL,     KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_BSPC,    KC_NO,          KC_NO,      KC_NO,
        KC_NO,      KC_P7,      KC_P8,      KC_P9,      KC_PMNS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO,      KC_DEL,         KC_NO,      KC_NO,
        KC_NO,      KC_P4,      KC_P5,      KC_P6,      KC_PPLS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                      KC_ENT,
        KC_NO,                  KC_P1,      KC_P2,      KC_P3,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_COMM,    KC_DOT,     KC_SLSH,                    KC_MS_BTN2,                 KC_MS_UP,
        KC_NO,      KC_NO,      KC_P0,                                          KC_PDOT,                                        KC_ACL0,    KC_ACL1,    KC_ACL2,        KC_MS_BTN1, KC_MS_LEFT,     KC_MS_DOWN, KC_MS_RIGHT),
};
// clang-format on

// === === === === === === === === === === === === === ===
//  CONFIGURACIÓN ENCODER
// === === === === === === === === === === === === === ===

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE]    = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [BASE_FN] = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [GAMING]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [NUM_PAD] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};

// === === === === === === === === === === === === === ===
//  LAYER CHANGE HANDLER
// === === === === === === === === === === === === === ===
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case BASE:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_DUAL_BEACON);
            combo_enable();
            break;
        case BASE_FN:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SPLASH);
            combo_disable();
            break;
        case GAMING:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
            combo_disable();
            break;
        case NUM_PAD:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SPLASH);
            combo_disable();
            break;
        default:
            combo_disable();
            break;
    }
    return state;
}

bool led_update_user(led_t led_state) {
    if (!led_state.num_lock) {
        tap_code(KC_NUM_LOCK);
    }
    return true;
}

// === === === === === === === === === === === === === ===
//  KEY PRESS HANDLER
// === === === === === === === === === === === === === ===
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }

    if (get_highest_layer(layer_state) == GAMING) {
        static bool aHeld = false;
        static bool dHeld = false;

        switch (keycode) {
            case KC_A:
                aHeld = record->event.pressed;
                if (dHeld && aHeld) {
                    unregister_code(KC_D);
                } else if (dHeld && !aHeld) {
                    unregister_code(KC_A);
                    register_code(KC_D);
                    return false;
                }
                return true;

            case KC_D:
                dHeld = record->event.pressed;
                if (aHeld && dHeld) {
                    unregister_code(KC_A);
                } else if (aHeld && !dHeld) {
                    unregister_code(KC_D);
                    register_code(KC_A);
                    return false;
                }
                return true;

            default:
                return true;
        }
    }

    return true;
}

// === === === === === === === === === === === === === ===
//  PER LAYER LED COLORS
// === === === === === === === === === === === === === ===
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch (get_highest_layer(layer_state)) {
        case BASE:
            break;
        case BASE_FN:
            // File
            rgb_matrix_set_color(1, RGB_GREEN);
            rgb_matrix_set_color(2, RGB_GREEN);
            rgb_matrix_set_color(3, RGB_GREEN);
            rgb_matrix_set_color(4, RGB_GREEN);
            // Media Control
            rgb_matrix_set_color(7, RGB_GOLDENROD);
            rgb_matrix_set_color(8, RGB_GOLDENROD);
            rgb_matrix_set_color(9, RGB_GOLDENROD);
            rgb_matrix_set_color(10, RGB_GOLDENROD);
            // Volume + / -
            rgb_matrix_set_color(11, RGB_GOLD);
            rgb_matrix_set_color(12, RGB_GOLD);
            // Wireless Setup
            rgb_matrix_set_color(16, RGB_BLUE);
            rgb_matrix_set_color(17, RGB_BLUE);
            rgb_matrix_set_color(18, RGB_BLUE);
            rgb_matrix_set_color(19, RGB_BLUE);
            break;
        case GAMING:
            rgb_matrix_set_color(13, RGB_MAGENTA);
            rgb_matrix_set_color(14, RGB_MAGENTA);
            rgb_matrix_set_color(15, RGB_MAGENTA);
            break;
        case NUM_PAD:
            rgb_matrix_set_color(13, RGB_GREEN);
            rgb_matrix_set_color(14, RGB_GREEN);
            rgb_matrix_set_color(15, RGB_GREEN);
            // MOUSE PAD
            rgb_matrix_set_color(75, RGB_WHITE);
            rgb_matrix_set_color(84, RGB_WHITE);
            rgb_matrix_set_color(85, RGB_WHITE);
            rgb_matrix_set_color(86, RGB_WHITE);
            rgb_matrix_set_color(74, RGB_YELLOW);
            rgb_matrix_set_color(83, RGB_YELLOW);
            // NUMPAD
            rgb_matrix_set_color(18, RGB_BLUE);
            rgb_matrix_set_color(19, RGB_BLUE);
            rgb_matrix_set_color(20, RGB_BLUE);
            rgb_matrix_set_color(34, RGB_CYAN);
            rgb_matrix_set_color(35, RGB_CYAN);
            rgb_matrix_set_color(36, RGB_CYAN);
            rgb_matrix_set_color(37, RGB_BLUE);
            rgb_matrix_set_color(51, RGB_CYAN);
            rgb_matrix_set_color(52, RGB_CYAN);
            rgb_matrix_set_color(53, RGB_CYAN);
            rgb_matrix_set_color(54, RGB_BLUE);
            rgb_matrix_set_color(64, RGB_CYAN);
            rgb_matrix_set_color(65, RGB_CYAN);
            rgb_matrix_set_color(66, RGB_CYAN);
            rgb_matrix_set_color(78, RGB_CYAN);
            rgb_matrix_set_color(79, RGB_BLUE);
            rgb_matrix_set_color(29, RGB_BLUE);
            rgb_matrix_set_color(62, RGB_BLUE);
            rgb_matrix_set_color(47, RGB_BLUE);
            break;
        default:
            break;
    }
    return true;
}
