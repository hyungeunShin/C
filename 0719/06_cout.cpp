//cout

#include <stdio.h>

namespace mystd
{
	class ostream
	{
	public:
		ostream& operator<<(int value)
		{
			printf("%d", value);
			return *this;
		}
		ostream& operator<<(char value)
		{
			printf("%c", value);
			return *this;
		}
		ostream& operator<<(const char* value)
		{
			printf("%s", value);
			return *this;
		}
	};

	ostream cout;
};

using mystd::cout;

int main()
{
	cout << 10;		// cout.operator<<(10);

	cout << 10 << 'a' << '\n' << 20 << '\n';
	cout << "hell";
}