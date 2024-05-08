#include "BST.h"
#include <iomanip>

extern list<Car> listCar;


BST::BST()
{
	root = NULL;
}

BST::~BST()
{
}

void BST::insert(Car& car)
{
	if (root != NULL)
	{
		insertHelper(car, root);
	}
	else
	{
		root = new Node(car);
		root->rightNode = NULL;
		root->leftNode = NULL;
	}
	index++;
}

// serach following personal key because inserting also follow personal key
Node* BST::search(const string& pK)
{
	return searchHelper(pK, root);
}

void BST::leftNodeRight(int choice, int size)
{
	leftToRightHelper(root, choice, size);
}

void BST::addEleToSave()
{
	addToSaveHelper(root);
}

void BST::searchByName(string& name)
{
	vector<Node*> nameArr = searchByNameHelper(name, root);
	for (size_t i = 0; i < nameArr.size(); i++)
	{
		// thông tin chung
		cout << setw(5) << i + 1 << setw(20) << "Owner name" << setw(25) << "Email" << setw(15) << "Key number"
			<< setw(15) << "ODO number" << setw(25) << "Remind service (km)" << endl;
		cout << setw(5) << "" << setw(20) << nameArr[i]->data.getCarName() << setw(25) << nameArr[i]->data.getEmail()
			<< setw(15) << nameArr[i]->data.getPersonalKey() << setw(15) << nameArr[i]->data.getODO()
			<< setw(25) << nameArr[i]->data.getServiceRemind() << endl;

		// thông tin display
		cout << setw(5) << "" << setw(15) << "Display: " << setw(10) << "Light" << setw(20) << "Screen light"
			<< setw(20) << "Taplo light" << endl;
		cout << setw(20) << "" << setw(10) << nameArr[i]->data.getDisplay()->get_light_level()
			<< setw(20) << nameArr[i]->data.getDisplay()->get_screen_light_level()
			<< setw(20) << nameArr[i]->data.getDisplay()->get_taplo_light_level() << endl;

		// thông tin sound
		cout << setw(5) << "" << setw(15) << "Sound: " << setw(10) << "Media" << setw(10) << "Call"
			<< setw(15) << "Navigation" << setw(15) << "Notification" << endl;
		cout << setw(20) << "" << setw(10) << nameArr[i]->data.getSound()->get_media_level()
			<< setw(10) << nameArr[i]->data.getSound()->get_call_level()
			<< setw(15) << nameArr[i]->data.getSound()->get_navi_level()
			<< setw(15) << nameArr[i]->data.getSound()->get_notification_level() << endl;

		// Thông tin general
		cout << setw(5) << "" << setw(15) << "General: " << setw(20) << "Timezone" << setw(20) << "Language" << endl;
		cout << setw(20) << "" << setw(20) << nameArr[i]->data.getGeneral()->get_timeZone()
			<< setw(20) << nameArr[i]->data.getGeneral()->get_language() << endl;
	}
}

void BST::searchByKey(string& key)
{
	searchByKeyHelper(key, root);
}

void BST::insertHelper(Car& car, Node* aNode)
{
	if (car.getPersonalKey() < aNode->data.getPersonalKey())
	{
		if (aNode->leftNode != NULL) {
			insertHelper(car, aNode->leftNode);
		}
		else
		{
			aNode->leftNode = new Node(car);
			aNode->leftNode->leftNode = NULL;
			aNode->leftNode->rightNode = NULL;
		}
	}
	else if (car.getPersonalKey() > aNode->data.getPersonalKey())
	{
		if (aNode->rightNode != NULL) {
			insertHelper(car, aNode->rightNode);
		}
		else
		{
			aNode->rightNode = new Node(car);
			aNode->rightNode->leftNode = NULL;
			aNode->rightNode->rightNode = NULL;
		}
	}
}

Node* BST::searchHelper(const string& perKey, Node* aNode)
{

	if (aNode != NULL)
	{
		if (perKey == aNode->data.getPersonalKey()) {
			return aNode;
		}
		else if (perKey < aNode->data.getPersonalKey()) {
			return searchHelper(perKey, aNode->leftNode);
		}
		else
		{
			return searchHelper(perKey, aNode->rightNode);
		}
	}
	else
		return nullptr;


}

// with name of the owner it can be the same
// so we need to go through all of nodes
vector<Node*> BST::searchByNameHelper(string& name, Node* aNode)
{
	vector<Node*> result;
	if (aNode != NULL)
	{
		// go through left sub tree
		vector<Node*> leftResult = searchByNameHelper(name, aNode->leftNode);

		// add element to result
		result.insert(result.end(), leftResult.begin(), leftResult.end());

		// compare to name of this node to add to vector
		if (name == aNode->data.getCarName())
		{
			result.push_back(aNode);
		}

		// go through right sub tree
		vector<Node*> rightResult = searchByNameHelper(name, aNode->rightNode);
		result.insert(result.end(), rightResult.begin(), rightResult.end());
		
	}

	return result;
}

