/*

   How to use a custom non-system font.

 */

#include "pebble.h"

static Window *window;
static GBitmap *background_image;
static BitmapLayer *background_layer;
static TextLayer *text_layer, *text_layer2, *text_layer3, *text_layer4;

static void init() {
  window = window_create();
  window_stack_push(window, true /* Animated */);

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  background_image = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_BACKGROUND);
  background_layer = bitmap_layer_create(layer_get_frame(window_layer));
  bitmap_layer_set_bitmap(background_layer, background_image);
  layer_add_child(window_layer, bitmap_layer_get_layer(background_layer));
  
  GFont custom_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_EJEMPLO_BOLD_64));
  GFont custom_font2 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_MINI_BOLD_32));
  GFont custom_font3 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_DIA_32));
  GFont custom_font4 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_MINI_BOLD_32));

  text_layer = text_layer_create((GRect) { .origin = { 7, 69 }, .size = { 100, 70 } });
  text_layer_set_text(text_layer, "12:44");
  text_layer_set_font(text_layer, custom_font);
    text_layer_set_background_color(text_layer, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(text_layer));
  
    text_layer2 = text_layer_create((GRect) { .origin = { 107, 106 }, .size = { 40, 40 } });
  text_layer_set_text(text_layer2, "12");
  text_layer_set_font(text_layer2, custom_font2);
    text_layer_set_background_color(text_layer2, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(text_layer2));
  
    text_layer3 = text_layer_create((GRect) { .origin = { 72, 62}, .size = { 40, 40 } });
  text_layer_set_text(text_layer3, "13");
  text_layer_set_font(text_layer3, custom_font3);
    text_layer_set_background_color(text_layer3, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(text_layer3));
  
    text_layer4 = text_layer_create((GRect) { .origin = { 0, 110 }, .size = { bounds.size.w, 40 } });
  text_layer_set_text(text_layer4, "");
  text_layer_set_font(text_layer4, custom_font4);
    text_layer_set_background_color(text_layer4, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(text_layer4));
}

static void deinit() {
  text_layer_destroy(text_layer);
    text_layer_destroy(text_layer2);
  text_layer_destroy(text_layer3);
  text_layer_destroy(text_layer4);
    layer_remove_from_parent(bitmap_layer_get_layer(background_layer));
  bitmap_layer_destroy(background_layer);
  gbitmap_destroy(background_image);
  background_image = NULL;

  window_destroy(window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
