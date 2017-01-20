#ifndef LCD_H
#define LCD_H

void lcd_init(void);
void lcd_clear(void);
void lcd_home(void);
void lcd_setcursor(uint8_t, uint8_t);
void lcd_data(uint8_t);
void lcd_string(const char *);
void lcd_command(uint8_t);
void lcd_on(void);
void lcd_off(void);

#endif /* LCD_H */
