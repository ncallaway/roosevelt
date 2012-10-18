#include <set>

class Entity;

class EntityContainer {
    public:
        bool AddEntity(Entity* entity);

        bool RemoveEntity(Entity* entity);

        bool HasEntity(Entity* entity);

        std::set<Entity*> Query();

    private:
        std::set<Entity*> m_entities;
};