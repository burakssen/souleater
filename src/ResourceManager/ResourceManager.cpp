#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
}

ResourceManager &ResourceManager::GetInstance()
{
    static ResourceManager instance;
    return instance;
}

void ResourceManager::LoadResources()
{
    YAML::Node metadata = YAML::LoadFile(m_resourcePath + "/metadata.yaml");

    for (auto entity : metadata)
    {
        Resource resource;
        resource.s_entityName = entity.first.as<std::string>();

        for (auto value : entity.second)
        {
            if (value.first.as<std::string>() == "animations")
            {
                AnimationResource animationResource;
                for (auto animation : value.second)
                {
                    animationResource.s_animationName = animation["name"].as<std::string>();
                    animationResource.s_numberOfFrames = animation["numberOfFrames"].as<int>();
                    animationResource.s_frameDelay = animation["frameDelay"].as<float>();
                    animationResource.s_loop = animation["loop"].as<bool>();
                    std::string texturePath = m_resourcePath + "/" + animation["texture"].as<std::string>() + ".png";
                    animationResource.s_texture = LoadTexture(texturePath.c_str());
                    resource.m_animations.push_back(animationResource);
                }

                continue;
            }

            ResourceValue resourceValue;
            resourceValue.float_value = value.second.as<float>();
            resource.m_values[value.first.as<std::string>()] = resourceValue;
        }

        m_resources[resource.s_entityName] = resource;
    }
}

Resource ResourceManager::GetResource(const std::string &entityName)
{
    return m_resources[entityName];
}
