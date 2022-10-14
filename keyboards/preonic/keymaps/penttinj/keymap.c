// Yo whaddap

#include QMK_KEYBOARD_H



enum preonic_layers {
  _QWERTY,	// 0
  _NORDIC,	// 1
  _LOWER,	// 2
  _RAISE,	// 3
  _ADJUST	// 4
};

enum preonic_keycodes {
  QWERTY,
  NORDIC,
  LOWER,
  RAISE,
  BACKLIT
};

enum custom_keycodes {
	L_PAREN = SAFE_RANGE,
	R_PAREN,
	L_BRACKET,
	R_BRACKET,
	L_CURLY,
	R_CURLY
};

//const key_override_t eight_bracket_key_override = ko_make_basic(MOD_MASK_CTRL, KC_8, RALT(KC_8)); 
//const key_override_t nine_bracket_key_override = ko_make_basic(MOD_MASK_CTRL, KC_9, RALT(KC_9));
const key_override_t eight_bracket_key_override = ko_make_with_layers_negmods_and_options(MOD_MASK_CTRL, KC_8, RALT(KC_8), ~0, MOD_MASK_SHIFT, ko_option_no_reregister_trigger);
const key_override_t nine_bracket_key_override = ko_make_with_layers_negmods_and_options(MOD_MASK_CTRL, KC_9, RALT(KC_9), ~0, MOD_MASK_SHIFT, ko_option_no_reregister_trigger);
const key_override_t eight_curly_override = ko_make_basic(MOD_MASK_CS, KC_8, RALT(KC_7));
const key_override_t nine_curly_override = ko_make_basic(MOD_MASK_CS, KC_9, RALT(KC_0));
const key_override_t** key_overrides = (const key_override_t*[]){
    &eight_bracket_key_override,
	&nine_bracket_key_override,
	&eight_curly_override,
	&nine_curly_override,
    NULL
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty "Programming"
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  ¨   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  <>  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |AltGr |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |Super | Alt  |Lower |    Space    |     Enter   |Raise | AltGr|   ?  |  ´   |
 * `-----------------------------------------------------------------------------------'
 */
	[_QWERTY] = LAYOUT_preonic_2x2u(
	KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RBRC,
	KC_NUBS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_LGUI, KC_NUHS,
	KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
	KC_LCTL, KC_LALT, KC_LGUI, MO(_LOWER),      KC_SPC    ,       KC_ENT    ,    MO(_RAISE),   KC_RALT, KC_MINS, KC_EQL
	),

/* Qwerty "Nordic"
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  Å   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ö  |  Ä   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
	[_NORDIC] = LAYOUT_preonic_2x2u(
	KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
	KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,
	KC_NUBS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
	KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
	KC_LCTL, KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE), KC_RALT, KC_MINS, KC_EQL
	),
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
	[_LOWER] = LAYOUT_preonic_2x2u(
	KC_GRV, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PSCR, KC_DEL,
	KC_NO, KC_NO, KC_NO, KC_END, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LBRC,
	KC_NO, KC_HOME, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_SCLN, KC_QUOT,
	KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_ADJUST), KC_TRNS, KC_NO, KC_NO
	),
/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   {  |   }  |   O  | Play | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   (  |   )  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   [  |   ]  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
	[_RAISE] = LAYOUT_preonic_2x2u(
	KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
	KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_NO, KC_NO, L_CURLY, R_CURLY, KC_NO, KC_MPLY, KC_F12,
	KC_CAPS, KC_F5, KC_F6, KC_F7, KC_F8, KC_NO, KC_NO, L_PAREN, R_PAREN, KC_NO, KC_NO, KC_NO,
	KC_TRNS, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_AUDIO_MUTE, L_BRACKET, R_BRACKET, KC_PGDN, KC_PGUP, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, MO(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_RCTL
	),
/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
	[_ADJUST] = LAYOUT_preonic_2x2u(
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, RESET, DEBUG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, AU_ON, AU_OFF, KC_NO, KC_NO, KC_NO, KC_NO, DF(_QWERTY), DF(_NORDIC), KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO, BL_OFF, BL_STEP, BL_BRTG, RGB_MOD, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO
		)
};

#ifdef AUDIO_ENABLE
    float startup_sound[][2] = SONG(PREONIC_SOUND);
	float qwerty_sound[][2] = SONG(NUM_LOCK_OFF_SOUND);
	float nordic_sound[][2] = SONG(NUM_LOCK_ON_SOUND);
#endif

/* Use this function to do stuff based on what key was pressed */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  	switch (keycode) {
		case L_CURLY:
			if (record->event.pressed){
				SEND_STRING(SS_RALT("7"));
			}
			break;
		case R_CURLY:
			if (record->event.pressed){
				SEND_STRING(SS_RALT("0"));
			}
			break;
		case L_PAREN:
			if (record->event.pressed){
				SEND_STRING(SS_LSFT("8"));
			}
			break;
		case R_PAREN:
			if (record->event.pressed){
				SEND_STRING(SS_LSFT("9"));
			}
			break;
		case L_BRACKET:
			if (record->event.pressed){
				SEND_STRING(SS_RALT("8"));
			}
			break;
		case R_BRACKET:
			if (record->event.pressed){
				SEND_STRING(SS_RALT("9"));
			}
			break;
		/*
		case KC_8:
			if (record->event.pressed) {
				const uint8_t mods = get_mods();
				if (mods && MOD_MASK_SHIFT) {
					del_mods(MOD_MASK_SHIFT);
					SEND_STRING(SS_LSFT("1"));
					set_mods(mods);
				}
			}
			break;
		*/
    	case DF(_QWERTY):
			if(record->event.pressed) {
        		#ifdef AUDIO_ENABLE
        			PLAY_SONG(qwerty_sound);
        		#endif
		  	}
			break;
		case DF(_NORDIC):
			if(record->event.pressed) {
        		#ifdef AUDIO_ENABLE
        			PLAY_SONG(nordic_sound);
        		#endif
			}
			break;
    }
    return true;
};


// Function gets called on powerup atleast
void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
        #ifdef AUDIO_ENABLE
          PLAY_SONG(startup_sound);
        #endif
      break;
   }
}
