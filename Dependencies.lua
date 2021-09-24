
-- Elys Dependencies

VULKAN_SDK = os.getenv("VULKAN_SDK")

IncludeDir = {}
IncludeDir["stb_image"] = "%{wks.location}/Elys/vendor/stb_image"
IncludeDir["yaml_cpp"] = "%{wks.location}/Elys/vendor/yaml-cpp/include"
IncludeDir["Box2D"] = "%{wks.location}/Elys/vendor/Box2D/include"
IncludeDir["GLFW"] = "%{wks.location}/Elys/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Elys/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Elys/vendor/ImGui"
IncludeDir["ImGuizmo"] = "%{wks.location}/Elys/vendor/ImGuizmo"
IncludeDir["glm"] = "%{wks.location}/Elys/vendor/glm"
IncludeDir["entt"] = "%{wks.location}/Elys/vendor/entt/include"
IncludeDir["shaderc"] = "%{wks.location}/Elys/vendor/shaderc/include"
IncludeDir["SPIRV_Cross"] = "%{wks.location}/Elys/vendor/SPIRV-Cross"
IncludeDir["VulkanSDK"] = "%{VULKAN_SDK}/Include"

LibraryDir = {}

LibraryDir["VulkanSDK"] = "%{VULKAN_SDK}/Lib"
LibraryDir["VulkanSDK_Debug"] = "%{wks.location}/Elys/vendor/VulkanSDK/Lib"
LibraryDir["VulkanSDK_DebugDLL"] = "%{wks.location}/Elys/vendor/VulkanSDK/Bin"

Library = {}
Library["Vulkan"] = "%{LibraryDir.VulkanSDK}/vulkan-1.lib"
Library["VulkanUtils"] = "%{LibraryDir.VulkanSDK}/VkLayer_utils.lib"

Library["ShaderC_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/shaderc_sharedd.lib"
Library["SPIRV_Cross_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/spirv-cross-cored.lib"
Library["SPIRV_Cross_GLSL_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/spirv-cross-glsld.lib"
Library["SPIRV_Tools_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/SPIRV-Toolsd.lib"

Library["ShaderC_Release"] = "%{LibraryDir.VulkanSDK}/shaderc_shared.lib"
Library["SPIRV_Cross_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-core.lib"
Library["SPIRV_Cross_GLSL_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-glsl.lib"
