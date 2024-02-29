#pragma once

#include <map>
#include <string>
#include <iostream>

#include <yaml-cpp/yaml.h>

#include "Resource.h"

class ResourceManager
{
    ResourceManager();

public:
    ~ResourceManager();
    static ResourceManager &GetInstance();

    void LoadResources();
    Resource GetResource(const std::string &entityName);

private:
    std::string m_resourcePath = "resources";
    std::map<std::string, Resource> m_resources;
};