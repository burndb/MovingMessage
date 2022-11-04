#include <ESPAsyncWebServer.h>


/* Network */
const char *ssid = "MOVING-MESSAGE";
const char *pw = "eisdiele";
AsyncWebServer server(80);



/* http query parameters*/
const char *PARAM_INPUT_PWR = "power";
const char *PARAM_INPUT_MODE = "direction";
const char *PARAM_INPUT_STRING = "string";
const char *PARAM_INPUT_SPEED = "speed";

/* Message control */
bool power = true;
bool runLeft = false;
int offset = 0;
int speed = 8;

/* uC pinout */
#define D1 D1
#define C1 D2
#define STR D3
#define LEDS D4
#define BCD0 D7
#define BCD1 D6
#define BCD2 D5