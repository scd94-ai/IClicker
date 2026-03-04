
#include "main.h"
#include "project.h"
#include <cstdint>
#include <cstdio>

/* ---------------------  UTILITY FUNCTIONS BEGIN  --------------------- */
void Csn_Low(){HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);}

void Csn_High(){HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);}

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
    TIM2->CNT = 0;
    while(TIM2->CNT < uS); 
}


void CC2500_Reset(){
/* CC2500_Reset:
1) Set SCLK=1 and SI=0, to avoid potential problems with pin control mode
2) Strobe CSnlow / high. Hold CSn high for at least 40 µs relative to pulling CSn low
3) Pull CSn low and wait for SO to go low (CHIP_RDYn).
4) Issue the SRESstrobe on the SI line.
5) When SO goes low again, reset is complete and the chip is in the IDLE state. */
    char MSG[] = "---------------RESET COMPLETE!---------------\r\n";
    uint8_t SRES_STROBE = 0x30;
    uint8_t JUNK;
    Csn_High();
    uS_Delay(50);
    Csn_Low();
    uS_Delay(50);
    Csn_High();
    uS_Delay(50);
    Csn_Low();
    while (HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6) == GPIO_PIN_SET);
    HAL_SPI_TransmitReceive(&hspi1,&SRES_STROBE,&JUNK,1,HAL_MAX_DELAY);

    while (HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6) == GPIO_PIN_SET);
    UART_Display(MSG,sizeof(MSG));
    return;
}

/* ---------------------  UTILITY FUNCTIONS END  --------------------- */
/////////////////////////////////////////////////////////////////////////
/* -----------------------  SPI COMMUNICATION  ----------------------- */

uint8_t CC2500_ReadReg(uint8_t addr, bool display_status){
    char msg[64];
    uint8_t cmd = (addr & 0x3F) | 0x80;    
    uint8_t tx[2] = { cmd, 0x00 };    uint8_t rx[2];
    Csn_Low();
    HAL_SPI_TransmitReceive(&hspi1, tx, rx, 2, 100);
    Csn_High();
    int size_of_message = snprintf(msg,64,"Status Byte: 0x%X \r\n", rx[0]);
    if (display_status){
        UART_Display(msg,size_of_message);
    }

    return rx[1];
}
    




