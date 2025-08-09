#include <vulkan/vulkan.h>  // подключаем библиотеку Vulkan
#include <iostream>

int main() {
    VkInstance instance; // объект, который надо создать

    // устанавливаем информацию о приложении
    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Ren's Vulkan App";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    // создаем объект VkInstance
    VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
    // если не удалось создать объект VKInstance
    if (result != VK_SUCCESS) {
        std::cout << "Unable to create VKInstance" << std::endl;
        return 1;
    }
    // для теста выводим название приложения и его версию
    std::cout << appInfo.pApplicationName << std::endl;
    std::cout << appInfo.applicationVersion << std::endl;  // 4194304 или 10000000000000000000000

    // удаление VKInstance
    vkDestroyInstance(instance, nullptr);

    return 0;
}
