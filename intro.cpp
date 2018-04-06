int add(int param1, int param2) {
	return param1 + param2;
}

int centuryFromYear(int year) {
	return year % 100 == 0 ? year / 100 : year / 100 + 1;
}

bool checkPalindrome(std::string inputString) {
	for (size_t i = 0; i < inputString.size(); i++)
	{
		if (inputString[i] != inputString[inputString.size() - 1 - i])
			return false;
	}
	return true;
}

int adjacentElementsProduct(std::vector<int> inputArray) {
	int result = inputArray[0] * inputArray[1];
	for (size_t i = 0; i < inputArray.size() - 1; i++)
	{
		if (inputArray[i] * inputArray[i + 1] > result)
			result = inputArray[i] * inputArray[i + 1];
	}
	return result;
}

int shapeArea(int n) {
	if (n == 1)
		return n;

	n = n * 2 - 1;
	int shapes = n;
	do
	{
		n -= 2;
		shapes += n * 2;
	} while (n>1);
	return shapes;
}

int makeArrayConsecutive2(std::vector<int> statues) {
	int min = statues[0];
	int max = statues[0];

	for (size_t i = 0; i < statues.size(); i++)
	{
		if (statues[i] > max)
			max = statues[i];
		if (statues[i] < min)
			min = statues[i];
	}

	return (max - min + 1) - statues.size();
}

bool almostIncreasingSequence(std::vector<int> sequence) {
	int step = 0;
	for (size_t i = 0; i < sequence.size() - 1; i++)
	{
		if (step > 1)
			return false;

		if (sequence[i] >= sequence[i + 1])
		{
			if (i == sequence.size() - 2)
			{
				step++;
				break;
			}
			else if (i == 0)
			{
				step++;
				continue;
			}

			if (sequence[i] < sequence[i + 2])
			{
				i++;
				step++;
			}
			else if (sequence[i - 1] < sequence[i + 1])
				step++;
			else
				return false;
		}
	}
	return step > 1 ? false : true;
}

int matrixElementsSum(std::vector<std::vector<int>> matrix) {
	int price = 0;
	for (size_t x = 0; x < matrix[0].size(); x++)
	{
		for (size_t y = 0; y < matrix.size(); y++)
		{
			if (matrix[y][x] == 0)
				break;
			else
				price += matrix[y][x];
		}
	}
	return price;
}

std::vector<std::string> allLongestStrings(std::vector<std::string> inputArray) {
	int size = 0;

	for (size_t i = 0; i < inputArray.size(); i++)
		if (inputArray[i].size() > size)
			size = inputArray[i].size();

	std::vector<string>result;

	for (size_t i = 0; i < inputArray.size(); i++)
		if (inputArray[i].size() == size)
			result.push_back(inputArray[i]);

	return result;
}

int commonCharacterCount(std::string s1, std::string s2) {
	int r = 0;
	char a = '0';
	int size = s1.size() > s2.size() ? s1.size() : s2.size();

	for (size_t i = 0; i < s1.size(); i++)
	{
		if (s1[i] == a || s1[i] == '0')
			continue;
		else
			a = s1[i];
		int s1c = 0;
		int s2c = 0;

		for (size_t c = 0; c < size; c++)
		{
			if (c < s1.size() && s1[c] == a)
			{
				s1[c] = '0';
				s1c++;
			}
			if (c < s2.size() && s2[c] == a)
			{
				s2[c] = '0';
				s2c++;
			}
		}
		r += s1c > s2c ? s2c : s1c;
	}

	return r;
}

bool isLucky(int n) {
	std::string temp = std::to_string(n);
	int s1 = 0, s2 = 0;
	for (size_t i = 0; i < temp.size() / 2; i++)
	{
		s1 += (int)temp[i];
		s2 += (int)temp[i + temp.size() / 2];
	}
	return s1 == s2 ? true : false;
}

