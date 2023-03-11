#include <stdio.h>
#include "gpios.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"
#include "esp_system.h"


//ESP_LOGI("GPIOs", "Trying to connect with Wi-Fi\n");
static esp_adc_cal_characteristics_t adc0_chars;

void setup_GPIO()
{
    gpio_set_direction(GPIO_NUM_0, GPIO_MODE_INPUT);
}

void setup_ADC()
{
    esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_DEFAULT, 0, &adc0_chars);
    ESP_ERROR_CHECK(adc1_config_width(ADC_WIDTH_BIT_DEFAULT));
    ESP_ERROR_CHECK(adc1_config_channel_atten(ADC1_CHANNEL_0, ADC_ATTEN_DB_0));
}

uint32_t get_ADC()
{
    return adc1_get_raw(ADC1_CHANNEL_0);
}

