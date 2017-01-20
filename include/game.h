#ifndef GAME_H
#define GAME_H

extern uint8_t FIELD[36];
extern uint8_t PLAYER[1];

void game_init(void);
void game_set(void);
void game_fix(void);

#endif /* GAME_H */
