// #include "stm32h7xx_hal_gpio.h"
// #include "stm32h7xx_hal_tim.h"
#include "main.h"
#include <stdbool.h>

void program (void) {


    // while (true) {
    //     HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, true);
    //     HAL_Delay(500);
    //     HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, false);
    // }

    HAL_TIM_PWM_Start( &htim4, TIM_CHANNEL_2);
    
    int pulse = 0;

    TIM_OC_InitTypeDef sConfigOC = {
        .Pulse = pulse,
        .OCMode = TIM_OCMODE_PWM1,
        .OCPolarity = TIM_OCPOLARITY_HIGH,
        .OCFastMode = TIM_OCFAST_DISABLE,
    };
    

    while (1) {
        if(pulse > 10000){
            pulse = 0;
        }

        sConfigOC.Pulse = pulse;

        HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_2);

        HAL_Delay(1);

        pulse += 10;

    }
    

    
}