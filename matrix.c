#include <avr/eeprom.h>
#include <util/delay.h>

#include "include/config.h"
#include "include/matrix.h"
#include "include/game.h"

static light matrix[72];
static void reset(void);

static void
toggle(uint8_t pin)
{
  PORTD |= (1 << pin);
  PORTD &= ~(1 << pin);
}

static void
ntoggle(uint8_t n, uint8_t pin)
{
  for (uint8_t i = 0; i < n; i++) {
    toggle(pin);
  }
}

static void
on(uint8_t cathode, uint8_t anode)
{
  reset();

  PORTD |= (1 << SER);
  toggle(SCK);
  PORTD &= ~(1 << SER);
  ntoggle(cathode-anode-1, SCK);

  PORTD |= (1 << SER);
  toggle(SCK);
  PORTD &= ~(1 << SER);
  ntoggle(anode-1, SCK);

  toggle(RCK);
}

void
matrix_init()
{
  for (uint8_t i = 0; i < 72; i++) {
    matrix[i].cathode = (uint8_t)eeprom_read_byte((uint8_t *)(i*2));
    matrix[i].anode = (uint8_t)eeprom_read_byte((uint8_t *)(i*2+1));
  }

  DDRD |= (1 << SER) | (1 << SCK) | (1 << RCK) | (1 << CLR);
  reset();
}

void
matrix_field()
{
  for (uint8_t i = 0; i < 36; i++) {
    switch(FIELD[i]) {
      case 1:
        on(matrix[i].cathode, matrix[i].anode);
        _delay_us(100);
      break;
      
      case 2:
        on(matrix[i+36].cathode, matrix[i+36].anode);
        _delay_us(100);
      break;
    }
  }
}

void
matrix_draw()
{
  for(;;) {
    while (*MODE == GAMEPLAY) matrix_field();
    while (*MODE == TESTMODE) matrix_test();
    while (*MODE == STANDOFF) matrix_field();
    while (*MODE == WIN) matrix_field();
  }
}


void
matrix_test()
{

    if (*MODE == TESTMODE) {
      for (uint8_t count = 0; count < 50; count++) {
        for (uint8_t a = 1; a <= 6; a++) {
          for (uint8_t c = 19; c <= 24; c++) {
            on(c, a);
            _delay_us(400);
          }
        }
      }
    }

    if (*MODE == TESTMODE) {
      for (uint8_t count = 0; count < 36; count++) {
        on(matrix[count].cathode, matrix[count].anode);
        _delay_ms(100);
      }
    }

    if (*MODE == TESTMODE) {
      for (uint8_t count = 0; count < 50; count++) {
        for (uint8_t a = 7; a <= 12; a++) {
          for (uint8_t c = 13; c <= 18; c++) {
            on(c, a);
            _delay_us(400);
          }
        }
      }
    }

    if (*MODE == TESTMODE) {
      for (uint8_t count = 0; count < 36; count++) {
        on(matrix[count+36].cathode, matrix[count+36].anode);
        _delay_ms(100);
      }
    }

}

static void
reset()
{
  PORTD &= ~(1 << CLR);
  PORTD |= (1 << CLR);
}
