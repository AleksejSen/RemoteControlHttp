#ifdef HTTPCLIENT_H_
#define HTTPCLIENT_H_



#define MAX_RETRY 10
static int retry_cnt = 0;

void HttpGet_Task(void *params);
static void volumeDownGet();
static void volumeUpGet();
esp_err_t client_event_get_handler(esp_http_client_event_handle_t evt);

#endif