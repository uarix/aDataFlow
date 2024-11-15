
#include "gamma.h"

// the gamma table was found here:
// https://github.com/espressif/esp-iot-solution/blob/76e4ad43950c8f3e26d296917ed166b8b14f4906/components/led/led_indicator/src/led_gamma.c
// gramma = 2.8 used for this lcd backlight: 50% pwm = 80% lum

/* step brightness table: gamma = 2.3 */
uint8_t gamma_table[MAX_PROGRESS] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 2,
    2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5,
    5, 5, 6, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10,
    10, 10, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16, 17,
    17, 18, 18, 19, 19, 20, 20, 21, 22, 22, 23, 23, 24, 25, 25, 26,
    26, 27, 28, 28, 29, 30, 30, 31, 32, 33, 33, 34, 35, 36, 36, 37,
    38, 39, 40, 40, 41, 42, 43, 44, 45, 45, 46, 47, 48, 49, 50, 51,
    52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67,
    68, 69, 70, 71, 72, 74, 75, 76, 77, 78, 79, 81, 82, 83, 84, 86,
    87, 88, 89, 91, 92, 93, 95, 96, 97, 99, 100, 101, 103, 104, 105, 107,
    108, 110, 111, 112, 114, 115, 117, 118, 120, 121, 123, 124, 126, 128, 129, 131,
    132, 134, 135, 137, 139, 140, 142, 144, 145, 147, 149, 150, 152, 154, 156, 157,
    159, 161, 163, 164, 166, 168, 170, 172, 174, 175, 177, 179, 181, 183, 185, 187,
    189, 191, 193, 195, 197, 199, 201, 203, 205, 207, 209, 211, 213, 215, 217, 219,
    221, 223, 226, 228, 230, 232, 234, 236, 239, 241, 243, 245, 248, 250, 252, 255};

void new_gamma_table(float gamma)
{
    if (gamma <= 0)
    {
        log_e("gamma value should be greater than 0");
        return;
    }
    for (int i = 0; i < MAX_PROGRESS; i++)
    {
        gamma_table[i] = pow(i / 255.0, gamma) * 255;
    }
}