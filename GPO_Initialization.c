static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  __HAL_RCC_GPIOA_CLK_ENABLE();

  // Seat sensor input
  GPIO_InitStruct.Pin = SEAT_SENSOR_PIN | BELT_SENSOR_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(SEAT_SENSOR_GPIO, &GPIO_InitStruct);

  // Buzzer output
  GPIO_InitStruct.Pin = BUZZER_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(BUZZER_GPIO, &GPIO_InitStruct);

  // Initialize buzzer to OFF
  HAL_GPIO_WritePin(BUZZER_GPIO, BUZZER_PIN, GPIO_PIN_RESET);
}
