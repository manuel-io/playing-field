#include <util/delay.h>

#include "include/config.h"
#include "include/game.h"
#include "include/lcd.h"

uint8_t FIELD[36];
uint8_t PLAYER[1];

static uint8_t position = 0;
static bool game_win(void);
static void game_clear(void);

static void
game_clear()
{
  for (uint8_t i = 0; i < 36; i++) {
    FIELD[i] = 0;
  }
}

void
game_init()
{
  *PLAYER = 1;
  game_clear();
}

void
game_set()
{
  if (position > 5) position = 0;
  FIELD[0] = FIELD[1] = FIELD[2] = FIELD[3] = FIELD[4] = FIELD[5] = 0;
  FIELD[position++] = *PLAYER;
}

void
game_fix()
{
  /*  0  1  2  3  4  5
   *  6  7  8  9 10 11
   * 12 13 14 15 16 17
   * 18 19 20 21 22 23
   * 24 25 26 27 28 29
   * 30 31 32 33 34 35
   */
  position -= 1;

  while ((position + 6) < 36) {
    if (FIELD[position + 6] == 0) position += 6;
    else break; 
  }

  FIELD[0] = FIELD[1] = FIELD[2] = FIELD[3] = FIELD[4] = FIELD[5] = 0;
  FIELD[position] = *PLAYER;
  
  if (game_win()) {
    *MODE = WIN;

    lcd_clear();
    lcd_string("PLAYER ");
    lcd_data('0' + *PLAYER);
    lcd_setcursor(0, 2);
    lcd_string("you win!");

    return;
  }

  if (position < 6) {
    *MODE = STANDOFF;

    if ( FIELD[6]  == 0 ||
         FIELD[7]  == 0 ||
         FIELD[8]  == 0 ||
         FIELD[9]  == 0 ||
         FIELD[10] == 0 ||
         FIELD[11] == 0
       ) {

      lcd_clear();
      lcd_string("PLAYER ");
      lcd_data('0' + *PLAYER);
      lcd_setcursor(0, 2);
      lcd_string("wake up again");

    } else {

      lcd_clear();
      lcd_string("PLAYER ");
      lcd_data('0' + *PLAYER);
      lcd_setcursor(0, 2);
      lcd_string("no winner");

    }

    game_clear();
    return;
  }

  position = 0;
  *PLAYER = 3 ^ *PLAYER;
  
  lcd_clear();
  lcd_string("PLAYER ");
  lcd_data('0' + *PLAYER);
  lcd_setcursor(0, 2);
  lcd_string("it's your turn");
}

static bool
game_win()
{
  uint8_t RESULT[4];

  for (uint8_t offset = 0; offset < 3; offset++) {
    for (uint8_t i = offset; i < 36; i+=6)
      if ( FIELD[RESULT[0] = i] == *PLAYER &&
           FIELD[RESULT[1] = i+1] == *PLAYER &&
           FIELD[RESULT[2] = i+2] == *PLAYER &&
           FIELD[RESULT[3] = i+3] == *PLAYER
          ) {
        game_clear();
        FIELD[RESULT[0]] = FIELD[RESULT[1]] = FIELD[RESULT[2]] = FIELD[RESULT[3]] = *PLAYER;
        return true;
      }

    for (uint8_t i = 0; i < 6; i++)
      if ( FIELD[RESULT[0] = 6*offset+i] == *PLAYER &&
           FIELD[RESULT[1] = 6*offset+i+6] == *PLAYER &&
           FIELD[RESULT[2] = 6*offset+i+12] == *PLAYER &&
           FIELD[RESULT[3] = 6*offset+i+18] == *PLAYER
          ) {
        game_clear();
        FIELD[RESULT[0]] = FIELD[RESULT[1]] = FIELD[RESULT[2]] = FIELD[RESULT[3]] = *PLAYER;
        return true;
      }

    for (uint8_t i = 0; i < 3; i++)
      if ( FIELD[RESULT[0] = 6*offset+i] == *PLAYER &&
           FIELD[RESULT[1] = 6*offset+i+6+1] == *PLAYER &&
           FIELD[RESULT[2] = 6*offset+i+12+2] == *PLAYER &&
           FIELD[RESULT[3] = 6*offset+i+18+3] == *PLAYER
          ) {
        game_clear();
        FIELD[RESULT[0]] = FIELD[RESULT[1]] = FIELD[RESULT[2]] = FIELD[RESULT[3]] = *PLAYER;
        return true;
      }

    for (uint8_t i = 3; i < 6; i++)
      if ( FIELD[RESULT[0] = 6*offset+i] == *PLAYER &&
           FIELD[RESULT[1] = 6*offset+i+6-1] == *PLAYER &&
           FIELD[RESULT[2] = 6*offset+i+12-2] == *PLAYER &&
           FIELD[RESULT[3] = 6*offset+i+18-3] == *PLAYER
          ) {
        game_clear();
        FIELD[RESULT[0]] = FIELD[RESULT[1]] = FIELD[RESULT[2]] = FIELD[RESULT[3]] = *PLAYER;
        return true;
      }
  }

 return false;
}
