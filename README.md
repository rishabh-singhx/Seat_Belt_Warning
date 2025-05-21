# Seat_Belt_Warning


Here's a basic STM32 code example for a Seat Belt Warning and Alert System for passenger cars. This system detects:

Whether the seat is occupied (via a seat occupancy sensor).

Whether the seat belt is fastened (via a seat belt switch).

If the seat is occupied and the seat belt is not fastened, it triggers a buzzer and/or LED alert.

🚗 System Components:

Component	                    GPIO Pin (example)	                Description

Seat Occupancy Sensor	        PA0	                                Input: HIGH if seat occupied

Seat Belt Switch	            PA1	                                Input: HIGH if belt fastened

Buzzer/Alert	                PA5	                                Output: Drives buzzer/LED

✅ Assumptions:

We're using STM32CubeIDE or HAL-based development.

The microcontroller is from STM32F1/F4 series.

HAL_GPIO_ReadPin() and HAL_GPIO_WritePin() are used for IO.

