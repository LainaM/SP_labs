#include <iostream>
#include <list>
#include <iterator>
//#include <algorithm>

using namespace std;

int main() {
	//1. Создать объект-контейнер list и заполнить его данными типа int
	list<int> first;
	for (int i = 0; i < 5; ++i){
		first.push_back(i);
	}

	//2. Просмотреть контейнер.
	cout << "First container: ";
	copy(first.begin(), first.end(), ostream_iterator<int>(cout, " "));

	//3. Изменить контейнер, удалив из него одни элементы и заменив другие.
	first.remove(4);
	first.push_back(21);

	//4. Просмотреть контейнер, используя для доступа к его элементам итераторы.
	cout << endl << "First container after changing: ";
	copy(first.begin(), first.end(), ostream_iterator<int>(cout, " "));

	//5. Создать второй контейнер этого же класса и заполнить его данными того же типа, что и первый контейнер.
	list<int> second;
	for (int i = 10; i < 15; ++i){
		second.push_back(i);
	}

	//6. Изменить первый контейнер, удалив из него n элементов после заданного.
	int n = 4, pos = 1;
	int q = n + pos;
	list<int>::iterator itr1, itr2;
	itr1 = first.begin();
	itr2 = first.begin();
	advance(itr1, pos);
	advance(itr2, q);
	first.erase(itr1, itr2);

	//Добавление всех элементов из второго контейнера.
	first.merge(second);

	//7. Просмотреть первый и второй контейнеры.
	cout << endl << "First container result: ";
	copy(first.begin(), first.end(), ostream_iterator<int>(cout, " "));
	cout << endl << "Second container after changing: ";
	copy(second.begin(), second.end(), ostream_iterator<int>(cout, " "));
	return 0;
}
