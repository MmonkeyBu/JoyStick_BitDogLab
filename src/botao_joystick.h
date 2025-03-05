#ifndef BOTAO_JOYSTICK_H
#define BOTAO_JOYSTICK_H

#include <stdbool.h>

#define TEMPO_DEBOUNCE 150
#define BOTAO_A 5
#define BOTAO_B 6
#define JOYSTICK_BUTTON 22

extern volatile bool estado_inverter;

void botao_callback(uint gpio, uint32_t eventos);
void botao_init(uint8_t pino);

#endif
