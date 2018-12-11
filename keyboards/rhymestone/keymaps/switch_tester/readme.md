# The switch tester keymap for Rhymestone

## Description

## How to use

```c

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
      XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
      XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
      XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
       LTAD, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX \
  //|------+------+------+------+-------------+------+------+------+------|
  ),

  [_ADJUST] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
        RST, XXXXX, XXXXX, XXXXX,  RGB0, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
       ROFF,  LHUI,  LSAI,  LVAI,  RGB1, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
      XXXXX,  LHUD,  LSAD,  LVAD,  RGB2, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+-------------+------+------+------+------|
      _____, XXXXX, XXXXX, XXXXX,  RGB3, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX \
  //|------+------+------+------+-------------+------+------+------+------|
  )
};

```