std::vector<int> sortByHeight(std::vector<int> a) {
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] == -1)
			continue;
		else
			for (size_t c = i; c < a.size(); c++)
				if (a[c] != -1 && a[c] < a[i])
					swap(a[c], a[i]);
	}
	return a;
}

std::string reverseParentheses(std::string s) {
	auto swap = [](auto &a1, auto &a2)
	{
		auto temp = a1;
		a1 = a2;
		a2 = temp;
	};

	auto gen = [swap](string s, int start, int end)
	{
		for (size_t a1 = start + 1, a2 = end - 1; a1 < a2; a1++, a2--)
		{
			swap(s[a1], s[a2]);
		}
		string temp;
		for (size_t i = 0; i < s.size(); i++)
		{
			if (i == start || i == end)
				continue;

			temp += s[i];
		}
		return temp;
	};

	int start;
	int end;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			start = i;
		if (s[i] == ')')
		{
			end = i;
			return reverseParentheses(s = gen(s, start, end));
			break;
		}
	}
	return s;
}

std::vector<int> alternatingSums(std::vector<int> a) {
	vector<int> team = { 0,0 };
	for (size_t i = 0; i < a.size(); i++)
	{
		i % 2 == 0 ? team[0] += a[i] : team[1] += a[i];
	}
	return team;
}

std::vector<std::string> addBorder(std::vector<std::string> picture) {
	for (size_t i = 0; i < picture.size(); i++)
	{
		picture[i] = '*' + picture[i] + '*';
	}
	string board;
	for (size_t i = 0; i < picture[0].size(); i++)
	{
		board += '*';
	}
	picture.insert(picture.begin(), board);
	picture.push_back(board);
	return picture;
}

bool areSimilar(std::vector<int> a, std::vector<int> b) {
	auto swap = [](auto &a, auto &b)
	{
		auto temp = a;
		a = b;
		b = temp;
	};

	int start, end;
	int step = 0;

	for (size_t i = 0; i < a.size(); i++)
	{
		if (b[i] != a[i] && step < 2)
		{
			step == 0 ? start = i : end = i;
			step++;
			if (step == 2)
			{
				swap(b[start], b[end]);
				i = start - 1;
			}
		}
		else if (b[i] != a[i] && step >= 2)
		{
			return false;
		}

	}

	return true;
}

int arrayChange(std::vector<int> inputArray) {
	int count = 0;

	for (size_t i = 0; i < inputArray.size() - 1; i++)
	{
		if (inputArray[i + 1] <= inputArray[i])
		{
			inputArray[i + 1]++;
			count++;
			i--;
		}
	}
	return count;
}

bool palindromeRearranging(std::string inputString) {
	int n = 0;
	int counter = 0;
	char k;

	for (size_t i = 0; i < inputString.size(); i++)
	{
		if (inputString[i] == '0')
			continue;
		else
			k = inputString[i];

		for (size_t c = 0; c < inputString.size(); c++)
		{
			if (inputString[c] == k)
			{
				counter++;
				inputString[c] = '0';
			}
		}
		n += counter % 2;
		counter = 0;
	}

	if (inputString.size() % 2 == 0)
		return n == 0 ? true : false;
	if (inputString.size() % 2 != 0)
		return n == 1 ? true : false;
}

bool areEquallyStrong(int a1, int a2, int b1, int b2) {
	return (a1 > a2 ? a1 : a2) == (b1 > b2 ? b1 : b2)
		&& (a1 < a2 ? a1 : a2) == (b1 < b2 ? b1 : b2);
}

int arrayMaximalAdjacentDifference(std::vector<int> a) {
	int c = 0;
	for (size_t i = 0; i < a.size() - 1; i++)
	{
		int t = a[i] > a[i + 1] ? a[i] - a[i + 1] : a[i + 1] - a[i];
		c = t > c ? t : c;
	}
	return c;
}

