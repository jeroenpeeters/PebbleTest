#include "pebble_os.h"
#include "pebble_app.h"
#include "pebble_fonts.h"
#include "http.h"
#include "mini-printf.h"

//#define MY_UUID { 0xCF, 0x91, 0xE3, 0xEC, 0xB4, 0xB0, 0x43, 0x59, 0x8A, 0xD4, 0xAB, 0x10, 0x81, 0x8F, 0xE8, 0xF8 }
//#define MY_UUID { 0x91, 0x41, 0xB6, 0x28, 0xBC, 0x89, 0x49, 0x8E, 0xB1, 0x47, 0x04, 0x9F, 0x49, 0xC0, 0x99, 0xAD }
//PBL_APP_INFO(MY_UUID,
//             "TestApp", "TMD",
//             1, 0, /* App version */
//             DEFAULT_MENU_ICON,
//             APP_INFO_STANDARD_APP); //APP_INFO_WATCH_FACE

//#define WEATHER_HTTP_COOKIE 1949327671
/*
Window window;
TextLayer text_layer;
TextLayer text_top;

void reconnect(void* context){
  // Build the HTTP request
  DictionaryIterator *body;
  HTTPResult result = http_out_get("http://www.zone-mr.net/api/weather.php", WEATHER_HTTP_COOKIE, &body);
  if(result != HTTP_OK) {
  	text_layer_set_text(&text_layer, "HTTP Result NOK");
  }else{
  	text_layer_set_text(&text_layer, "HTTP Result OK");
  }
}

void success(int32_t cookie, int http_status, DictionaryIterator* received, void* context) {
	if(cookie != WEATHER_HTTP_COOKIE) return;
	Tuple* icon_tuple = dict_find(received, 1);
	if(icon_tuple) {
		int temp = icon_tuple->value->int8;
		char buf[3];
		mini_snprintf(buf, 3, "%d", temp);
		text_layer_set_text(&text_layer, buf);
	}
	text_layer_set_text(&text_top, "success");
}

void location(float latitude, float longitude, float altitude, float accuracy, void* context) {
	// Fix the floats
	reconnect(context);
}

void select_single_click_handler(ClickRecognizerRef recognizer, Window *window) {
   	text_layer_set_text(&text_top, "click");
	reconnect(NULL);
}

void config_provider(ClickConfig **config, Window *window) {
	config[BUTTON_ID_SELECT]->click.handler = (ClickHandler) select_single_click_handler;
}


void handle_init(AppContextRef ctx) {
  (void)ctx;

  window_init(&window, "Main window");
  window_stack_push(&window, true);

  window_set_click_config_provider(&window, (ClickConfigProvider) config_provider);
	
  text_layer_init(&text_layer, GRect(0, 60, 144, 20));
  text_layer_set_text_alignment(&text_layer, GTextAlignmentCenter);
  layer_add_child(&window.layer, &text_layer.layer);
	
  bool registered = http_register_callbacks((HTTPCallbacks){.reconnect=reconnect,.location=location,.success=success}, (void*)ctx);
	
  text_layer_init(&text_top, GRect(0, 0, 144, 20));
	if(registered){
		text_layer_set_text(&text_top, "true");
	}else{
		text_layer_set_text(&text_top, "false");
	}
  text_layer_set_text_alignment(&text_top, GTextAlignmentLeft);
  layer_add_child(&window.layer, &text_top.layer);
}

*/
