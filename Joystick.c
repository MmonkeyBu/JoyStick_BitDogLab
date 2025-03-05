#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "direcao.h"
#include "botao_joystick.h"

int main() {
    stdio_init_all();
    adc_init();
    adc_gpio_init(26);
    adc_gpio_init(27); 

    //botao B para bootSeel
    botao_init(BOTAO_B);
    botao_init(JOYSTICK_BUTTON);

    while (1) {
        adc_select_input(0);
        uint adc_y_raw = adc_read();
        adc_select_input(1);
        uint adc_x_raw = adc_read();
        
        //print_direction(adc_x_raw, adc_y_raw, estado_inverter);
        //detectar_gesto(adc_x_raw, adc_y_raw);
        porcentagem(adc_x_raw, adc_y_raw);

        sleep_ms(100);
    }
}