# Vulkan Extension Checker (Windows)

Простая программа для проверки установки Vulkan SDK и доступных расширений на Windows. Идеальный первый шаг перед изучением Vulkan API.

## Что делает?
- Проверяет работоспособность Vulkan SDK
- Выводит количество доступных расширений Vulkan в консоль

## Требования
- [Vulkan SDK](https://vulkan.lunarg.com/) (установленный в `C:\VulkanSDK\`)
- Visual Studio 2022 (Community подойдет)
- Совместимые драйверы GPU (проверьте через `vulkaninfo.exe` из SDK)

## Настройка проекта в Visual Studio
1. Создайте **Empty Project** → C++
2. Добавьте `main.cpp` с кодом из примера
3. В свойствах проекта:
   - **C/C++ → Language → C++ Language Standard**: Установите **C++17** или новее
   - **C/C++ → General → Additional Include Directories**:  
     `C:\VulkanSDK\[версия]\Include`
   - **Linker → General → Additional Library Directories**:  
     `C:\VulkanSDK\[версия]\Lib`
   - **Linker → Input → Additional Dependencies**:  
     Добавьте `vulkan-1.lib`

## Пример вывода
```
20 extensions available
```

## Если выводится "0 extensions"
1. Проверьте путь к SDK в настройках проекта
2. Убедитесь, что драйверы GPU поддерживают Vulkan (скачайте актуальные драйверы)
3. Запустите `vulkaninfo.exe` из папки `C:\VulkanSDK\[версия]\Bin` для диагностики

> **Совет для новичков**:  
> - Замените `[версия]` на актуальную (например, `1.4.309.0`)  
> - Программа не требует создания окна или графического вывода – это чистая проверка окружения  
> - Успешный запуск означает готовность к следующим шагам в изучении Vulkan