bool isIPv4Address(std::string a) {
	string temp;
	int counter = 0;
	for (char x : a)
	{
		if (x >= (int)'0' && x <= (int)'9')
			temp += x;
		else if (x == '.')
		{
			if (temp == "" || atof(temp.c_str()) > 255 || atof(temp.c_str()) < 0)
				return false;
			else
			{
				counter++;
				temp = "";
			}
		}
		else
			return false;
	}

	return counter == 3 && atof(temp.c_str()) <= 255 & atof(temp.c_str()) >= 0;
}

//avoidObstacles
int foo(std::vector<int> a, int jump)
{
	for (auto x : a)
		if (x % jump == 0)
			return foo(a, ++jump);
	return jump;
}

int avoidObstacles(std::vector<int> a) {
	return foo(a, 2);
}
//

std::vector<std::vector<int>> boxBlur(std::vector<std::vector<int>> image) {
	std::vector<std::vector<int>> result(image.size() - 2);
	auto get = [&result](vector<std::vector<int>> image, auto row, auto col)
	{
		int temp = 0;
		for (size_t i = 0; i < 3; i++)
			for (size_t c = 0; c < 3; c++)
				temp += image[row + i][col + c];
		result[row].push_back(temp / 9);
	};

	for (size_t i = 0; i <= image.size() - 3; i++)
		for (size_t c = 0; c <= image[i].size() - 3; c++)
			get(image, i, c);

	return result;
}

std::vector<std::vector<int>> minesweeper(std::vector<std::vector<bool>> matrix) {
	vector<vector<int>> result(matrix.size(), vector<int>(matrix[0].size()));
	auto check = [&](int y, int x) {
		for (int i = -1; i < (y == matrix.size() - 1 ? 1 : 2); i++) {
			if (y == 0 && i == -1)continue;
			for (int c = -1; c < (x == matrix[0].size() - 1 ? 1 : 2); c++) {
				if (x == 0 && c == -1 || c == 0 && i == 0)continue;
				if (matrix[y + i][x + c] == true)result[y][x]++;
			}
		}
	};
	for (size_t i = 0; i < matrix.size(); i++)
		for (size_t c = 0; c < matrix[0].size(); c++)
			check(i, c);
	return result;
}

std::vector<int> arrayReplace(std::vector<int> inputArray, int elemToReplace, int substitutionElem) {
	std::replace(inputArray.begin(), inputArray.end(), elemToReplace, substitutionElem);
	return inputArray;
}

bool evenDigitsOnly(int n) {
	string x = to_string(n);
	for (auto a : x)
	{
		if ((int)a % 2 != 0)
			return false;
	}
	return true;
}

bool variableName(std::string name) {
	regex let("[A-Za-z_][A-Za-z0-9_]*");
	return regex_match(name, let);
}

std::string alphabeticShift(std::string x) {
	for (auto &a : x)
		a == 'z' ? a = 'a' : a++;
	return x;
}

bool chessBoardCellColor(std::string a, std::string b) {
	return (a[0] % 2 == 0 ? (a[1] % 2 == 0 ? true : false) : (a[1] % 2 != 0 ? true : false))
		== (b[0] % 2 == 0 ? (b[1] % 2 == 0 ? true : false) : (b[1] % 2 != 0 ? true : false));
}

int circleOfNumbers(int n, int a) {
	return a >= n / 2 ? a - n / 2 : a + n / 2;
}

int depositProfit(int deposit, int rate, int threshold) {
	int years = 0;
	float dep = static_cast<float>(deposit);
	while (dep < threshold)
	{
		years++;
		dep *= (float)rate / 100 + 1;
	}
	return years;
}

int absoluteValuesSumMinimization(std::vector<int> a) {
	return a.size() % 2 == 0 ? a[a.size() / 2 - 1] : a[a.size() / 2];
}

