#include <iostream>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

class Example{
	public:
		int number;

		Example(const int& n){
			number = n;
		}

		friend bool operator<(const Example& l, const Example& r)
		    {
		        return l.number < r.number;
		    }

};

ostream& operator<<(ostream& os, const Example& obj)
{
	os << obj.number;
	return os;
}

int main() {
	//1. ������� ��������� list, ���������� ������� ����������������� ����.
	list<Example> first;
	first.push_back(Example(5));
	first.push_back(Example(1));
	first.push_back(Example(3));
	first.push_back(Example(8));

	//2. ������������� ��� �� �������� ���������.
	//3. ����������� ���������.
	sort(begin(first), end(first), [](const Example& l, const Example& r){
		return l.number < r.number;
	});

	cout << "First container: ";
	for (const auto& item: first){
			cout << item << " ";
		}

	//4. ��������� ���������� ��������, ����� � ���������� �������, ��������������� ��������� �������.
	/*find_if(begin(first), end(first), [](const Example& number){
			return number < 5;
	});
*/
	//5. ����������� ��������, ��������������� ��������� ������� � ������ (�������������� ������) ��������� set
	//6. ����������� ������ ���������.


	//7. ������������� ������ � ������ ���������� �� ����������� ���������.
	//8. ����������� ��.
	/*sort(begin(first), end (first));
	cout << "First sort container: ";
		for (const auto& item: first){
				cout << item << " ";
			}*/

	//9. �������� ������ ��������� ����� ������� ������ ����.


	//10. ����������� ������ ���������.


	//11 ����������, ������� ���������, ��������������� ��������� �������, �������� ������ ���������.


	//12.����������, ���� �� � ������� ���������� �������, ��������������� ��������� �������.

	return 0;
}
