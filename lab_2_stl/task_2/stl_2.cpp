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
	//1. Создать контейнер list, содержащий объекты пользовательского типа.
	list<Example> first;
	first.push_back(Example(5));
	first.push_back(Example(1));
	first.push_back(Example(3));
	first.push_back(Example(8));

	//2. Отсортировать его по убыванию элементов.
	//3. Просмотреть контейнер.
	sort(begin(first), end(first), [](const Example& l, const Example& r){
		return l.number < r.number;
	});

	cout << "First container: ";
	for (const auto& item: first){
			cout << item << " ";
		}

	//4. Используя подходящий алгоритм, найти в контейнере элемент, удовлетворяющий заданному условию.
	/*find_if(begin(first), end(first), [](const Example& number){
			return number < 5;
	});
*/
	//5. Переместить элементы, удовлетворяющие заданному условию в другой (предварительно пустой) контейнер set
	//6. Просмотреть второй контейнер.


	//7. Отсортировать первый и второй контейнеры по возрастанию элементов.
	//8. Просмотреть их.
	/*sort(begin(first), end (first));
	cout << "First sort container: ";
		for (const auto& item: first){
				cout << item << " ";
			}*/

	//9. Получить третий контейнер путем слияния первых двух.


	//10. Просмотреть третий контейнер.


	//11 Подсчитать, сколько элементов, удовлетворяющих заданному условию, содержит третий контейнер.


	//12.Определить, есть ли в третьем контейнере элемент, удовлетворяющий заданному условию.

	return 0;
}