bool stringsRearrangement(std::vector<std::string> a) {
	vector<string>temp(a.size());
	temp[0] = a[0];
	a.erase(a.begin());
	auto check = [](string &a1, string &a2)
	{
		int x = 0;
		for (size_t i = 0; i < a1.size(); i++)
			if (a1[i] != a2[i])
				x++;
		return x == 1 ? true : false;
	};


	for (size_t i = 0; i < temp.size() - 1; i++)
		for (size_t c = 0; c < a.size(); c++)
			if (check(temp[i], a[c]))
			{
				temp[i + 1] = a[c];
				a.erase(a.begin() + c);
				break;
			}

	bool step = true;
	while (a.size()>0 && step == true)
	{
		step = false;
		for (size_t i = 0; i < a.size(); i++)
		{
			for (size_t c = 1; c < temp.size(); c++)
			{
				if (check(temp[0], a[i]) == true)
				{
					temp.insert(temp.begin(), a[i]);
					a.erase(a.begin() + i);
					step = true;
					break;
				}
				if (check(temp[c], a[i]) == true && check(temp[c - 1], a[i]) == true)
				{
					temp.insert(temp.begin() + c, a[i]);
					a.erase(a.begin() + i);
					step = true;
					break;
				}
			}

		}
	}

	return a.size() == 0 ? true : false;
}

std::vector<int> extractEachKth(std::vector<int> a, int k) {
	for (size_t i = a.size(); i > 0; i--)
		if (i % k == 0)
			a.erase(a.begin() + i - 1);
	return a;
}

char firstDigit(std::string a) {
	regex x("[0-9]");
	cmatch res;
	regex_search(a.c_str(), res, x);
	return a[res.position()];
}

int differentSymbolsNaive(std::string a) {
	int q = 0;
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] != '0')
		{
			char l = a[i];
			q++;
			for (auto &x : a)
				if (x == l)
					x = '0';
		}
	}
	return q;
}

int arrayMaxConsecutiveSum(std::vector<int> a, int k) {
	int maxsum = 0;
	for (size_t i = 0; i < k; i++)
		maxsum += a[i];
	for (size_t i = 1, sum = maxsum; i < a.size() - (k - 1); i++)
	{
		sum -= a[i - 1];
		sum += a[i + k - 1];
		if (sum > maxsum)
			maxsum = sum;
	}
	return maxsum;
}

int growingPlant(int a, int b, int x) {
	int height = 0;
	int counter = 1;
	while (height + a < x)
	{
		height += a - b;
		counter++;
	}
	return counter;
}

int knapsackLight(int value1, int weight1, int value2, int weight2, int maxW) {
	if (weight1 > maxW && weight2 > maxW)
		return 0;
	if (weight1 + weight2 <= maxW)
		return value1 + value2;
	return value1 > value2 ? (weight1 <= maxW ? value1 : value2) : (weight2 <= maxW ? value2 : value1);
}

std::string longestDigitsPrefix(std::string a) {
	string temp;
	for (auto x : a)
		if (isdigit(x))temp += x;
		else break;
		return temp;
}

int digitDegree(int n) {
	int dig = 0;
	while (n > 9)
	{
		int sum = 0;
		while (n > 0)
		{
			sum += n % 10;
			n /= 10;
		}
		n = sum;
		dig++;
	}
	return dig;
}

bool bishopAndPawn(std::string b, std::string p) {
	return abs(p[0] - b[0]) == abs(p[1] - b[1]);
}

bool isBeautifulString(std::string a) {
	sort(a.begin(), a.end());
	char ch = 'a';

	int last = a.size();
	int curr = 0;
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] == ch)
		{
			curr++;
			if (curr > last)
				return false;
		}
		else
		{
			if (curr == 0)
				return false;
			last = curr;
			curr = 0;
			ch++;
			i--;
		}
	}

	return true;
}

std::string findEmailDomain(std::string a) {
	return a.substr(a.find_last_of('@') + 1);
}

std::string buildPalindrome(std::string st) {
	auto rev = [](string &st)
	{
		string temp;
		for (int i = st.size() - 1; i >= 0; i--)
			temp += st[i];
		return temp;
	};
	int n = st.size();
	int i = 0;
	while (st != rev(st))
	{
		st.insert(st.begin() + n, st[i]);
		i++;
	}
	return st;
}

