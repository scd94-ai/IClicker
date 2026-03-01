
#include "main.h"
#include "project.h"
#include <cstdint>

void Blink_Test(){
    HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_8);
    HAL_Delay(500);
}

void Blink_Test2(){
    HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_8);
    HAL_Delay(1000);
}

