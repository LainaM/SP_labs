#include <iostream>
#include <list>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const list<T>& items){
    os << "list: ";
    for (const auto& item: items){
        os << item << " ";
    }
    return os;
}

int main() {
	//1. Создать объект-контейнер list и заполнить его данными типа int
	list<int> first;
	for (int i = 0; i < 5; ++i){
		first.push_back(i);
	}

	//2. Просмотреть контейнер.
	cout << "First container: ";
	for (const auto& item: first){
		cout << item << " ";
	}

	//3. Изменить контейнер, удалив из него одни элементы и заменив другие.
	first.remove(4);
	first.push_back(21);

	//4. Просмотреть контейнер, используя для доступа к его элементам итераторы.
	cout << endl << "First container after changing: ";
	for (auto it = begin(first); it != end(first); ++it){
		cout << *it << " ";
	}

	//5. Создать второй контейнер этого же класса и заполнить его данными того же типа, что и первый контейнер.
	list<int> second;
	for (int i = 4; i < 10; ++i){
		second.push_back(i);
	}

	//6. Изменить первый контейнер, удалив из него n элементов после заданного.
	//Добавление всех элементов из второго контейнера.
	first.pop_back();
	    for (const auto& item: second){
	        first.push_back(item);
	}

	//7. Просмотреть первый и второй контейнеры.
	cout << endl << "First container result ";
	cout << first;
	cout << endl << "Second container ";
	cout << second;

	return 0;
}