int electionsWinners(std::vector<int> votes, int k) {
	int max = *max_element(votes.begin(), votes.end());
	int counter = 0;
	if (k == 0)
	{
		for (auto x : votes)
			if (x == max)
				counter++;
		if (counter > 1)
			return 0;
	}
	for (auto x : votes)
	{
		if (x + k > max)
			counter++;
	}
	return counter;
}

bool isMAC48Address(std::string inputString) {
	regex reg("[0-9A-F]{2}-[0-9A-F]{2}-[0-9A-F]{2}-[0-9A-F]{2}-[0-9A-F]{2}-[0-9A-F]{2}");
	return regex_match(inputString, reg);
}

bool isDigit(char symbol) {
	return isdigit(symbol);
}

std::string lineEncoding(std::string s) {
	string temp;
	char ch = s[0];
	int counter = 0;
	auto place = [&temp](auto counter, auto ch)
	{
		if (counter == 1)
			temp += ch;
		else
			temp += to_string(counter) + ch;
	};
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] == ch)
			counter++;
		else
		{
			place(counter, ch);
			ch = s[i];
			i--;
			counter = 0;
		}
		if (i == s.size() - 1)
			place(counter, ch);
	}
	return temp;
}

int chessKnight(std::string cell) {
	int x = (int)cell[0] - 96;
	int y = (int)cell[1] - 48;
	int counter = 0;
	auto check = [](auto a1, auto a2)
	{
		if (a1 > 0 && a1 <= 8 && a2 > 0 && a2 <= 8)
			return true;
		else
			return false;
	};
	if (check(x + 2, y + 1) == true)counter++;
	if (check(x + 2, y - 1) == true)counter++;
	if (check(x - 2, y + 1) == true)counter++;
	if (check(x - 2, y - 1) == true)counter++;
	if (check(x + 1, y + 2) == true)counter++;
	if (check(x - 1, y + 2) == true)counter++;
	if (check(x - 1, y - 2) == true)counter++;
	if (check(x + 1, y - 2) == true)counter++;

	return counter;
}

int deleteDigit(int n) {
	string temp = to_string(n);
	if (temp[0] < temp[1])
		temp.erase(temp.begin());
	else
	{
		for (size_t i = 1; i < temp.size() - 1; i++)
			if (temp[i] < temp[i + 1])
			{
				temp.erase(temp.begin() + i);
				return atof(temp.c_str());
			}
		temp.pop_back();
	}
	return atof(temp.c_str());
}

