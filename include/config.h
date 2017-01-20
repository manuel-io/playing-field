#ifndef CONFIG_H
#define CONFIG_H

#define IS_SET(r, b) (r & (1 << b)) >> b == 1
#define IS_UNSET(r, b) (r & (1 << b)) >> b == 0

#define SER PD4
#define SCK PD6
#define RCK PD5
#define CLR PD7

#define LCD_PORT PORTB
#define LCD_DDR  DDRB
#define LCD_R    PB1
#define LCD_E    PB0

#define LCD_LIGHT_PORT PORTC
#define LCD_LIGHT_DDR  DDRC
#define LCD_LIGHT      PC0

#define START 1
#define GAMEPLAY 2
#define TESTMODE 3
#define WIN 4
#define STANDOFF 5

#define true 1
#define false 0
typedef uint8_t bool;

extern uint8_t MODE[1];

#endif /* CONFIG_H */
