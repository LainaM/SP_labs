#include <iostream>
#include <list>
#include <iterator>
//#include <algorithm>

using namespace std;

int main() {
	//1. ������� ������-��������� list � ��������� ��� ������� ���� int
	list<int> first;
	for (int i = 0; i < 5; ++i){
		first.push_back(i);
	}

	//2. ����������� ���������.
	cout << "First container: ";
	for (const auto& item: first){
		cout << item << " ";
	}

	//3. �������� ���������, ������ �� ���� ���� �������� � ������� ������.
	first.remove(4);
	first.push_back(21);

	//4. ����������� ���������, ��������� ��� ������� � ��� ��������� ���������.
	cout << endl << "First container after changing: ";
	for (auto it = begin(first); it != end(first); ++it){
			cout << *it << " ";
	}

	//5. ������� ������ ��������� ����� �� ������ � ��������� ��� ������� ���� �� ����, ��� � ������ ���������.
	list<int> second;
	for (int i = 10; i < 15; ++i){
		second.push_back(i);
	}

	//6. �������� ������ ���������, ������ �� ���� n ��������� ����� ���������.
	int n = 4, pos = 1;
	int q = n + pos;
	list<int>::iterator itr1, itr2;
	itr1 = first.begin();
	itr2 = first.begin();
	advance(itr1, pos);
	advance(itr2, q);
	first.erase(itr1, itr2);

	//���������� ���� ��������� �� ������� ����������.
	first.merge(second);

	//7. ����������� ������ � ������ ����������.
	cout << endl << "First container result: ";
	for (const auto& item: first){
			cout << item << " ";
	}

	cout << endl << "Second container after changing: ";

	for (const auto& item: second){
			cout << item << " ";
	}

	return 0;
}

/* � ����������
  for (auto it = begin(first); it != end(first); ++it){
		cout << "\t" << *it << endl;
	}
	copy(first.begin(), first.end(), ostream_iterator<int>(cout, " "));
	*/

