# orhan yigit durmaz is at it again
# (im too embarrassed to say i accidentally deleted my
# github commits and i didnt had a local copy)


#--------------------- OpenFFBoard Headers ---------------------#
set(FFBOARD_HEADERS
    "../../../FFBoard/Inc"
)

set(FFBOARD_USEREXT_HEADERS
    "../../../FFBoard/UserExtensions/Inc"
)

set(TINYUSB_HEADERS
    "../../../FFBoard/USB"
    "../../../FFBoard/USB/class/audio"
    "../../../FFBoard/USB/class/bth"
    "../../../FFBoard/USB/class/cdc"
    "../../../FFBoard/USB/class/dfu"
    "../../../FFBoard/USB/class/hid"
    "../../../FFBoard/USB/class/midi"
    "../../../FFBoard/USB/class/msc"
    "../../../FFBoard/USB/class/net"
    "../../../FFBoard/USB/class/usbtmc"
    "../../../FFBoard/USB/class/vendor"
    "../../../FFBoard/USB/class/video"
    "../../../FFBoard/USB/common"
    "../../../FFBoard/USB/device"
    "../../../FFBoard/USB/host"
    "../../../FFBoard/USB/osal"
    "../../../FFBoard/USB/portable"
    "../../../FFBoard/USB/typec"
)

#--------------------- OpenFFBoardSources ---------------------#
set(FFBOARD_SOURCES
    "../../../FFBoard/Src/AdcHandler.cpp"
    "../../../FFBoard/Src/AnalogAxisProcessing.cpp"
    "../../../FFBoard/Src/AnalogSource.cpp"
    "../../../FFBoard/Src/AxesManager.cpp"
    "../../../FFBoard/Src/Axis.cpp"
    "../../../FFBoard/Src/ButtonSource.cpp"
    "../../../FFBoard/Src/CAN.cpp"
    "../../../FFBoard/Src/CanHandler.cpp"
    "../../../FFBoard/Src/CANPort2B.cpp"
    "../../../FFBoard/Src/ccondition_variable.cpp"
    "../../../FFBoard/Src/CDCcomm.cpp"
    "../../../FFBoard/Src/cevent_groups.cpp"
    "../../../FFBoard/Src/CmdParser.cpp"
    "../../../FFBoard/Src/cmem_pool.cpp"
    "../../../FFBoard/Src/cmutex.cpp"
    "../../../FFBoard/Src/CommandHandler.cpp"
    "../../../FFBoard/Src/CommandInterface.cpp"
    "../../../FFBoard/Src/cppmain.cpp"
    "../../../FFBoard/Src/cqueue.cpp"
    "../../../FFBoard/Src/CRC.cpp"
    "../../../FFBoard/Src/cread_write_lock.cpp"
    "../../../FFBoard/Src/csemaphore.cpp"
    "../../../FFBoard/Src/ctasklet.cpp"
    "../../../FFBoard/Src/cthread.cpp"
    "../../../FFBoard/Src/ctickhook.cpp"
    "../../../FFBoard/Src/ctimer.cpp"
    "../../../FFBoard/Src/cworkqueue.cpp"
    "../../../FFBoard/Src/eeprom.c"
    "../../../FFBoard/Src/EffectsCalculator.cpp"
    "../../../FFBoard/Src/Encoder.cpp"
    "../../../FFBoard/Src/ErrorHandler.cpp"
    "../../../FFBoard/Src/ExtiHandler.cpp"
    "../../../FFBoard/Src/FFBoardMainCommandThread.cpp"
    "../../../FFBoard/Src/Filters.cpp"
    "../../../FFBoard/Src/flash_helpers.cpp"
    "../../../FFBoard/Src/global_callbacks.cpp"
    "../../../FFBoard/Src/HidCommandInterface.cpp"
    "../../../FFBoard/Src/HidFFB.cpp"
    "../../../FFBoard/Src/I2C.cpp"
    "../../../FFBoard/Src/I2CHandler.cpp"
    "../../../FFBoard/Src/ledEffects.cpp"
    "../../../FFBoard/Src/MidiHandler.cpp"
    "../../../FFBoard/Src/MotorDriver.cpp"
    "../../../FFBoard/Src/PersistentStorage.cpp"
    "../../../FFBoard/Src/ringbuffer.c"
    "../../../FFBoard/Src/ringbufferwrapper.cpp"
    "../../../FFBoard/Src/SelectableInputs.cpp"
    "../../../FFBoard/Src/SerialFFB.cpp"
    "../../../FFBoard/Src/SPI.cpp"
    "../../../FFBoard/Src/SpiHandler.cpp"
    "../../../FFBoard/Src/SystemCommands.cpp"
    "../../../FFBoard/Src/TimerHandler.cpp"
    "../../../FFBoard/Src/UART.cpp"
    "../../../FFBoard/Src/UartHandler.cpp"
    "../../../FFBoard/Src/USBdevice.cpp"
    "../../../FFBoard/Src/UsbHidHandler.cpp"
    "../../../FFBoard/Src/voltagesense.cpp"
)

