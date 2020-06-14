#include "Topping.h"

// Union constructor of fields and default constructor
Topping::Topping(const char* name, char coverege, float price)
{
	setName(name);
	setCoverege(coverege);
	setPrice(price);
}

// Copy constructor
Topping::Topping(const Topping& other)
{
	*this = other;
}

// Destructor
Topping::~Topping()
{
	delete[] name;
}

void Topping::setName(const char* name)
{
	if (name != nullptr)
	{
	//	 if(this->name != nullptr)
	//		delete[] this->name;
		int size = strlen(name) + 1;
		this->name = new char[size];
		assert(this->name);
		strcpy_s(this->name, size, name);
	}
}

void Topping::setCoverege(const char coverege)
{
	if (coverege != 'r' && coverege != 'l' && coverege != 'f')
	{
		cout << "coverege not valid. set to 'f'" << endl;
		this->coverege = 'f';
	}
	else
		this->coverege = coverege;
}

void Topping::setPrice(const float price)
{
	if (price <= 0) {
		cout << "Price not valid. set to 10." << endl;
		this->price = 10;
	}else
			this->price = price;
}

char Topping::getCoverege() const
{
	return this->coverege;
}

float Topping::getPrice() const
{
		return this->price;
}

float Topping::getCalcPrice() const
{
	if (this->coverege != 'f')
		return 0.5 * this->price;
	else
		return this->price;
}

Topping& Topping::operator=(const Topping& other)
{
	if (this != &other) {
		setName(other.name);
		this->coverege = other.coverege;
		this->price = other.price;
	}
	return *this;
}

// Load operator << to print all Topping fields (print the calcPrice of Topping. depends on coverege).
ostream& operator<<(ostream& output, const Topping& other)
{
	return output << "Topping: \nname: " << other.name << ", coverage: "
		<< other.coverege << ", price: " << other.getCalcPrice() << endl;
}

// Load Operator < to compare prices of 2 Toppings
bool Topping::operator<(const Topping& other) const
{
	return (this->price < other.price);
}

// Load Operator > to compare prices of 2 Toppings
bool Topping::operator>(const Topping& other) const
{
	return (this->price > other.price);
}

// Load operator == to compare 2 extras by type of cover
bool Topping::operator==(const Topping& other) const
{
	return (this->coverege == other.coverege);
}

