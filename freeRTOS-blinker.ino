#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif
// Pins
static const int led_pin = 6;
void toggleLED(void *parameter) {
  while(1) {
    digitalWrite(led_pin, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(led_pin, LOW);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void setup() {
  // Configure pin
  pinMode(led_pin, OUTPUT);
  // Task to run forever
  xTaskCreatePinnedToCore (
    toggleLED, //Function to be called
    "Toggle LED", // Name of the task
    1024, // Stack size (bytes in ESP32, words in FreeRTOS)
    NULL, // Parameter to passs to function
    1, // Task priority (0 to configMAX_PRIORITIES -1)
    NULL, // Task handel
    app_cpu); // Run on one core for demo purpose (esp32 only)
}

void loop() {

}