set(FFBOARD_USEREXT_SOURCES
    "../../../FFBoard/UserExtensions/Src/ADS111X.cpp"
    "../../../FFBoard/UserExtensions/Src/AnalogSources.cpp"
    "../../../FFBoard/UserExtensions/Src/ButtonSources.cpp"
    "../../../FFBoard/UserExtensions/Src/CanAnalog.cpp"
    "../../../FFBoard/UserExtensions/Src/CanBridge.cpp"
    "../../../FFBoard/UserExtensions/Src/CanButtons.cpp"
    "../../../FFBoard/UserExtensions/Src/CanInputMain.cpp"
    "../../../FFBoard/UserExtensions/Src/CustomMain.cpp"
    "../../../FFBoard/UserExtensions/Src/eeprom_addresses.c"
    "../../../FFBoard/UserExtensions/Src/EncoderBissC.cpp"
    "../../../FFBoard/UserExtensions/Src/EncoderLocal.cpp"
    "../../../FFBoard/UserExtensions/Src/EncoderSources.cpp"
    "../../../FFBoard/UserExtensions/Src/EncoderSSI.cpp"
    "../../../FFBoard/UserExtensions/Src/FFBHIDExt.cpp"
    "../../../FFBoard/UserExtensions/Src/FFBHIDMain_commmands.cpp"
    "../../../FFBoard/UserExtensions/Src/FFBHIDMain.cpp"
    "../../../FFBoard/UserExtensions/Src/FFBJoystick.cpp"
    "../../../FFBoard/UserExtensions/Src/FFBoardMain.cpp"
    "../../../FFBoard/UserExtensions/Src/FFBWheel.cpp"
    "../../../FFBoard/UserExtensions/Src/LocalAnalog.cpp"
    "../../../FFBoard/UserExtensions/Src/LocalButtons.cpp"
    "../../../FFBoard/UserExtensions/Src/mainclass_chooser.cpp"
    "../../../FFBoard/UserExtensions/Src/MidiMain.cpp"
    "../../../FFBoard/UserExtensions/Src/MotorPWM.cpp"
    "../../../FFBoard/UserExtensions/Src/MotorSimplemotion.cpp"
    "../../../FFBoard/UserExtensions/Src/MtEncoderSPI.cpp"
    "../../../FFBoard/UserExtensions/Src/ODriveCAN.cpp"
    "../../../FFBoard/UserExtensions/Src/PCF8574.cpp"
    "../../../FFBoard/UserExtensions/Src/RmdMotorCAN.cpp"
    "../../../FFBoard/UserExtensions/Src/ShifterAnalog.cpp"
    "../../../FFBoard/UserExtensions/Src/SPIButtons.cpp"
    "../../../FFBoard/UserExtensions/Src/TMC4671.cpp"
    "../../../FFBoard/UserExtensions/Src/TMCDebugBridge.cpp"
    "../../../FFBoard/UserExtensions/Src/usb_descriptors.cpp"
    "../../../FFBoard/UserExtensions/Src/usb_hid_1ffb_desc.c"
    "../../../FFBoard/UserExtensions/Src/usb_hid_2ffb_desc.c"
    "../../../FFBoard/UserExtensions/Src/usb_hid_gamepad.c"
    "../../../FFBoard/UserExtensions/Src/VescCAN.cpp"
)

set(TINYUSB_SOURCES
    "../../../FFBoard/USB/tusb.c"
    "../../../FFBoard/USB/class/audio/audio_device.c"
    "../../../FFBoard/USB/class/bth/bth_device.c"
    "../../../FFBoard/USB/class/cdc/cdc_device.c"
    "../../../FFBoard/USB/class/cdc/cdc_host.c"
    "../../../FFBoard/USB/class/cdc/cdc_rndis_host.c"
    "../../../FFBoard/USB/class/dfu/dfu_device.c"
    "../../../FFBoard/USB/class/dfu/dfu_rt_device.c" # i know this is not needed just whynot huh
    "../../../FFBoard/USB/class/hid/hid_device.c"
    "../../../FFBoard/USB/class/hid/hid_host.c"
    "../../../FFBoard/USB/class/midi/midi_device.c"
    "../../../FFBoard/USB/class/msc/msc_device.c"
    "../../../FFBoard/USB/class/msc/msc_host.c"
    "../../../FFBoard/USB/class/net/ecm_rndis_device.c"
    "../../../FFBoard/USB/class/net/ncm_device.c"
    "../../../FFBoard/USB/class/usbtmc/usbtmc_device.c"
    "../../../FFBoard/USB/class/vendor/vendor_device.c"
    "../../../FFBoard/USB/class/vendor/vendor_host.c"
    "../../../FFBoard/USB/class/video/video_device.c"
    "../../../FFBoard/USB/common/tusb_fifo.c"
    "../../../FFBoard/USB/device/usbd.c"
    "../../../FFBoard/USB/device/usbd_control.c"
    "../../../FFBoard/USB/host/hub.c"
    "../../../FFBoard/USB/host/usbh.c"
    #from portables we only need the espressif one
    "../../../FFBoard/USB/portable/espressif/esp32sx/dcd_esp32sx.c"
)

#--------------------- Target Port Headers ---------------------#
set(TARGET_HEADERS
    "."
    "${IDF_PATH}/components/freertos/FreeRTOS-Kernel/include/freertos"
)

#--------------------- Target Port Sources ---------------------#
set(TARGET_SOURCES
    "main.cpp"
)

#--------------------- freertos fix ---------------------#


#--------------------- Finally register everything ---------------------#
idf_component_register(SRCS ${TARGET_SOURCES} ${FFBOARD_SOURCES} ${FFBOARD_USEREXT_SOURCES} ${TINYUSB_SOURCES}
                    INCLUDE_DIRS ${TARGET_HEADERS} ${FFBOARD_HEADERS} ${FFBOARD_USEREXT_HEADERS} ${TINYUSB_HEADERS})
