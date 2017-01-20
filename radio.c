#include <avr/io.h>
#include <avr/interrupt.h>

#include "include/config.h"
#include "include/radio.h"
#include "include/lcd.h"
#include "include/matrix.h"
#include "include/game.h"

/* 4 Channel 
 * 433 MHz Receiver
 */

void
radio_init()
{
  GICR |= (1 << INT0);
  MCUCR |= (1 << ISC01) | (1 << ISC00);
  RADIO_DDR &= ~(1 << RADIO_CH1) & ~(1 << RADIO_CH2);
  RADIO_DDR &= ~(1 << RADIO_CH3) & ~(1 << RADIO_CH4);
}

ISR(INT0_vect)                            
{
  if (*MODE == TESTMODE) {
    /* A */
    if (IS_SET(RADIOPIN, RADIO_CH3)) {
      lcd_init();
      lcd_string("PLAYER 1: RED");
      lcd_setcursor(0, 2);
      lcd_string("PLAYER 2: GREEN");

      *MODE = GAMEPLAY;
    }
  }

  if (*MODE == GAMEPLAY) {
    /* A */ if (IS_SET(RADIOPIN, RADIO_CH3)) {
    }
    /* C */ if (IS_SET(RADIOPIN, RADIO_CH4)) {
    }

    /* B */ if (IS_SET(RADIOPIN, RADIO_CH1)) {
      lcd_clear();
      lcd_string("PLAYER ");
      lcd_data('0' + *PLAYER);
      lcd_setcursor(0, 2);
      lcd_string("it's your turn");

      game_set();
    }

    /* D */ if (IS_SET(RADIOPIN, RADIO_CH2)) {
      game_fix();
    }
  }

  if (*MODE == WIN) {
    /* A */ if (IS_SET(RADIOPIN, RADIO_CH3)) {
      game_init();
      *MODE = TESTMODE;
    }
  }

  if (*MODE == STANDOFF) {
    /* A */ if (IS_SET(RADIOPIN, RADIO_CH3)) {
      game_init();
      *MODE = TESTMODE;
    }
  }
}
