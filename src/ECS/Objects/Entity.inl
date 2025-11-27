#pragma once

// Реализация AddComponent - создаёт компонент и возвращает ссылку
template <typename T, typename... Args>
T& Entity::AddComponent(Args... args)
{
    T* componentPtr = new T(args...);
    components.push_back(componentPtr);
    return *componentPtr;
}

template <typename T>
T* Entity::GetComponent()
{
    for (Component *componentPtr : components)
    {
        if (componentPtr == nullptr) continue;
        
        if (T *casted = dynamic_cast<T *>(componentPtr))
        {
            return casted;
        }
    }
    return nullptr;
}
