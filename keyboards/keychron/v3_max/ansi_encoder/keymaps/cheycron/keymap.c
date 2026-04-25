#include QMK_KEYBOARD_H
#include "keychron_common.h"

// === === === === === === === === === === === === === ===
//  GLOBAL
// === === === === === === === === === === === === === ===
extern layer_state_t layer_state;
// clang-format on
// === === === === === === === === === === === === === ===
//  LAYERS
// === === === === === === === === === === === === === ===
enum layers { BASE, BASE_FN, GAMING, NUM_PAD };

enum custom_keycodes { AR_WALK = SAFE_RANGE };

static bool autorun_active = false;

static inline bool gaming_active(void) {
    return layer_state_cmp(layer_state, GAMING);
}

static void stop_autorun(void) {
    if (autorun_active) {
        unregister_code(KC_W);
        autorun_active = false;
    }
}
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
        QK_BOOT,    KC_BRID,    KC_BRIU,    KC_TASK,    KC_FILE,    KC_NO,      KC_NO,      KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_MUTE,    KC_VOLD,    KC_VOLU,        KC_NO,      KC_NO,          KC_NO,      KC_NO,
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
//  ENCODER
// === === === === === === === === === === === === === ===

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE]    = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [BASE_FN] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [GAMING]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [NUM_PAD] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};

// === === === === === === === === === === === === === ===
//  COMBOS
// === === === === === === === === === === === === === ===
enum combos { ZX_UNDO, ZXC_REDO, XC_CUT, CV_COPY, VB_PASTE, SD_SAVE, QWE_AUTORUN, ONE_TWO_THREE_GAMING, SLASHDOT_COMMENT, F3F4_SUPERF4 };

const uint16_t PROGMEM zx_combo[]       = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM zxc_combo[]      = {KC_Z, KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM xc_combo[]       = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[]       = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM vb_combo[]       = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM sd_combo[]       = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM qwe_combo[]      = {KC_Q, KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM one_two_three_combo[] = {KC_1, KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM slashdot_combo[] = {KC_DOT, KC_SLASH, COMBO_END};
const uint16_t PROGMEM f3f4_combo[]     = {KC_F3, KC_F4, COMBO_END};

// clang-format off
combo_t key_combos[] = {
    [ZX_UNDO]           = COMBO(zx_combo,       C(KC_Z)),
    [ZXC_REDO]          = COMBO(zxc_combo,      C(KC_Y)),
    [XC_CUT]            = COMBO(xc_combo,       C(KC_X)),
    [CV_COPY]           = COMBO(cv_combo,       C(KC_C)),
    [VB_PASTE]          = COMBO(vb_combo,       C(KC_V)),
    [SD_SAVE]           = COMBO(sd_combo,       C(KC_S)),
    [QWE_AUTORUN]       = COMBO(qwe_combo,      AR_WALK),
    [ONE_TWO_THREE_GAMING] = COMBO(one_two_three_combo, TG(GAMING)),
    [SLASHDOT_COMMENT]  = COMBO(slashdot_combo, C(KC_SLASH)),
    [F3F4_SUPERF4]      = COMBO(f3f4_combo,     C(A(KC_F4))),
};

// === === === === === === === === === === === === === ===
//  LAYER CHANGE HANDLER
// === === === === === === === === === === === === === ===
layer_state_t layer_state_set_user(layer_state_t state) {
    if (!layer_state_cmp(state, GAMING)) {
        stop_autorun();
    }

    switch (get_highest_layer(state)) {
        case BASE:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_DUAL_BEACON);
            break;
        case BASE_FN:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SPLASH);
            break;
        case GAMING:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
            break;
        case NUM_PAD:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SPLASH);
            break;
        default:
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

    if (keycode == AR_WALK) {
        if (record->event.pressed) {
            if (autorun_active) {
                stop_autorun();
            } else {
                register_code(KC_W);
                autorun_active = true;
            }
        }
        return false;
    }

    if (gaming_active()) {
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

            case KC_W:
            case KC_S:
                if (record->event.pressed) {
                    stop_autorun();
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
    const bool autorun_phase = ((timer_read32() / 180) & 1) != 0;

    if (layer_state_cmp(layer_state, BASE_FN)) {
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
    }

    if (gaming_active()) {
        // WASD movement cluster: W pulses, A/S/D stay as the movement base.
        rgb_matrix_set_color(51, RGB_MAGENTA);
        rgb_matrix_set_color(52, RGB_MAGENTA);
        rgb_matrix_set_color(53, RGB_MAGENTA);

        if (autorun_active) {
            // Slightly brighten the pulse so the forward direction reads as an arrow.
            if (autorun_phase) {
                rgb_matrix_set_color(35, RGB_BLUE);
            } else {
                rgb_matrix_set_color(35, RGB_MAGENTA);
            }
        } else {
            rgb_matrix_set_color(35, RGB_MAGENTA);
        }
    }

    if (layer_state_cmp(layer_state, NUM_PAD)) {
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
    }
    return true;
}

// === === === === === === === === === === === === === ===
//  PER LAYER COMBO ACTIVATION
// === === === === === === === === === === === === === ===
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (gaming_active() ? GAMING : get_highest_layer(layer_state)) {
        case BASE:
            return combo_index != QWE_AUTORUN;
        case GAMING:
            return combo_index == QWE_AUTORUN || combo_index == ONE_TWO_THREE_GAMING;
        default:
            return false;
    }
}
