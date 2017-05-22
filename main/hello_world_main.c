/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "esp_spi_flash.h"

#define GPIO_LED GPIO_NUM_33

void blinkTask(void *pvParameter){
  gpio_pad_select_gpio(GPIO_LED);
  gpio_set_direction(GPIO_LED, GPIO_MODE_OUTPUT);
  while (1) {
    gpio_set_level(GPIO_LED, 0);
    vTaskDelay(1000/portTICK_RATE_MS);
    gpio_set_level(GPIO_LED, 1);
    vTaskDelay(1000/portTICK_RATE_MS);
  }
}

void app_main(){
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    printf("[Dark Side of the Solder] Blink LED\n");
    xTaskCreate(&blinkTask, "Demo blink", 512, NULL, 5, NULL);
}
