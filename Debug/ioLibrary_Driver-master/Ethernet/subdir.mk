################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ioLibrary_Driver-master/Ethernet/socket.c \
../ioLibrary_Driver-master/Ethernet/wizchip_conf.c 

OBJS += \
./ioLibrary_Driver-master/Ethernet/socket.o \
./ioLibrary_Driver-master/Ethernet/wizchip_conf.o 

C_DEPS += \
./ioLibrary_Driver-master/Ethernet/socket.d \
./ioLibrary_Driver-master/Ethernet/wizchip_conf.d 


# Each subdirectory must supply rules for building sources it contributes
ioLibrary_Driver-master/Ethernet/%.o ioLibrary_Driver-master/Ethernet/%.su ioLibrary_Driver-master/Ethernet/%.cyclo: ../ioLibrary_Driver-master/Ethernet/%.c ioLibrary_Driver-master/Ethernet/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32G4xx_Nucleo -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"C:/Users/pc/Documents/STM32_Pruebas/FTP_SD_STM32G4/ioLibrary_Driver-master/Ethernet" -I"C:/Users/pc/Documents/STM32_Pruebas/FTP_SD_STM32G4/ioLibrary_Driver-master/Ethernet/W5500" -I"C:/Users/pc/Documents/STM32_Pruebas/FTP_SD_STM32G4/ioLibrary_Driver-master/Internet/FTPServer" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ioLibrary_Driver-2d-master-2f-Ethernet

clean-ioLibrary_Driver-2d-master-2f-Ethernet:
	-$(RM) ./ioLibrary_Driver-master/Ethernet/socket.cyclo ./ioLibrary_Driver-master/Ethernet/socket.d ./ioLibrary_Driver-master/Ethernet/socket.o ./ioLibrary_Driver-master/Ethernet/socket.su ./ioLibrary_Driver-master/Ethernet/wizchip_conf.cyclo ./ioLibrary_Driver-master/Ethernet/wizchip_conf.d ./ioLibrary_Driver-master/Ethernet/wizchip_conf.o ./ioLibrary_Driver-master/Ethernet/wizchip_conf.su

.PHONY: clean-ioLibrary_Driver-2d-master-2f-Ethernet

