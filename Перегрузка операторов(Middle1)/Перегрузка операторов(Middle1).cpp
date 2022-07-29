#include <iostream>

class Vector
{
public:
	Vector(float a, float b, float c)
	{
		x = a;
		y = b;
		z = c;
	}

	Vector()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	friend Vector operator*(const Vector& a, const float b);
	friend Vector operator-(const Vector& a, const Vector& b);
	friend std::ostream& operator<<(std::ostream& out, const Vector& a);
	friend std::istream& operator>>(std::istream& in, Vector& a);

private:
	float x;
	float y;
	float z;
};

Vector operator*(const Vector& a, const float b)
{
	return Vector(a.x * b, a.y * b, a.z * b);
}

Vector operator-(const Vector& a, const Vector& b)
{
	return Vector(a.x - b.x, a.y - b.y, a.z - b.z);
}

std::ostream& operator<<(std::ostream& out, const Vector& a)
{
	out << ' ' << a.x << ' ' << a.y << ' ' << a.z;
	return out;
}

std::istream& operator>>(std::istream& in, Vector& a)
{
	in >> a.x;
	in >> a.y;
	in >> a.z;

	return in;
}

int main()
{
	Vector V1(1, 2, 3);
	Vector V2(5, 1, 3);
	Vector V3(1,1,1);
	float a = 3;
	std::cout << V1 * a;
	std::cout << V1 - V2;
	std::cin >> V3;
	std::cout << V3;
}