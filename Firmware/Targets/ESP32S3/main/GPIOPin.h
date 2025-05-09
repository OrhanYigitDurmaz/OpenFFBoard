#pragma once

#include <driver/gpio.h>
#include <esp_err.h>
#include <functional>
#include <cstdint>

// Forward declaration
class ExtiHandler;

// GPIO Pin wrapper for ESP32, designed to be API compatible with STM32 version
class OutputPin {
public:
    // Constructor with pin number and initial state
    OutputPin(gpio_num_t pin, bool state = false) : pin_num(pin) {
        // Configure as output
        gpio_config_t io_conf = {};
        io_conf.intr_type = GPIO_INTR_DISABLE;
        io_conf.mode = GPIO_MODE_OUTPUT;
        io_conf.pin_bit_mask = (1ULL << pin_num);
        io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
        io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
        esp_err_t result = gpio_config(&io_conf);
        if (result != ESP_OK) {
            // Handle error?
        }

        // Set initial state
        write(state);
    }

    // Write to the pin
    void write(bool state) {
        gpio_set_level(pin_num, state ? 1 : 0);
    }

    // Toggle the pin
    void toggle() {
        int level = gpio_get_level(pin_num);
        gpio_set_level(pin_num, !level);
    }

    // Get pin state
    bool read() {
        return gpio_get_level(pin_num) != 0;
    }

    // Comparison operator
    bool operator==(const OutputPin& other) const {
        return pin_num == other.pin_num;
    }

    // Get the raw pin number
    gpio_num_t getPin() const {
        return pin_num;
    }

protected:
    gpio_num_t pin_num;
};

// Input pin class
class InputPin : public OutputPin {
public:
    // Pin modes
    enum PinMode {
        Input = 0,
        InputPullUp,
        InputPullDown
    };

    // Constructor
    InputPin(gpio_num_t pin, PinMode mode = Input, gpio_int_type_t interruptMode = GPIO_INTR_DISABLE) 
        : OutputPin(pin, false) {
        
        // Configure GPIO
        gpio_config_t io_conf = {};
        io_conf.intr_type = interruptMode;
        io_conf.mode = GPIO_MODE_INPUT;
        io_conf.pin_bit_mask = (1ULL << pin_num);
        
        switch (mode) {
            case InputPullUp:
                io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
                io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
                break;
            case InputPullDown:
                io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
                io_conf.pull_down_en = GPIO_PULLDOWN_ENABLE;
                break;
            default: // Input
                io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
                io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
                break;
        }
        
        gpio_config(&io_conf);
    }
    
    // Set interrupt handler
    void setInterruptHandler(std::function<void(void)> callback) {
        if (callback) {
            gpio_isr_handler_add(pin_num, [](void* arg) {
                auto cb = reinterpret_cast<std::function<void(void)>*>(arg);
                (*cb)();
            }, (void*)&callback);
        }
    }
};

// GPIO Pin class for analog pins (ADC)
class AnalogPin : public InputPin {
public:
    AnalogPin(gpio_num_t pin) : InputPin(pin, Input) {
        // ESP32-specific ADC setup would go here
        // Unlike STM32, ESP32 has specific GPIO pins that can be used as ADC
        // GPIO 32-39 are ADC1 channels on ESP32
    }

    // Read analog value
    uint16_t readAnalog() {
        // This would need to be implemented using the ESP-IDF ADC API
        // For now, just a placeholder
        return 0;
    }
};