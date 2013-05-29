#include "pebble_os.h"
#include "pebble_app.h"
#include "pebble_fonts.h"


#define MY_UUID { 0xCF, 0x91, 0xE3, 0xEC, 0xB4, 0xB0, 0x43, 0x59, 0x8A, 0xD4, 0xAB, 0x10, 0x81, 0x8F, 0xE8, 0xF8 }
PBL_APP_INFO(MY_UUID,
             "TestApp", "TMD",
             1, 0, /* App version */
             DEFAULT_MENU_ICON,
             APP_INFO_STANDARD_APP); //APP_INFO_WATCH_FACE

Window window;
TextLayer text_layer;

void handle_init(AppContextRef ctx) {
  (void)ctx;

  window_init(&window, "Main window");
  window_stack_push(&window, true /* Animated */);
	
  text_layer_init(&text_layer, GRect(0, 60, 144 /* width */, 20 /* height */));
  text_layer_set_text(&text_layer, "Hoi Sander!");
  text_layer_set_text_alignment(&text_layer, GTextAlignmentCenter);
  layer_add_child(&window.layer, &text_layer.layer);
}


void pbl_main(void *params) {
  PebbleAppHandlers handlers = {
    .init_handler = &handle_init
  };
  app_event_loop(params, &handlers);
}
