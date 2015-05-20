/*

   How to use a custom non-system font.

 */

#include "pebble.h"

static Window *window;
static GBitmap *background_image;
static BitmapLayer *background_layer;
static TextLayer *text_layer_hora, *text_layer_segundos, *text_layer_fecha1, *text_layer_fecha2, *text_layer_letras, *text_layer_ano, *text_layer_bateria;

static void init() {
  window = window_create();
  window_stack_push(window, true /* Animated */);

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  background_image = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_BACKGROUND);
  background_layer = bitmap_layer_create(layer_get_frame(window_layer));
  bitmap_layer_set_bitmap(background_layer, background_image);
  layer_add_child(window_layer, bitmap_layer_get_layer(background_layer));
  
  GFont fuente_hora = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FUENTE_HORA_64));
  GFont fuente_segundos = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FUENTE_SEGUNDOS_32));
  GFont fuente_fecha = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FUENTE_FECHA_32));
  GFont fuente_letras = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FUENTE_LETRAS_24));
  GFont fuente_bateria = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FUENTE_BATERIA_8));

  text_layer_hora = text_layer_create((GRect) { .origin = { 7, 69 }, .size = { 100, 70 } });
  text_layer_set_text(text_layer_hora, "12:44");
  text_layer_set_font(text_layer_hora, fuente_hora);
  text_layer_set_background_color(text_layer_hora, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(text_layer_hora));
  
  text_layer_segundos = text_layer_create((GRect) { .origin = { 107, 106 }, .size = { 40, 40 } });
  text_layer_set_text(text_layer_segundos, "12");
  text_layer_set_font(text_layer_segundos, fuente_segundos);
  text_layer_set_background_color(text_layer_segundos, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(text_layer_segundos));
  
  text_layer_fecha1 = text_layer_create((GRect) { .origin = { 72, 62}, .size = { 40, 40 } });
  text_layer_set_text(text_layer_fecha1, "13");
  text_layer_set_font(text_layer_fecha1, fuente_fecha);
  text_layer_set_background_color(text_layer_fecha1, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(text_layer_fecha1));
  
  text_layer_fecha2 = text_layer_create((GRect) { .origin = { 110, 62}, .size = { 40, 40 } });
  text_layer_set_text(text_layer_fecha2, "07");
  text_layer_set_font(text_layer_fecha2, fuente_fecha);
  text_layer_set_background_color(text_layer_fecha2, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(text_layer_fecha2));
    
  
  text_layer_letras = text_layer_create((GRect) { .origin = { 41, 33}, .size = { 70, 40 } });
  text_layer_set_text(text_layer_letras, "LUN");
  text_layer_set_font(text_layer_letras, fuente_letras);
  text_layer_set_background_color(text_layer_letras, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(text_layer_letras));
  
  text_layer_ano = text_layer_create((GRect) { .origin = { 102, 33}, .size = { 70, 40 } });
  text_layer_set_text(text_layer_ano, "15");
  text_layer_set_font(text_layer_ano, fuente_letras);
  text_layer_set_background_color(text_layer_ano, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(text_layer_ano));
  
  text_layer_bateria = text_layer_create((GRect) { .origin = { 14, 41}, .size = { 30, 30 } });
  text_layer_set_text(text_layer_bateria, "70");
  text_layer_set_font(text_layer_bateria, fuente_bateria);
  text_layer_set_background_color(text_layer_bateria, GColorClear);
  layer_add_child(window_layer, text_layer_get_layer(text_layer_bateria));
}

static void deinit() {
  text_layer_destroy(text_layer_hora);
  text_layer_destroy(text_layer_segundos);
  text_layer_destroy(text_layer_fecha1);
  text_layer_destroy(text_layer_letras);
  text_layer_destroy(text_layer_ano);
  text_layer_destroy(text_layer_fecha2);
  text_layer_destroy(text_layer_bateria);

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
