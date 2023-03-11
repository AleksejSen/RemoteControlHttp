#ifndef WIFISTATION_H_
#define WIFISTATION_H_

#define  EXAMPLE_ESP_WIFI_SSID "WifiHome"
//#define EXAMPLE_ESP_WIFI_SSID "Adazi"
#define EXAMPLE_ESP_WIFI_PASS "Walter37"
#define MAX_RETRY 10

static esp_err_t wifi_event_handler(void *arg, esp_event_base_t event_base,
                                    int32_t event_id, void *event_data);
void wifi_init(void);


#endif