void BST::searchByKeyHelper(string& key, Node* aNode)
{

	if (aNode != NULL) {

		if (key == aNode->data.getPersonalKey())
		{
			// thông tin chung
			cout << setw(5) << 1 << setw(20) << "Owner name" << setw(25) << "Email" << setw(15) << "Key number"
				<< setw(15) << "ODO number" << setw(25) << "Remind service (km)" << endl;
			cout << setw(5) << "" << setw(20) << aNode->data.getCarName() << setw(25) << aNode->data.getEmail()
				<< setw(15) << aNode->data.getPersonalKey() << setw(15) << aNode->data.getODO()
				<< setw(25) << aNode->data.getServiceRemind() << endl;

			// thông tin display
			cout << setw(5) << "" << setw(15) << "Display: " << setw(10) << "Light" << setw(20) << "Screen light"
				<< setw(20) << "Taplo light" << endl;
			cout << setw(20) << "" << setw(10) << aNode->data.getDisplay()->get_light_level()
				<< setw(20) << aNode->data.getDisplay()->get_screen_light_level()
				<< setw(20) << aNode->data.getDisplay()->get_taplo_light_level() << endl;

			// thông tin sound
			cout << setw(5) << "" << setw(15) << "Sound: " << setw(10) << "Media" << setw(10) << "Call"
				<< setw(15) << "Navigation" << setw(15) << "Notification" << endl;
			cout << setw(20) << "" << setw(10) << aNode->data.getSound()->get_media_level()
				<< setw(10) << aNode->data.getSound()->get_call_level()
				<< setw(15) << aNode->data.getSound()->get_navi_level()
				<< setw(15) << aNode->data.getSound()->get_notification_level() << endl;

			// Thông tin general
			cout << setw(5) << "" << setw(15) << "General: " << setw(20) << "Timezone" << setw(20) << "Language" << endl;
			cout << setw(20) << "" << setw(20) << aNode->data.getGeneral()->get_timeZone()
				<< setw(20) << aNode->data.getGeneral()->get_language() << endl;
		}

		else if (key > aNode->data.getPersonalKey())
		{
			searchByKeyHelper(key, aNode->rightNode);
		}
		else
		{
			searchByKeyHelper(key, aNode->leftNode);
		}
	}
		
}




void BST::leftToRightHelper(Node* aNode, int choice, int& size)
{
	if (aNode != NULL)
	{
		if (choice == 1)		// display 
		{
			leftToRightHelper(aNode->leftNode, 1, size);
			cout << setw(5) << size + 1 << setw(20) << aNode->data.getCarName() << setw(25) << aNode->data.getEmail()
				<< setw(15) << aNode->data.getPersonalKey() << setw(15) << aNode->data.getODO()
				<< setw(25) << aNode->data.getServiceRemind() << endl
				<< setw(5) << "" << setw(20) << aNode->data.getDisplay()->get_light_level()
				<< setw(25) << aNode->data.getDisplay()->get_screen_light_level()
				<< setw(20) << aNode->data.getDisplay()->get_taplo_light_level() << endl;
			size++;
			leftToRightHelper(aNode->rightNode, 1, size);
		}
		else if (choice == 2 )
		{
			leftToRightHelper(aNode->leftNode, size, size);
			cout << setw(5) << size + 1 << setw(20) << aNode->data.getCarName() << setw(25) << aNode->data.getEmail()
				<< setw(15) << aNode->data.getPersonalKey() << setw(15) << aNode->data.getODO()
				<< setw(25) << aNode->data.getServiceRemind() << endl
				<< setw(5) << "" << setw(10) << aNode->data.getSound()->get_media_level()
				<< setw(10) << aNode->data.getSound()->get_call_level()
				<< setw(15) << aNode->data.getSound()->get_navi_level()
				<< setw(15) << aNode->data.getSound()->get_notification_level() << endl;
			size++;
			leftToRightHelper(aNode->rightNode, 2, size);
		}
		else
		{
			leftToRightHelper(aNode->leftNode, 3, size);
			cout << setw(5) << size + 1 << setw(20) << aNode->data.getCarName() << setw(25) << aNode->data.getEmail()
				<< setw(15) << aNode->data.getPersonalKey() << setw(15) << aNode->data.getODO()
				<< setw(25) << aNode->data.getServiceRemind() << endl
				<< setw(5) << "" << setw(20) << aNode->data.getGeneral()->get_timeZone()
				<< setw(15) << aNode->data.getGeneral()->get_language() << endl;
			size++;
			leftToRightHelper(aNode->rightNode, 3, size);
		}
	}
	
}

void BST::addToSaveHelper(Node* aNode)
{
	if (aNode != NULL)
	{
		addToSaveHelper(aNode->leftNode);
		listCar.push_back(aNode->data);
		addToSaveHelper(aNode->rightNode);
	}
}
