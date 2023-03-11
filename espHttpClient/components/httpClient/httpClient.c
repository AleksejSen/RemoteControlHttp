#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_netif.h"
#include "esp_log.h"

#include "esp_http_client.h"
#include "driver/gpio.h"
#include "httpClient.h"
#include "gpios.h"

static const char *TAG = "ESP32HTTP";


esp_err_t client_event_get_handler(esp_http_client_event_handle_t evt)
{
    switch (evt->event_id)
    {
    case HTTP_EVENT_ON_DATA:
        // printf("HTTP_EVENT_ON_DATA: %.*s\n", evt->data_len, (char *)evt->data);
        ESP_LOGI(TAG, "HTTP_EVENT_ON_DATA: %.*s\n", evt->data_len, (char *)evt->data);
        break;

    default:
        break;
    }
    return ESP_OK;
}

static void volumeUpGet()
{
    esp_http_client_config_t config_get = {
        .url = "http://192.168.0.104:5270/volup",
        .method = HTTP_METHOD_GET,
        .cert_pem = NULL,
        .event_handler = client_event_get_handler};

    esp_http_client_handle_t client = esp_http_client_init(&config_get);
    esp_http_client_perform(client);
    esp_http_client_cleanup(client);
}

static void volumeDownGet()
{
    esp_http_client_config_t config_get = {
        .url = "http://192.168.0.104:5270/voldown",
        .method = HTTP_METHOD_GET,
        .cert_pem = NULL,
        .event_handler = client_event_get_handler};

    esp_http_client_handle_t client = esp_http_client_init(&config_get);
    esp_http_client_perform(client);
    esp_http_client_cleanup(client);
}

void HttpGet_Task(void *params)
{
    while (true)
    {
        uint32_t buttons = get_ADC();
        
        //ESP_LOGI(TAG, "BUTTON VAL: %d\n", buttons);
        switch (buttons)
        {
            case 4095:
                ESP_LOGI(TAG, "BUTTON 1\n");
                volumeUpGet();
                break;
            case 2000 ... 2500:
                ESP_LOGI(TAG, "BUTTON 2\n");
                volumeDownGet();
                break;
            case 1400 ... 1600:
                ESP_LOGI(TAG, "BUTTON 3\n");
                volumeDownGet();
                break;
            case 1000 ... 1200:
                ESP_LOGI(TAG, "BUTTON 4\n");
                volumeDownGet();
                break;
            case 900 ... 950:
                ESP_LOGI(TAG, "BUTTON 5\n");
                volumeDownGet();
                break;
            
        }

        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

