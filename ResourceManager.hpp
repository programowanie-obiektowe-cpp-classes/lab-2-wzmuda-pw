pragma once

#include "Resource.hpp"

#include <memory>
#include <stdexcept>

class ResourceManager
{
public:
    ResourceManager()
        : resource(std::make_unique<Resource>())
    {}

    ~ResourceManager() = default;

    ResourceManager(const ResourceManager& other)
        : resource(other.resource ? std::make_unique<Resource>(*other.resource) : nullptr)
    {}

    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            resource = other.resource ? std::make_unique<Resource>(*other.resource) : nullptr;
        }
        return *this;
    }

    double get()
    {
        if (!resource) {
            throw std::runtime_error("ResourceManager: no resource");
        }
        return resource->get();
    }

private:
    std::unique_ptr<Resource> resource;
};
