#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "esp_system.h"
#include "nvs_flash.h"
#include "esp_event.h"
#include "esp_netif.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"
#include "esp_log.h"
#include "driver/gpio.h"

#include "httpClient.h"
#include "wifiStation.h"
#include "gpios.h"


static const char *TAG = "ESP32HTTP";

extern void HttpGet_Task(void *params);


void app_main(void)
{
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    wifi_init();
    setup_GPIO();

    vTaskDelay(2000 / portTICK_PERIOD_MS);
    ESP_LOGI(TAG, "INIT DONE");

    // rest_get();

    xTaskCreate(HttpGet_Task, "HttpGet_Task", 1024 * 5, NULL, 5, NULL);
}
