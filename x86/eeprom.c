#include <stdint.h>
#include <stdio.h> 
#include "../include/matrix.h"

int
main(int argc, char **argv)
{
  light board[] = {
    {LED01_C, LED01_A},
    {LED02_C, LED02_A},
    {LED03_C, LED03_A},
    {LED04_C, LED04_A},
    {LED05_C, LED05_A},
    {LED06_C, LED06_A},
    {LED07_C, LED07_A},
    {LED08_C, LED08_A},
    {LED09_C, LED09_A},
    {LED10_C, LED10_A},
    {LED11_C, LED11_A},
    {LED12_C, LED12_A},
    {LED13_C, LED13_A},
    {LED14_C, LED14_A},
    {LED15_C, LED15_A},
    {LED16_C, LED16_A},
    {LED17_C, LED17_A},
    {LED18_C, LED18_A},
    {LED19_C, LED19_A},
    {LED20_C, LED20_A},
    {LED21_C, LED21_A},
    {LED22_C, LED22_A},
    {LED23_C, LED23_A},
    {LED24_C, LED24_A},
    {LED25_C, LED25_A},
    {LED26_C, LED26_A},
    {LED27_C, LED27_A},
    {LED28_C, LED28_A},
    {LED29_C, LED29_A},
    {LED30_C, LED30_A},
    {LED31_C, LED31_A},
    {LED32_C, LED32_A},
    {LED33_C, LED33_A},
    {LED34_C, LED34_A},
    {LED35_C, LED35_A},
    {LED36_C, LED36_A},
    {LED37_C, LED37_A},
    {LED38_C, LED38_A},
    {LED39_C, LED39_A},
    {LED40_C, LED40_A},
    {LED41_C, LED41_A},
    {LED42_C, LED42_A},
    {LED43_C, LED43_A},
    {LED44_C, LED44_A},
    {LED45_C, LED45_A},
    {LED46_C, LED46_A},
    {LED47_C, LED47_A},
    {LED48_C, LED48_A},
    {LED49_C, LED49_A},
    {LED50_C, LED50_A},
    {LED51_C, LED51_A},
    {LED52_C, LED52_A},
    {LED53_C, LED53_A},
    {LED54_C, LED54_A},
    {LED55_C, LED55_A},
    {LED56_C, LED56_A},
    {LED57_C, LED57_A},
    {LED58_C, LED58_A},
    {LED59_C, LED59_A},
    {LED60_C, LED60_A},
    {LED61_C, LED61_A},
    {LED62_C, LED62_A},
    {LED63_C, LED63_A},
    {LED64_C, LED64_A},
    {LED65_C, LED65_A},
    {LED66_C, LED66_A},
    {LED67_C, LED67_A},
    {LED68_C, LED68_A},
    {LED69_C, LED69_A},
    {LED70_C, LED70_A},
    {LED71_C, LED71_A},
    {LED72_C, LED72_A}
  };

  printf("Matrix size: %lu\n", sizeof(board)/sizeof(light));

  FILE *ptr;
  ptr = fopen("eeprom.bin","wb");
  fwrite(&board, sizeof(light), sizeof(board)/sizeof(light), ptr);
  fclose(ptr);

  return 0;
}
