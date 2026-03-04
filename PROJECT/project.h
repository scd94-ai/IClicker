#ifndef PROJECT_H_
#define PROJECT_H_

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

void Blink_Test(void);
void Csn_Low(void);
void Csn_High(void);
void CC2500_Reset();
void UART_Display(char*, int);
uint8_t CC2500_ReadReg(uint8_t, bool);
#ifdef __cplusplus
}
#endif

#endif /* INC_CPP_CUSTOM_H_ */