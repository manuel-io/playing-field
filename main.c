#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>

#include "include/config.h"
#include "include/lcd.h"
#include "include/matrix.h"
#include "include/radio.h"
#include "include/game.h"

uint8_t MODE[1];

int
main(void)
{
  *MODE = TESTMODE;

  sei();
  radio_init();
  matrix_init();
  game_init();

  matrix_draw();
}
