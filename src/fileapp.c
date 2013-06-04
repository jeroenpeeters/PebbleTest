#include "pebble_os.h"
#include "pebble_app.h"
#include "pebble_fonts.h"
#include "http.h"
#include "mini-printf.h"
	
// The auto-generated header file with resource handle definitions
#include "resource_ids.auto.h"

#define MY_UUID { 0x91, 0x41, 0xB6, 0x28, 0xBC, 0x89, 0x49, 0x8E, 0xB1, 0x47, 0x04, 0x9F, 0x49, 0xC0, 0x99, 0xAD }
PBL_APP_INFO(MY_UUID,
             "FileApp", "TMD",
             1, 0, /* App version */
             DEFAULT_MENU_ICON,
             APP_INFO_WATCH_FACE); //APP_INFO_STANDARD_APP

Window window;
TextLayer text_h1;
TextLayer text_h2;
TextLayer text_m1;
TextLayer text_m2;

void init_time_text(TextLayer *text_layer, GFont custom_font){
	text_layer_set_text_alignment(text_layer, GTextAlignmentLeft);
	text_layer_set_text_color(text_layer, GColorWhite);
	text_layer_set_background_color(text_layer, GColorBlack);
	text_layer_set_font(text_layer, custom_font);
  	layer_add_child(&window.layer, &(*text_layer).layer);
	text_layer_set_text(text_layer, "0");
}

void handle_init(AppContextRef ctx) {
   (void)ctx;

	// init window
  	window_init(&window, "Main window");
	window_set_background_color(&window, GColorBlack);
  	window_stack_push(&window, true /* Animated */);
	
	resource_init_current_app(&APP_RESOURCES);
	
	GFont custom_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_SILK_WONDER_25));
	
	static int x_startpos = 40;
	static int y = 70;
	static int w = 16;
	//init time layer
  	text_layer_init(&text_h1, GRect((0*w)+x_startpos, y, w /* width */, 100 /* height */));
  	init_time_text(&text_h1, custom_font);
	text_layer_init(&text_h2, GRect((1*w)+x_startpos, y, w /* width */, 100 /* height */));
  	init_time_text(&text_h2, custom_font);
	
	text_layer_init(&text_m1, GRect((2*w)+x_startpos, y, w /* width */, 100 /* height */));
  	init_time_text(&text_m1, custom_font);
	text_layer_init(&text_m2, GRect((3*w)+x_startpos, y, w /* width */, 100 /* height */));
  	init_time_text(&text_m2, custom_font);
}


void handle_deinit(AppContextRef ctx){
}

void handle_tick(AppContextRef app_ctx, PebbleTickEvent *event){
	static char date_text[] = "000000";
	string_format_time(date_text, sizeof(date_text), "%H%M%S", event->tick_time);
	
	static char sb1[2];	
	memcpy( sb1, &date_text[0], 1 );
	sb1[1] = '\0';
	text_layer_set_text(&text_h1, sb1);
	static char sb2[2];	
	memcpy( sb2, &date_text[1], 1 );
	sb2[1] = '\0';
	text_layer_set_text(&text_h2, sb2);
	static char sb3[2];	
	memcpy( sb3, &date_text[2], 1 );
	sb3[1] = '\0';
	text_layer_set_text(&text_m1, sb3);
	static char sb4[2];	
	memcpy( sb4, &date_text[3], 1 );
	sb4[1] = '\0';
	text_layer_set_text(&text_m2, sb4);
}

void pbl_main(void *params) {
	PebbleAppHandlers handlers = {
    	.init_handler = &handle_init,
	  	.tick_info = {
     		.tick_handler = &handle_tick,    // called repeatedly, each second
     		.tick_units = MINUTE_UNIT        // specifies interval of `tick_handler`
        },
   		.deinit_handler = &handle_deinit,
		.messaging_info = {
			.buffer_sizes = {
				.inbound = 124,
				.outbound = 124,
		    }
	    }
    };
  	app_event_loop(params, &handlers);
}