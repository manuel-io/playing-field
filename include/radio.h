#ifndef RADIO_H
#define RADIO_H

#define RADIOPIN PINC
#define RADIOPORT PORTC
#define RADIO_DDR DDRC

#define RADIO_CH1 PC1
#define RADIO_CH2 PC2
#define RADIO_CH3 PC3
#define RADIO_CH4 PC4

void radio_init(void);

#endif /* RADIO_H */
