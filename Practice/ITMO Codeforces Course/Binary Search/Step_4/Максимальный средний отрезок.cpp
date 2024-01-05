// A. Максимальный средний отрезок
// ограничение по времени на тест2 секунды
// ограничение по памяти на тест512 мегабайт
// вводстандартный ввод
// выводстандартный вывод
// Дан массив из n
//  чисел и число d
// . Требуется найти отрезок массива длины не менее d
// , на котором среднее арифметическое элементов максимально.

// Входные данные
// Первая строка содержит два целых числа n
//  и d
//  (1≤d≤n≤105
// ). Следующая строка содержит n
//  чисел ai
//  — элементы массива (0≤ai≤100
// ).

// Выходные данные
// Выведите два числа — номера первого и последнего элемента требуемого отрезка (элементы нумеруются с 1).

// Пример
// входные данныеСкопировать
// 6 2
// 3 1 8 5 7 2
// выходные данныеСкопировать
// 3 5


#include <bits/stdc++.h>
using namespace std;

int n, d;
vector<int> a;

// Используя бинарный поиск, пытаемся найти то самое максимальное средн. арифметическое.
// Пусть x - current value в бин поиске.
// sum[l -> r](ai) / (r - l) >= x
// Переносим (r - l). Вычитаем из обоих частей (r - l) * x 
// (аl-x) + (a(l+1)-x) + ... (ar - x) >= 0
// Заменяем на префиксные суммы - p[r] - p[l] >= 0
// Используй минимум префиксных сумм, чтобы сократить время работы алгоритма

bool okay(double mid) {

	vector<double> a_x;
	for (int i = 0; i < n; i++) {
		a_x.push_back(a[i] - mid);
	}

	vector<double> prefix(n+1);
	for (int i = 1; i <= n; i++) {
		prefix[i] = prefix[i-1] + a_x[i-1];
	}
	
	vector<double> min_prefix(n+1);
	// этот вектор нужен, чтобы вытащить левую границу отрезка
	vector<int> min_prefix_idx(n+1);
	for (int i = d; i <= n; i++) {
		if (min_prefix[i-1] <= prefix[i-d]) {
			min_prefix_idx[i] = min_prefix_idx[i-1]; 
		} else {
			min_prefix_idx[i] = i-d;
		}

		min_prefix[i] = min(min_prefix[i-1], prefix[i-d]);
	}


	for (int i = 1; i <= n; i++) {
		// первое условние идентично >= 0, просто здесь тип double)
			if (((prefix[i] - min_prefix[i]) >= -1e-6) && ((i-min_prefix_idx[i]) >= d)) {
			return true;
		}
	}

	return false;
}

vector<int> func_for_returning_indexies(double mid) {
	vector<double> a_x;
	for (int i = 0; i < n; i++) {
		a_x.push_back(a[i] - mid);
	}

	vector<double> prefix(n+1);
	for (int i = 1; i <= n; i++) {
		prefix[i] = prefix[i-1] + a_x[i-1];
	}
	
	vector<double> min_prefix(n+1);
	vector<int> min_prefix_idx(n+1);
	for (int i = d; i <= n; i++) {
		if (min_prefix[i-1] <= prefix[i-d]) {
			min_prefix_idx[i] = min_prefix_idx[i-1]; 
		} else {
			min_prefix_idx[i] = i-d;
		}

		min_prefix[i] = min(min_prefix[i-1], prefix[i-d]);
	}

	for (int i = 1; i <= n; i++) {
			if (((prefix[i] - min_prefix[i]) >= -1e-6) && ((i-min_prefix_idx[i]) >= d)) {
			int start = min_prefix_idx[i]+1;
			int end = i;
			return vector<int>{start, end};
		}
	}
}



int main() {

	freopen("input", "rt", stdin);
	freopen("output", "wt", stdout);
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}

	
	double l = 0, r = 10e5;

	for (int i = 0; i < 50; i++) {

		double mid = (r + l) * 0.5;

		if (okay(mid)) {
			l = mid;
		} else {
			r = mid;
		}


	}
	vector<int> res = func_for_returning_indexies(l);

	cout << res[0] << " " << res[1];

}

