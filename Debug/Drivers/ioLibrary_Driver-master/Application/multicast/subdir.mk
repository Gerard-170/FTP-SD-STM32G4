################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/ioLibrary_Driver-master/Application/multicast/multicast.c 

OBJS += \
./Drivers/ioLibrary_Driver-master/Application/multicast/multicast.o 

C_DEPS += \
./Drivers/ioLibrary_Driver-master/Application/multicast/multicast.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/ioLibrary_Driver-master/Application/multicast/%.o Drivers/ioLibrary_Driver-master/Application/multicast/%.su Drivers/ioLibrary_Driver-master/Application/multicast/%.cyclo: ../Drivers/ioLibrary_Driver-master/Application/multicast/%.c Drivers/ioLibrary_Driver-master/Application/multicast/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32G474xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32G4xx_Nucleo -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"C:/Users/pc/Documents/STM32_Pruebas/FTP_SD_STM32G4/Drivers/ioLibrary_Driver-master/Ethernet" -I"C:/Users/pc/Documents/STM32_Pruebas/FTP_SD_STM32G4/Drivers/ioLibrary_Driver-master/Ethernet/W5500" -I"C:/Users/pc/Documents/STM32_Pruebas/FTP_SD_STM32G4/Drivers/ioLibrary_Driver-master/Internet/FTPServer" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-ioLibrary_Driver-2d-master-2f-Application-2f-multicast

clean-Drivers-2f-ioLibrary_Driver-2d-master-2f-Application-2f-multicast:
	-$(RM) ./Drivers/ioLibrary_Driver-master/Application/multicast/multicast.cyclo ./Drivers/ioLibrary_Driver-master/Application/multicast/multicast.d ./Drivers/ioLibrary_Driver-master/Application/multicast/multicast.o ./Drivers/ioLibrary_Driver-master/Application/multicast/multicast.su

.PHONY: clean-Drivers-2f-ioLibrary_Driver-2d-master-2f-Application-2f-multicast