std::string longestWord(std::string text) {
	int start;
	int counter = 0;
	vector<string>temp;
	auto cor = [](char a)
	{
		if (a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z')
			return true;
		else
			return false;
	};
	auto max = [&temp]()
	{
		int x = temp[0].size();
		int a = 0;
		for (size_t i = 0; i < temp.size(); i++)
		{
			if (temp[i].size() > x)
			{
				x = temp[i].size();
				a = i;
			}
		}
		return temp[a];
	};
	bool st = false;
	for (size_t i = 0; i < text.size(); i++)
	{
		if (cor(text[i]))
		{
			if (st == false)
				start = i;
			st = true;
			counter++;
		}

		if (!cor(text[i]) || i == text.size() - 1)
		{
			if (st == true)
			{
				temp.push_back(text.substr(start, counter));
				st = false;
				counter = 0;
			}
		}
	}
	return max();
}

bool validTime(std::string time) {
	return regex_match(time, regex("(?:[0-1][0-9]|[0-2][0-3]):[0-5][0-9]"));
}

int sumUpNumbers(std::string a) {
	string temp;
	int sum = 0;
	for (size_t i = 0; i < a.size(); i++)
	{
		if (isdigit(a[i]))
			temp += a[i];
		else
		{
			if (temp.size() > 0)
			{
				sum += atof(temp.c_str());
				temp = "";
			}
		}
	}
	if (temp.size() > 0)
		sum += atof(temp.c_str());
	return sum;
}

int differentSquares(std::vector<std::vector<int>> a) {
	int key[9999] = {};
	int counter = 0;
	for (size_t i = 0; i < a.size() - 1; i++)
		for (size_t c = 0; c < a[0].size() - 1; c++)
		{
			int n = a[i][c] * 1000 + a[i][c + 1] * 100 + a[i + 1][c] * 10 + a[i + 1][c + 1];
			if (key[n] == 0)
			{
				counter++;
				key[n] = 1;
			}
		}
	return counter;
}

int digitsProduct(int product) {
	string temp;
	if (product == 0)
		return 10;
	if (product == 1)
		return 1;
	while (product > 1)
	{
		int n = 9;
		while (product % n != 0)n--;

		if (n == 1)
			return -1;
		product /= n;
		temp.insert(0, to_string(n));
		n = 9;
	}
	return atof(temp.c_str());
}

std::vector<std::string> fileNaming(std::vector<std::string> names) {
	auto f = [&names](string str, int start)
	{
		int num = 1;
		bool check = false;
		while (true)
		{
			string temp = str + '(' + to_string(num) + ')';
			check = false;
			for (int i = start - 1; i >= 0; i--)
			{
				if (names[i] == temp)
				{
					check = true;
					break;
				}
			}
			if (check == false)
				return temp;
			num++;
		}
	};

	for (size_t i = 0; i < names.size(); i++)
	{
		for (size_t c = i + 1; c < names.size(); c++)
		{
			if (names[c] == names[i])
				names[c] = f(names[c], c);
		}
	}
	return names;
}

std::string messageFromBinaryCode(std::string code) {
	string result, temp;

	int counter = 0;
	for (auto x : code)
	{
		temp += x;
		counter++;
		if (counter == 8)
		{
			result += (char)strtol(temp.c_str(), 0, 2);
			temp = "";
			counter = 0;
		}
	}
	return result;
}

std::vector<std::vector<int>> spiralNumbers(int n) {
	vector<vector<int>>map(n, vector<int>(n));
	map[0][0] = 1;
	int counter = 1;
	int posx = 0;
	int posy = 0;
	auto check = [n](int x, int y)
	{
		if (x >= 0 && x < n && y >= 0 && y < n)
			return true;
		else
			return false;
	};
	auto go = [&](int dirx, int diry)
	{
		while (check(posx + dirx, posy + diry) && map[posx + dirx][posy + diry] == 0)
		{
			map[posx + dirx][posy + diry] = ++counter;
			posx += dirx;
			posy += diry;
		}
	};
	while (counter < n*n)
	{
		go(0, 1);
		go(1, 0);
		go(0, -1);
		go(-1, 0);
	}
	return map;
}

bool sudoku(std::vector<std::vector<int>> grid) {
	int num[10] = { 0,1,2,3,4,5,6,7,8,9 };
	auto clear = [&num]()
	{
		for (size_t i = 0; i < 10; i++)
			num[i] = 0;
	};
	auto check = [&num]()
	{
		for (size_t i = 1; i < 10; i++)
			if (num[i] == 0)
				return false;
		return true;
	};
	auto getq = [&num, &grid](int x, int y)
	{
		for (size_t i = x; i < x + 3; i++)
			for (size_t c = y; c < y + 3; c++)
				num[grid[i][c]] = grid[i][c];
	};

	for (size_t i = 0; i < grid.size(); i++)
	{
		for (size_t c = 0; c < grid.size(); c++)
			num[grid[i][c]] = grid[i][c];

		if (check() == false)
			return false;
		else
			clear();
	}
	for (size_t i = 0; i < grid.size(); i++)
	{
		for (size_t c = 0; c < grid.size(); c++)
			num[grid[c][i]] = grid[c][i];

		if (check() == false)
			return false;
		else
			clear();
	}
	for (size_t i = 0; i < grid.size() - 2; i += 3)
	{
		for (size_t c = 0; c < grid.size() - 2; c += 3)
		{
			getq(i, c);
			if (check() == false)
				return false;
			else
				clear();
		}
	}
	return true;
}
