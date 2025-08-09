#include <vulkan/vulkan.h>  // ���������� ��������� Vulkan
#include <iostream>

int main() {
    uint32_t extensionCount{};    // ���������� ��� ��������� ���������� ����������       
    // �������� ���������� ��������� ���������� Vulkan
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    // ������� ���������
    std::cout << extensionCount << " extensions available\n";

    return 0;
}