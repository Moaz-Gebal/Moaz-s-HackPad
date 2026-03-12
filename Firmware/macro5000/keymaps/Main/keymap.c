// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _MACRO,

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */
    [_BASE] = LAYOUT_macropad5000(
        KC_1, KC_2, KC_3,
        KC_4, KC_5, KC_6,
        KC_7, KC_8, KC_9,
            TT(_MACRO)
    ),
        [_MACRO] = LAYOUT_macropad5000(
        KC_PRINT_SCREEN, KC_UP, KC_MEDIA_PLAY_PAUSE,
        KC_LEFT, KC_DOWN, KC_RIGHT,
        QK_BOOTLOADER, QK_PROGRAMMABLE_BUTTON_1, QK_PROGRAMMABLE_BUTTON_2,
            TT(_BASE)
    )

};


#ifdef OLED_ENABLE

bool oled_task_user(void) {

    oled_write_ln("Macro5000", false);

    oled_write("Layer: ", false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln("Base", false);
            break;
        case _MACRO:
            oled_write_ln("Macro", false);
            break;
    }

    return false;
}


#endif

bool encoder_update_user(uint8_t index, bool clockwise) {

    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }

    return false;
}
