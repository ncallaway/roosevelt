#ifndef I_ENTITY_SYSTEM
#define I_ENTITY_SYSTEM

class EntityContainer;

class IEntitySystem {
    public:
        virtual ~IEntitySystem() {}

        virtual void Update(EntityContainer* container /* OTHER ARGS (like dt) here */) = 0;
};

#endif // I_ENTITY_SYSTEM