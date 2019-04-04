#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

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
	//1. Создать контейнер list, содержащий объекты пользовательского типа.
	list<Example> first;
	first.push_back(Example(5));
	first.push_back(Example(1));
	first.push_back(Example(3));
	first.push_back(Example(8));

	//2. Отсортировать его по убыванию элементов.
	//3. Просмотреть контейнер.
	first.sort([](const Example& l, const Example& r){
		return l.number > r.number;
	});

	cout << "First container: ";
	for (const auto& item: first){
			cout << item << " ";
		}

	//4. Используя подходящий алгоритм, найти в контейнере элемент, удовлетворяющий заданному условию.
	auto result = find_if(begin(first), end(first), [](const Example& number){
			return number < 5;
	});
	cout << endl << "Element less than five: ";
	if (result == end(first)){
		cout << "not found";
	} else cout << *result << endl;

	//5. Переместить элементы, удовлетворяющие заданному условию в другой (предварительно пустой) контейнер
	//6. Просмотреть второй контейнер.
	list<Example> second;
	copy_if(begin(first), end(first), back_inserter(second), [](const Example& number){
		return number < 5;
	});

	cout << "Second container: ";
	for (const auto& item: second){
		cout << item << " ";
	}

	//7. Отсортировать первый и второй контейнеры по возрастанию элементов.
	//8. Просмотреть их.
	first.sort();
	cout << endl << "First sort container: ";
	for (const auto& item: first){
		cout << item << " ";
	}

	second.sort();
	cout << endl << "Second sort container: ";
	for (const auto& item: second){
		cout << item << " ";
	}

	//9. Получить третий контейнер путем слияния первых двух.
	//10. Просмотреть третий контейнер.
	list<Example> third;
	merge(begin(first), end(first), begin(second), end(second), back_inserter(third));
	cout << endl << "Third container: ";
	for (const auto& item: third){
		cout << item << " ";
	}

	//11 Подсчитать, сколько элементов, удовлетворяющих заданному условию, содержит третий контейнер.
	auto count = count_if(begin(third), end(third), [](const Example& number){
		return number < 3;
	});
	cout << endl << "Quantity elements less than three: " << count;

	//12.Определить, есть ли в третьем контейнере элемент, удовлетворяющий заданному условию.
	cout << endl << "Element less than three: ";
	auto less3 = find_if(begin(third), end(third), [](const Example& number){
				return number < 3;
		});

		if (less3 == end(third)){
			cout << "No";
		} else cout << "Yes";

	return 0;
}
