#include <vector>
#include <string>

using namespace std;

class ingredient {

private:
	string name;

public:
	ingredient();
	ingredient(string inputName);
	bool operator==(const ingredient& rhs);
	~ingredient();
};