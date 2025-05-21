#include "main.h"

// Define GPIO pins
#define SEAT_SENSOR_GPIO    GPIOA
#define SEAT_SENSOR_PIN     GPIO_PIN_0

#define BELT_SENSOR_GPIO    GPIOA
#define BELT_SENSOR_PIN     GPIO_PIN_1

#define BUZZER_GPIO         GPIOA
#define BUZZER_PIN          GPIO_PIN_5

void SystemClock_Config(void);
static void MX_GPIO_Init(void);

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();

  while (1)
  {
    // Read seat occupancy and belt status
    GPIO_PinState seatOccupied = HAL_GPIO_ReadPin(SEAT_SENSOR_GPIO, SEAT_SENSOR_PIN);
    GPIO_PinState beltFastened = HAL_GPIO_ReadPin(BELT_SENSOR_GPIO, BELT_SENSOR_PIN);

    if (seatOccupied == GPIO_PIN_SET && beltFastened == GPIO_PIN_RESET)
    {
      // Seat is occupied and belt is not fastened -> alert
      HAL_GPIO_WritePin(BUZZER_GPIO, BUZZER_PIN, GPIO_PIN_SET);
    }
    else
    {
      // No alert
      HAL_GPIO_WritePin(BUZZER_GPIO, BUZZER_PIN, GPIO_PIN_RESET);
    }

    HAL_Delay(200); // Polling delay
  }
}
