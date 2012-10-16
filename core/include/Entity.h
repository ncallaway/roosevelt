#include <string>

class Entity {
public:
	void set_id(std::string id);
	std::string get_id();
private:
	std::string m_id;
};