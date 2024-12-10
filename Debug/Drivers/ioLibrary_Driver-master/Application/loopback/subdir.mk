################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/ioLibrary_Driver-master/Application/loopback/loopback.c 

OBJS += \
./Drivers/ioLibrary_Driver-master/Application/loopback/loopback.o 

C_DEPS += \
./Drivers/ioLibrary_Driver-master/Application/loopback/loopback.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/ioLibrary_Driver-master/Application/loopback/%.o Drivers/ioLibrary_Driver-master/Application/loopback/%.su Drivers/ioLibrary_Driver-master/Application/loopback/%.cyclo: ../Drivers/ioLibrary_Driver-master/Application/loopback/%.c Drivers/ioLibrary_Driver-master/Application/loopback/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32G4xx_Nucleo -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"C:/Users/pc/Documents/STM32_Pruebas/FTP_SD_STM32G4/Drivers/ioLibrary_Driver-master/Ethernet" -I"C:/Users/pc/Documents/STM32_Pruebas/FTP_SD_STM32G4/Drivers/ioLibrary_Driver-master/Ethernet/W5500" -I"C:/Users/pc/Documents/STM32_Pruebas/FTP_SD_STM32G4/Drivers/ioLibrary_Driver-master/Internet/FTPServer" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-ioLibrary_Driver-2d-master-2f-Application-2f-loopback

clean-Drivers-2f-ioLibrary_Driver-2d-master-2f-Application-2f-loopback:
	-$(RM) ./Drivers/ioLibrary_Driver-master/Application/loopback/loopback.cyclo ./Drivers/ioLibrary_Driver-master/Application/loopback/loopback.d ./Drivers/ioLibrary_Driver-master/Application/loopback/loopback.o ./Drivers/ioLibrary_Driver-master/Application/loopback/loopback.su

.PHONY: clean-Drivers-2f-ioLibrary_Driver-2d-master-2f-Application-2f-loopback

