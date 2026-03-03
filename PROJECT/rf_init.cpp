
#include "main.h"
#include "project.h"
#include <cstdint>

/* ---------------------  UTILITY FUNCTIONS BEGIN  --------------------- */
void Csn_Low(){HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);}

void Csn_High(){HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);}

void Blink_Test(){
    HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_8);
    HAL_Delay(500);
}

void UART_Display(char* msg, int size){
    HAL_UART_Transmit(
        &huart1,
        reinterpret_cast<uint8_t*> (msg),
        size,
        HAL_MAX_DELAY
    );
}

void uS_Delay(int uS){
    HTIM
}

// ADD A TMER UTILITY FUNCTION HERE uS 
/* ---------------------  UTILITY FUNCTIONS END  --------------------- */







