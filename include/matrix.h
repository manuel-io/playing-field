#ifndef MATRIX_H
#define MATRIX_H

void matrix_init(void);
void matrix_test(void);
void matrix_draw(void);

typedef struct {
  uint8_t cathode;
  uint8_t anode;
} __attribute__((packed)) light;

/* Anode: 1 - 6
 * Kathode: 19 - 24 */

#define LED01_A 7
#define LED01_C 13
#define LED02_A 7
#define LED02_C 14
#define LED03_A 7
#define LED03_C 15
#define LED04_A 7
#define LED04_C 16
#define LED05_A 7
#define LED05_C 17
#define LED06_A 7
#define LED06_C 18

#define LED07_A 8
#define LED07_C 13
#define LED08_A 8
#define LED08_C 14
#define LED09_A 8
#define LED09_C 15
#define LED10_A 8
#define LED10_C 16
#define LED11_A 8
#define LED11_C 17
#define LED12_A 8
#define LED12_C 18

#define LED13_A 12
#define LED13_C 13
#define LED14_A 12
#define LED14_C 14
#define LED15_A 12
#define LED15_C 15
#define LED16_A 12
#define LED16_C 16
#define LED17_A 12
#define LED17_C 17
#define LED18_A 12
#define LED18_C 18

#define LED19_A 9
#define LED19_C 13
#define LED20_A 9
#define LED20_C 14
#define LED21_A 9
#define LED21_C 15
#define LED22_A 9
#define LED22_C 16
#define LED23_A 9
#define LED23_C 17
#define LED24_A 9
#define LED24_C 18

#define LED25_A 10
#define LED25_C 13
#define LED26_A 10
#define LED26_C 14
#define LED27_A 10
#define LED27_C 15
#define LED28_A 10
#define LED28_C 16
#define LED29_A 10
#define LED29_C 17
#define LED30_A 10
#define LED30_C 18

#define LED31_A 11
#define LED31_C 13
#define LED32_A 11
#define LED32_C 14
#define LED33_A 11
#define LED33_C 15
#define LED34_A 11
#define LED34_C 16
#define LED35_A 11
#define LED35_C 17
#define LED36_A 11
#define LED36_C 18

#define LED37_A 5
#define LED37_C 19
#define LED38_A 3
#define LED38_C 19
#define LED39_A 1
#define LED39_C 19
#define LED40_A 2
#define LED40_C 19
#define LED41_A 4
#define LED41_C 19
#define LED42_A 6
#define LED42_C 19

#define LED43_A 5
#define LED43_C 21
#define LED44_A 3
#define LED44_C 21
#define LED45_A 1
#define LED45_C 21
#define LED46_A 2
#define LED46_C 21
#define LED47_A 4
#define LED47_C 21
#define LED48_A 6
#define LED48_C 21

#define LED49_A 5
#define LED49_C 23
#define LED50_A 3
#define LED50_C 23
#define LED51_A 1
#define LED51_C 23
#define LED52_A 2
#define LED52_C 23
#define LED53_A 4
#define LED53_C 23
#define LED54_A 6
#define LED54_C 23

#define LED55_A 5
#define LED55_C 24
#define LED56_A 3
#define LED56_C 24
#define LED57_A 1
#define LED57_C 24
#define LED58_A 2
#define LED58_C 24
#define LED59_A 4
#define LED59_C 24
#define LED60_A 6
#define LED60_C 24

#define LED61_A 5
#define LED61_C 22
#define LED62_A 3
#define LED62_C 22
#define LED63_A 1
#define LED63_C 22
#define LED64_A 2
#define LED64_C 22
#define LED65_A 4
#define LED65_C 22
#define LED66_A 6
#define LED66_C 22

#define LED67_A 5
#define LED67_C 20
#define LED68_A 3
#define LED68_C 20
#define LED69_A 1
#define LED69_C 20
#define LED70_A 2
#define LED70_C 20
#define LED71_A 4
#define LED71_C 20
#define LED72_A 6
#define LED72_C 20

#endif /* MATRIX_H */
