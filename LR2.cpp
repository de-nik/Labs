#include <iostream>
#include <string>
class TExh {
private:
	int *Value,
		*Time;
	char **Title;
public:
	TExh(int Number) {
		Title = new char*[Number];
		for (int i = 0; i < Number; i++) Title[i] = new char[20];
		Value = new int[Number];
		Time = new int[Number];
	}
	void Enter(char *c_title, int c_value, int c_time, int i) {
		strcpy_s(Title[i], sizeof(c_title) + 1, c_title);
		Value[i] = c_value;
		Time[i] = c_time;
	}
	void AverageValue(int Number, int Buf) {
		std::cout << std::endl << "The parameters of all exhibits: " << std::endl;
		for (int i = 0; i < Number; i++)
			std::cout << "[" << i + 1 << "] " << "Title = " << Title[i] << " | " << "Value = " << Value[i] << " | " << "Av. Value = " << Value[i] * Time[i] << std::endl;
		std::cout << "------------------------------------------------------" << std::endl << "max ->" << std::endl;
		std::cout << "[" << Buf + 1 << "] " << "Title = " << Title[Buf] << " | " << "Value = " << Value[Buf] << " | " << "Av. Value = " << Value[Buf] * Time[Buf] << std::endl;
	}
	~TExh() {
		delete []Title;
		delete []Value;
		delete []Time;
	}
};
int main() {
	int Value, Number, Time, Buf, Max = 0;
	char Title[20];
	std::cout << "Enter the number of exhibits: " << std::endl;
	std::cin >> Number;
	TExh obj(Number);
	std::cout << "Enter title, value of exhibits and time of exposure: " << std::endl;
	for (int i = 0; i < Number; ++i) {
		std::cout << "[" << i + 1 << "]" << std::endl;
		std::cin >> Title >> Value >> Time;
		obj.Enter(Title, Value, Time, i);
		if (Value * Time > Max) {
			Max = Value * Time;
			Buf = i;
		}
	}
	obj.AverageValue(Number, Buf);
	system("pause");
}
