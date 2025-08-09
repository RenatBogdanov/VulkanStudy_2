# VkInstance

## Основные понятия
- **VkInstance** - отправная точка для любого приложения Vulkan
- Представляет связь между приложением и библиотекой Vulkan
- Обязательный первый шаг при работе с Vulkan API

## Создание VkInstance

### Функция создания
```cpp
VkResult vkCreateInstance(
    const VkInstanceCreateInfo* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkInstance* pInstance);
```
- При успехе возвращает `VK_SUCCESS`
- `pAllocator` обычно `nullptr` (стандартный аллокатор)

### Структура VkInstanceCreateInfo
```cpp
typedef struct VkInstanceCreateInfo {
    VkStructureType sType;                  // VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO
    const void* pNext;                      // Расширения (обычно nullptr)
    VkInstanceCreateFlags flags;            // Флаги создания
    const VkApplicationInfo* pApplicationInfo; // Информация о приложении
    uint32_t enabledLayerCount;             // Количество слоев
    const char* const* ppEnabledLayerNames; // Имена слоев
    uint32_t enabledExtensionCount;         // Количество расширений
    const char* const* ppEnabledExtensionNames; // Имена расширений
} VkInstanceCreateInfo;
```

### Минимальный пример создания
```cpp
VkInstance instance;
VkInstanceCreateInfo createInfo{};
createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
createInfo.enabledLayerCount = 0; // Без слоев

VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
if(result != VK_SUCCESS) {
    // Обработка ошибки
}
```

## Удаление VkInstance
```cpp
vkDestroyInstance(instance, nullptr);
```
- **Важно**: Удалять только перед завершением программы
- Все остальные ресурсы Vulkan должны быть освобождены ДО удаления VkInstance

## VkApplicationInfo (опционально, но рекомендуется)

### Структура
```cpp
typedef struct VkApplicationInfo {
    VkStructureType sType;
    const void* pNext;
    const char* pApplicationName;
    uint32_t applicationVersion;
    const char* pEngineName;
    uint32_t engineVersion;
    uint32_t apiVersion;
} VkApplicationInfo;
```

### Пример использования
```cpp
VkApplicationInfo appInfo = {};
appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
appInfo.pApplicationName = "My Vulkan App";
appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
appInfo.pEngineName = "No Engine";
appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
appInfo.apiVersion = VK_API_VERSION_1_0;

VkInstanceCreateInfo createInfo{};
createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
createInfo.pApplicationInfo = &appInfo;
```

## Важные замечания
1. `VK_MAKE_VERSION(major, minor, patch)` - макрос для создания версии
2. Версия API указывает, какую версию Vulkan будет использовать приложение
3. Информация в VkApplicationInfo помогает драйверу оптимизировать работу
4. Для получения списка доступных расширений можно использовать `vkEnumerateInstanceExtensionProperties`
5. Для получения списка доступных слоев можно использовать `vkEnumerateInstanceLayerProperties`

> **Совет**: Всегда проверяйте результат вызова `vkCreateInstance` и обрабатывайте возможные ошибки.
