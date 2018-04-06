int addTwoDigits(int n) {
	return n / 10 + n % 10;
}

int largestNumber(int n) {
	return pow(10, n) - 1;
}

int candies(int n, int m) {
	return (m / n) * n;
}

int seatsInTheater(int nCols, int nRows, int col, int row) {
	return (nCols - col + 1) * (nRows - row);
}

int maxMultiple(int divisor, int bound) {
	return bound - (bound % divisor);
}

int circleOfNumbers(int n, int x) {
	return (x + (n / 2)) % n;
}

int lateRide(int n) {
	return n / 60 / 10 + n / 60 % 10 + n % 60 / 10 + n % 60 % 10;
}

int phoneCall(int m1, int m2, int m3, int n) {
	int min = 0;
	if (n < m1)
		return 0;
	else
	{
		min++;
		n -= m1;
	}

	int counter = 9;
	while (n > 0 && n > m2 && counter > 0)
	{
		n -= m2;
		min++;
		counter--;
	}
	if (n > 0 && counter == 0)
		return min += n / m3;
	return min;
}

bool reachNextLevel(int experience, int threshold, int reward) {
	return experience + reward >= threshold;
}

int knapsackLight(int value1, int weight1, int value2, int weight2, int maxW) {
	if (weight1 > maxW && weight2 > maxW)
		return 0;
	if (weight1 + weight2 <= maxW)
		return value1 + value2;
	return value1 > value2 ? (weight1 <= maxW ? value1 : value2) : (weight2 <= maxW ? value2 : value1);
}

int extraNumber(int a, int b, int c) {
	return a == b ? c : (a == c ? b : a);
}

bool isInfiniteProcess(int a, int b) {
	return a > b ? true : (b - a) % 2 != 0;
}

bool arithmeticExpression(int a, int b, int c) {
	if (a + b == c || a - b == c || a * b == c || a / b == c && a % b == 0)
		return true;
	return false;
}

bool tennisSet(int score1, int score2) {
	return ((score1 == 7 || score2 == 7) &&
		((score1 > 4 && score1 < 7) ||
		(score2 > 4 && score2 < 7))) ||
			((score1 == 6 || score2 == 6) &&
		(score1 < 5 || score2 < 5));
}

bool willYou(bool young, bool beautiful, bool loved) {
	if (young && beautiful && !loved)
		return true;
	if (loved && (!young || !beautiful))
		return true;
	return false;
}

std::vector<int>reg, metroCard(int a) {
	return a == 31 ? reg = { 28,30,31 } : reg = { 31 };
}

int killKthBit(int n, int k) {
	return (n &= ~(1 << k - 1));
}

int result, arrayPacking(std::vector<int> a) {
	for (size_t i = 0; i < a.size(); i++)
		result |= a[i] << i * 8;
	return result;
}

int result, rangeBitCount(int a, int b) {
	for (size_t i = a; i <= b; i++)
	{
		bitset<8>a(i);
		result += a.count();
	}
	return result;
}

int num, mirrorBits(int a) {
	vector<int>bits;
	while (a > 0)
	{
		bits.push_back(a % 2);
		a /= 2;
	}
	for (auto x : bits)
		num = num * 2 + x;
	return num;
}

int secondRightmostZeroBit(int n) {
	return -~((n - ~(n ^ (n + 1)) / 2) ^ (n - ~(n ^ (n + 1)) / 2 + 1)) / 2;
}

int swapAdjacentBits(int n) {
	return (((n & 0x2AAAAAAA) >> 1) | ((n & 0x15555555) << 1));
}

int differentRightmostBit(int n, int m) {
	return -~((~(n^m)) ^ ((~(n^m)) + 1)) / 2;
}

int equalPairOfBits(int n, int m) {
	return ~(n ^ m) & ((n ^ m) + 1);
}

//leastFactorial
int fact(int x)
{
	return x == 1 ? 1 : x * fact(x - 1);
}

int leastFactorial(int n) {
	int x = 1;
	while (fact(x) < n)
		x++;
	return fact(x);
}
//

int counter, countSumOfTwoRepresentations2(int n, int l, int r) {
	while (r >= n - r)
	{
		if (n - r >= l)
			counter++;
		r--;
	}
	return counter;
}

int magicalWell(int a, int b, int n) {
	int result = 0;
	while (n > 0)
	{
		result += a++ * b++;
		n--;
	}
	return result;
}

int lineUp(std::string commands) {
	float dir = 0;
	for (auto x : commands)
		(x == 'L' || x == 'R') ? dir += 0.5 : (dir == (int)dir ? dir += 1 : dir += 0);
	return (int)dir;
}

int additionWithoutCarrying(int param1, int param2) {
	int result = 0;
	for (int n = 1; param1 || param2; param1 /= 10, param2 /= 10, n *= 10)
		result += ((param1 % 10 + param2 % 10) % 10) * n;
	return result;
}

int appleBoxes(int k) {
	int result = 0;
	for (int r = 0, y = 0; k; k--, result = r - y)
		k % 2 == 0 ? r += k * k : y += k * k;
	return result;
}

bool increaseNumberRoundness(int n) {
	for (; n / 10 > 0; n /= 10)
		if (n % 10 != 0 && (n / 10) % 10 == 0)return true;
	return false;
}

int rounders(int value) {
	int result = 1;
	for (; value>9; result *= 10)
		value % 10 >= 5 ? value = (value / 10) + 1 : value /= 10;
	return value * result;
}

int candles(int num, int cost) {
	int result = 0;
	for (int stack = 0; num; num = stack / cost, stack = stack % cost)
	{
		stack += num;
		result += num;
	}
	return result;
}

//countBlackCells
int gcd(int n, int m) {
	while (m) {
		int temp = n;
		n = m;
		m = temp % m;
	}

	return n;
}
int countBlackCells(int n, int m) {
	if (n == m) return (n + 2 * (n - 1));
	if (n == 1 || m == 1) return n * m;
	return n + m - gcd(n, m) + (gcd(n, m) - 1) * 2;
}
//

std::vector<int> createArray(int size) {
	return vector<int>(size, 1);
}

std::vector<int> arrayReplace(std::vector<int> inputArray, int elemToReplace, int substitutionElem) {
	for (auto &x : inputArray)
		if (x == elemToReplace)x = substitutionElem;
	return inputArray;
}

std::vector<int> firstReverseTry(std::vector<int> arr) {
	if (arr.size() == 0)
		return arr;
	std::swap(arr[0], arr[arr.size() - 1]);
	return arr;
}

std::vector<int> concatenateArrays(std::vector<int> a, std::vector<int> b) {
	for (auto x : b)a.push_back(x);
	return a;
}

std::vector<int> removeArrayPart(std::vector<int> a, int l, int r) {
	a.erase(a.begin() + l, a.begin() + r + 1);
	return a;
}

bool isSmooth(std::vector<int> arr) {
	int r = arr.size() % 2 == 0 ? arr[arr.size() / 2] + arr[arr.size() / 2 - 1] : arr[arr.size() / 2];
	return arr[0] == r && arr[0] == arr[arr.size() - 1];
}

std::vector<int> replaceMiddle(std::vector<int> arr) {
	if (arr.size() % 2 == 0)
	{
		arr.insert(arr.begin() + arr.size() / 2 - 1, arr[arr.size() / 2] + arr[arr.size() / 2 - 1]);
		arr.erase(arr.begin() + arr.size() / 2, arr.begin() + arr.size() / 2 + 2);
	}

	return arr;
}

int makeArrayConsecutive2(std::vector<int> statues) {
	auto res = minmax_element(statues.begin(), statues.end());
	return ((*res.second - *res.first) + 1) - statues.size();
}

bool isPower(int n) {
	return (pow((int)sqrt(n), 2) == n || (int)(pow((int)(pow(n, 1.0 / 3) + 1), 3)) == n);
}

int isSumOfConsecutive2(int n) {
	if (n == 1)
		return 0;
	int x = n / 2 + 1;
	int counter = 0;
	do
	{
		for (size_t i = 0, res = 0; i < x && res < n; i++)
		{
			res += x - i;
			if (res == n)
			{
				counter++;
				break;
			}
		}
	} while (x-- > 1);
	return counter;
}

int squareDigitsSequence(int a0) {
	int counter = 1;
	bool num[255] = {};

	while (num[a0] != 1)
	{
		num[a0] = 1;
		int res = 0;
		while (a0 > 0)
		{
			res += pow(a0 % 10, 2);
			a0 /= 10;
		}
		a0 = res;
		counter++;
	}
	return counter;
}

int pagesNumberingWithInk(int a, int b) {
	int cost = 0;
	int page = 0;
	while (b >= cost)
	{
		cost = 0;
		int temp = a;
		while (temp>0)
		{
			temp /= 10;
			cost++;
		}

		if (b >= cost)
		{
			b -= cost;
			page = a;
			a++;
		}
	}
	return page;
}

int comfortableNumbers(int l, int r) {
	auto plus = [](int x)
	{
		int res = 0;
		while (x > 0)
		{
			res += x % 10;
			x /= 10;
		}
		return res;
	};
	int counter = 0;
	while (r>l)
	{
		int x = r - plus(r);
		int y = l;
		while (y < r)
		{
			if (y >= x && r <= y + plus(y))
				counter++;
			y++;
		}
		r--;
	}
	return counter;
}

std::vector<int> weakNumbers(int n) {
	auto del = [](int n)
	{
		if (n == 1 || n == 0)
			return 1;
		int x = 2;
		int counter = 2;
		while (x * 2 <= n)
		{
			if (n % x == 0)
				counter++;
			x++;
		}
		return counter;
	};
	vector<int>result(2, 0);
	int size = n + 1;
	int *arr = new int[size];
	for (size_t i = 0; i < size; i++)
		arr[i] = del(i);

	int max = 0;
	for (size_t i = size - 1; i >= 1; i--)
	{
		int temp = 0;
		for (size_t c = i - 1; c >= 1; c--)
		{
			if (arr[c] > arr[i])
				temp++;
		}
		if (temp > max)
			max = temp;
		arr[i] = temp;
	}
	result[0] = max;

	for (size_t i = 0; i < size; i++)
		if (arr[i] == max)
			result[1]++;

	return result;
}

int rectangleRotation(int a, int b) {
	float res = sqrt(pow(1, 2) + pow(1, 2));
	int x = (int)((a / 2) / res) * 2 + 1;
	int y = (int)((b / 2) / res) * 2 + 1;
	float x1 = (a / 2 - res / 2);
	x1 = (int)(x1 / res + 1) * 2;
	float y1 = (b / 2 - res / 2);
	y1 = (int)(y1 / res + 1) * 2;
	res = x * y + x1 * y1;
	return res;
}

int crosswordFormation(std::vector<std::string> words) {
	int counter = 0;

	auto check = [&counter](string fir, string sec, string thi, string res)
	{
		for (size_t f = 0; f < fir.size() - 2; f++)
		{
			for (size_t s = 0; s < sec.size() - 2; s++)
			{
				if (sec[s] == fir[f])
					for (size_t f2 = f + 2; f2 < fir.size() && (f2 - f) < res.size(); f2++)
					{
						for (size_t t = 0; t < thi.size(); t++)
						{
							if (thi[t] == fir[f2])
							{
								for (size_t r = 0; r < res.size() - (f2 - f); r++)
								{
									for (size_t s2 = s + 2, t2 = t + 2; s2 < sec.size() && t2 < thi.size(); s2++, t2++)
									{
										if (res[r] == sec[s2] && res[r + (f2 - f)] == thi[t2])
										{
											counter++;

										}
									}
								}
							}
						}
					}
			}
		}
	};

	for (auto fir : words)
	{
		for (auto sec : words)
		{
			if (sec != fir)
				for (auto thi : words)
				{
					if (thi != sec && thi != fir)
						for (auto res : words)
						{
							if (res != thi && res != sec && res != fir)
							{
								check(fir, sec, thi, res);
							}
						}
				}
		}
	}
	return counter;
}

std::string encloseInBrackets(std::string inputString) {
	return "(" + inputString + ")";
}

std::string properNounCorrection(std::string noun) {
	for (auto &x : noun)
		x = tolower(x);
	noun[0] = toupper(noun[0]);
	return noun;
}

bool isTandemRepeat(std::string a) {
	return a.substr(0, a.size() / 2) == a.substr(a.size() / 2, a.size());
}

bool isCaseInsensitivePalindrome(std::string inputString) {
	for (auto &x : inputString)
		x = tolower(x);
	string temp = inputString;
	reverse(temp.begin(), temp.end());
	return inputString == temp;
}

std::string findEmailDomain(std::string address) {
	return address.substr(address.find_last_of('@') + 1, address.size());
}

std::string htmlEndTagByStartTag(std::string a) {
	auto end = [](string a) {
		for (size_t i = 0; i < a.size(); i++)
			if (a[i] == ' ' || a[i] == '>')return i; };

	return  "</" + a.substr(a.find('<') + 1, end(a) - 1) + ">";
}

bool isMAC48Address(std::string inputString) {
	regex reg("[0-9A-F]{2}-[0-9A-F]{2}-[0-9A-F]{2}-[0-9A-F]{2}-[0-9A-F]{2}-[0-9A-F]{2}");
	return regex_match(inputString, reg);
}

bool isUnstablePair(std::string a1, std::string a2) {
	auto check1 = [&]()
	{
		for (size_t i = 0; i < a1.size() && i < a2.size(); i++)
			if (a1[i] != a2[i])
				return a1[i]<a2[i];
		return a1.size() < a2.size();
	};
	auto check2 = [&]()
	{
		for (size_t i = 0; i < a1.size() && i < a2.size(); i++)
			if (toupper(a1[i]) != toupper(a2[i]))
				return toupper(a1[i]) < toupper(a2[i]);
		return a1.size() < a2.size();
	};
	return check1() != check2();
}

int stringsConstruction(std::string a, std::string b) {
	int counter = 0;
	bool check = true;
	while (check == true)
	{
		for (size_t i = 0; i < a.size(); i++)
			for (size_t c = 0; c < b.size(); c++)
			{
				if (b[c] == a[i])
				{
					b[c] = '0';
					break;
				}
				if (c == b.size() - 1)
					check = false;
			}
		counter++;
	}
	return counter - 1;
}

bool isSubstitutionCipher(std::string s1, std::string s2) {
	char ch2 = '0', ch1 = '0', c1, c2;
	for (size_t c = 0; c < s1.size(); c++)
	{
		if (s1[c] > '9')
		{
			ch1++;
			c1 = s1[c];
		}
		if (s2[c] > '9')
		{
			ch2++;
			c2 = s2[c];
		}
		for (size_t i = 0; i < s1.size(); i++)
		{
			if (s1[i] == c1 && s1[i] > '9')
				s1[i] = ch1;
			if (s2[i] == c2 && s2[i] > '9')
				s2[i] = ch2;
		}

	}
	return s1 == s2;
}

int createAnagram(std::string s, std::string t) {
	int counter = 0;
	string temp = " ";
	char ch;

	for (size_t i = 0; s.find_first_not_of(temp) < s.size(); i++)
	{
		int c1 = 0, c2 = 0;
		ch = s[s.find_first_not_of(temp)];
		for (size_t c = 0; c < t.size(); c++)
		{
			if (s[c] == ch)
				c1++;
			if (t[c] == ch)
				c2++;
		}
		if (c1 > c2)
			counter += c1 - c2;
		temp += ch;
	}
	return counter;
}

int constructSquare(std::string s) {

	auto calc = [](string &str)
	{
		string mask;
		for (string exep = " "; str.find_first_not_of(exep)< str.size(); )
		{
			int counter = 0;
			char ch = str[str.find_first_not_of(exep)];
			for (size_t i = 0; i < str.size(); i++)
			{
				if (str[i] == ch)
					counter++;
			}
			mask += to_string(counter);
			exep += ch;
		}
		return mask;
	};
	string temp(s.size(), '9');
	int qt = sqrt(atof(temp.c_str()));
	s = calc(s);
	sort(s.begin(), s.end());
	if (s.size() == 1 && s[0] - 48 > 1)
		return -1;
	while (true)
	{
		temp = to_string((int)pow(qt, 2));
		temp = calc(temp);
		sort(temp.begin(), temp.end());
		if (temp == s)
			return (int)pow(qt, 2);
		qt--;
	}
	return -1;
}

int numbersGrouping(std::vector<int> a) {
	sort(a.begin(), a.end());
	int counter = 1;
	int last = a[0] % 10000 == 0 ? a[0] / 10000 - 1 : a[0] / 10000;
	for (size_t i = 1; i < a.size(); i++)
	{
		int gr = a[i] % 10000 == 0 ? a[i] / 10000 - 1 : a[i] / 10000;
		if (gr != last)
			counter++;
		last = gr;
	}

	return counter + a.size();
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

int mostFrequentDigitSum(int n) {
	auto lam = [](int x)
	{
		int sum = 0;
		while (x > 0)
		{
			sum += x % 10;
			x /= 10;
		}
		return sum;
	};

	int arr[60] = {};
	while (n > 0)
	{
		int c = lam(n);
		arr[c]++;
		n -= c;
	}
	int num = 0;
	for (size_t i = 0, max = 0; i < 60; i++)
	{
		if (arr[i] >= max)
		{
			num = i;
			max = arr[i];
		}
	}
	return num;
}

int numberOfClans(std::vector<int> div, int k) {
	set<vector<bool>>clanset;
	for (size_t i = 1; i <= k; i++)
	{
		vector<bool>clan(div.size());
		for (size_t c = 0; c < div.size(); c++)
			clan[c] = i % div[c] == 0;
		clanset.emplace(clan);
	}
	return clanset.size();
}

int result, houseNumbersSum(std::vector<int> inputArray) {
	for (auto x : inputArray)
	{
		if (x == 0)
			break;
		result += x;
	}
	return result;
}

std::vector<std::string> result, allLongestStrings(std::vector<std::string> s) {
	int max = 0;
	for (auto x : s)
		x.size() > max ? max = x.size() : max;
	for (auto x : s)
		if (x.size() == max)
			result.push_back(x);
	return result;
}

std::vector<int>result, houseOfCats(int legs) {
	for (; legs >= 0; legs -= 4)
		legs == 0 ? result.insert(result.begin(), 0) : result.insert(result.begin(), legs / 2);
	return result;
}

bool alphabetSubsequence(std::string s) {
	for (size_t i = 1; i < s.size(); i++)
		if (s[i] <= s[i - 1])
			return false;
	return true;
}

int result, minimalNumberOfCoins(std::vector<int> coins, int price) {
	for (size_t i = coins.size() - 1; i >= 0 && price; i--)
		if (coins[i] <= price)
		{
			result += price / coins[i];
			price -= coins[i] * (price / coins[i]);
		}
	return result;
}

std::vector<std::string> addBorder(std::vector<std::string> picture) {
	for (auto &x : picture)
		x = "*" + x + "*";
	picture.insert(picture.begin(), string(picture[0].size(), '*'));
	picture.push_back(string(picture[0].size(), '*'));
	return picture;
}

std::vector<int> switchLights(std::vector<int> a) {
	int counter = 0;
	for (auto x = a.rbegin(); x != a.rend(); x++)
	{
		if (*x == 1)
			counter++;
		counter % 2 != 0 ? *x = abs(*x - 1) : *x;
	}
	return a;
}

int timedReading(int maxLength, std::string text) {
	int leng = 0;
	int result = 0;
	auto check = [&]()
	{
		result += leng && leng <= maxLength;
		leng = 0;
	};
	for (auto x : text)
	{
		if (isalpha(x))
			leng++;
		else
			check();
	}
	check();
	return result;
}

int electionsWinners(std::vector<int> votes, int k) {
	int max = *max_element(votes.begin(), votes.end());
	int counter = 0;
	int countermax = 0;
	for (auto x : votes)
	{
		if (x + k > max)
			counter++;
		if (x == max)
			countermax++;
	}
	return countermax > 1 ? 0 : counter;
}

std::string integerToStringOfFixedWidth(int number, int width) {
	string res = to_string(number);
	return res.size() < width ? string(width - res.size(), '0') + res : res.substr(res.size() - width, res.size());
}

bool areSimilar(std::vector<int> a, std::vector<int> b) {
	int a1 = a.size();
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
		{
			if (a1 == a.size())
				a1 = i;
			else
			{
				swap(a[a1], a[i]);
				return a == b;
			}
		}
	}
	return a == b;
}

bool adaNumber(std::string line) {
	auto parse = [](string str)
	{
		string temp;
		for (auto x : str)
		{
			if (x >= 97 && x <= 102)
				temp += to_string(x - 87);
			else if (x >= 65 && x <= 70)
				temp += to_string(x - 55);
			else if (isdigit(x))
				temp.push_back(x);
		}
		return temp;
	};
	if (line[0] == '#')
		return false;
	if (line.find_first_of('#') < line.size())
	{
		int x = atof(parse(line.substr(0, line.find_first_of('#'))).c_str());
		if (x < 2 || x > 16)
			return false;
	}
	int reg = 10;
	int start = 0;
	int end = line.size();

	auto check = [&line](int x, int y, int reg)
	{
		if (line.substr(x, y).size() == 0)
			return false;
		else if (regex_match(line.substr(x, y), regex("[_]*")))
			return false;

		if (reg < 2 || reg > 16)
			return false;
		if (reg > 10)
		{
			string temp = "a-" + string(1, 'a' + reg - 11) + "A-" + string(1, 'A' + reg - 11);
			return regex_match(line.substr(x, y), regex("[0-9" + temp + "_]*"));
		}
		else
			return regex_match(line.substr(x, y), regex("[0-" + to_string(reg - 1) + "_]*"));
	};

	for (size_t i = 0, counter = 0; i < line.size(); i++)
	{
		if (line[i] == '#')
		{
			counter++;
			end = i - start;
			if (check(start, end, reg) == false)
				return false;
			reg = atof(parse(line.substr(start, end)).c_str());
			start = i + 1;
		}
		if (i == line.size() - 1 && line[i] == '#' && counter >1)
			return true;
	}
	start = 0;
	end = line.size();
	return check(start, end, reg);
}

int threeSplit(std::vector<int> a) {
	int end = 0, counter = 0, total = 0;
	for (size_t i = 0; i < a.size(); i++)
		total += a[i];

	for (int i = a.size() - 1, sum3 = 0; i > 0; i--)
	{
		sum3 += a[i];
		if (sum3 == total / 3)
		{
			end = i;
			break;
		}
		if (i < 2)
			return 0;
	}

	for (int i = 0, sum1 = 0; i < end - 1; i++)
	{
		sum1 += a[i];
		if (sum1 == total / 3)
			for (int c = i + 1, sum2 = 0; c < end; c++)
			{
				sum2 += a[c];
				if (sum2 == total / 3)
					counter++;
			}
	}
	return counter;
}

std::string characterParity(char symbol) {
	return isdigit(symbol) ? (((int)symbol - 48) % 2 == 0 ? "even" : "odd") : "not a digit";
}

std::string reflectString(std::string inputString) {
	for (auto &x : inputString)
		x = 'z' - (x - 'a');
	return inputString;
}

std::vector<std::string> newNumeralSystem(char number) {
	vector<string>arr;
	for (size_t i = 0; i <= (number - 'A') / 2; i++)
	{
		string temp;
		temp.push_back('A' + i);
		temp += " + ";
		temp.push_back(number - i);
		arr.push_back(temp);
	}
	return arr;
}

std::string cipher26(std::string str) {
	for (int i = 0, ch = 0, sum = 0; i < str.size(); i++)
	{
		if (sum % 26 <= str[i] - 'a')
		{
			ch = (str[i] - 'a') - sum % 26;
			sum += ch;
		}
		else
		{
			ch = 26 - (sum % 26) + str[i] - 'a';
			sum += ch;
		}
		str[i] = char(ch + 'a');
	}
	return str;
}

std::string stolenLunch(std::string note) {
	for (auto &x : note)
	{
		if (isdigit(x))
			x = char(x - '0' + 'a');
		else if (x >= 'a' && x <= 'j')
			x = char(x - 'a') + '0';
	}
	return note;
}

bool higherVersion(std::string ver1, std::string ver2) {
	vector<int>v1, v2;
	int start = 0;
	for (size_t i = 0; i < ver1.size(); i++)
		if (ver1[i] == '.')
		{
			v1.push_back(atof(ver1.substr(start, i - start).c_str()));
			start = i + 1;
		}
	v1.push_back(atof(ver1.substr(start, ver1.size() - start).c_str()));
	for (size_t i = 0, start = 0; i < ver2.size(); i++)
		if (ver2[i] == '.')
		{
			v2.push_back(atof(ver2.substr(start, i - start).c_str()));
			start = i + 1;
		}
	v2.push_back(atof(ver2.substr(start, ver2.size() - start).c_str()));
	return v1 > v2;
}

std::string decipher(std::string cipher) {
	string result;
	for (size_t i = 0, start = 0; i < cipher.size(); i++)
	{
		int x = atof(cipher.substr(start, i - start + 1).c_str());
		if (x >= 'a' && x <= 'z')
		{
			result.push_back(char(x));
			start = i + 1;
		}
	}
	return result;
}

bool alphanumericLess(std::string s1, std::string s2) {
	vector<string>v1, v2;
	auto prs = [](string str)
	{
		string temp;
		vector<string>res;
		for (size_t i = 0, start = 0; i < str.size(); i++)
		{
			if (isdigit(str[i]))
			{
				temp.push_back(str[i]);
				if (i != str.size() - 1)
					continue;
			}
			if (temp.size() != 0)
			{
				res.push_back(temp);
				temp = "";

			}
			res.push_back(string(1, str[i]));
		}
		return res;
	};
	v1 = prs(s1);
	v2 = prs(s2);
	int size = v1.size() < v2.size() ? v1.size() : v2.size();
	for (size_t i = 0; i < size; i++)
	{
		if (isdigit(v1[i][0]) && isdigit(v2[i][0]))
		{
			if (atof(v1[i].c_str()) != atof(v2[i].c_str()))
			{
				return atof(v1[i].c_str()) < atof(v2[i].c_str());
			}
		}
		else if (!isdigit(v1[i][0]) && !isdigit(v2[i][0]))
		{
			if (v1[i] != v2[i])
				return v1[i] < v2[i];
		}
		else
		{
			if (isdigit(v1[i][0]))
				return true;
			else if (isdigit(v2[i][0]))
				return false;
		}
	}

	if (v1.size() != v2.size())
		return v1.size() < v2.size();

	for (size_t i = 0; i < v1.size(); i++)
	{
		if (v1[i].size() > v2[i].size())
			return true;
		else if (v1[i].size() < v2[i].size())
			return false;
	}
	return false;
}

int arrayConversion(std::vector<int> arr) {
	int iter = 0;
	while (arr.size() != 1)
	{
		vector<int>temp;
		iter++;
		for (size_t i = 0; i < arr.size(); i += 2)
			iter % 2 == 0 ? temp.push_back(arr[i] * arr[i + 1]) :
			temp.push_back(arr[i] + arr[i + 1]);
		arr = temp;
	}
	return arr[0];
}

std::vector<int> arrayPreviousLess(std::vector<int> items) {
	vector<int>result;
	for (size_t i = 0; i < items.size(); i++)
		for (int c = i; c >= 0; c--)
		{
			if (items[c] < items[i])
			{
				result.push_back(items[c]);
				break;
			}
			if (c == 0)
				result.push_back(-1);
		}
	return result;
}

bool pairOfShoes(std::vector<std::vector<int>> shoes) {
	set<int>size;
	for (size_t i = 0; i < shoes.size(); i++)
		size.emplace(shoes[i][1]);
	for (auto x : size)
	{
		int lr[2] = {};
		for (size_t i = 0; i < shoes.size(); i++)
			if (x == shoes[i][1])
				lr[shoes[i][0]]++;
		if (lr[0] != lr[1])
			return false;
	}
	return true;
}

int combs(std::string comb1, std::string comb2) {
	auto par = [](string str1, string str2)
	{
		int size = str1.size() + str2.size();
		for (size_t i = 0, comp = false; i < str1.size(); i++, comp = false)
		{
			int x = 0;
			for (size_t c = i; c < str1.size() && x < str2.size(); c++, x++)
			{
				if ((str1[c] + str2[x]) == ('*' + '*'))
				{
					comp = true;
					break;
				}
			}
			if (comp == false)
			{
				size = str1.size() + (str2.size() - x) < size ? str1.size() + (str2.size() - x) : size;
				break;
			}
		}
		return size;
	};
	int s1 = par(comb1, comb2), s2 = par(comb2, comb1);
	return  s1 < s2 ? s1 : s2;
}

int stringsCrossover(std::vector<std::string> arr, std::string result) {
	int counter = 0;
	for (size_t i = 0; i < arr.size() - 1; i++)
		for (size_t x = i + 1; x < arr.size(); x++)
			for (size_t c = 0; c < arr[i].size(); c++)
			{
				if (arr[i][c] != result[c] && arr[x][c] != result[c])
					break;
				if (c == arr[i].size() - 1)
					counter++;
			}
	return counter;
}

int cyclicString(std::string s) {
	set<char>result;
	for (auto x : s)
		result.emplace(x);
	int x = result.size();


	if (s.size() > x && x > 1)
	{
		bool check = false;
		while (!check)
		{
			string temp = s.substr(0, x);
			for (size_t i = x, c = 0; i < s.size(); i++, c++)
			{
				if (s[i] != temp[c])
				{
					x++;
					if (x == s.size())
						return x;
					break;
				}
				if (i == s.size() - 1)
					check = true;
			}

		}
	}
	return x;
}

bool beautifulText(std::string str, int l, int r) {
	str += " ";
	l++; r++;
	while (l <= r)
	{
		while (str.size() % l != 0 && l <= r)l++;
		if (l > r)
			return false;
		int x = l - 1;
		for (size_t i = x; i < str.size(); i += x)
		{
			if (str[i] != ' ')
			{
				l++;
				break;
			}
			else
				i++;
			if (i >= str.size() - 1)
				return true;
		}
	}
	return false;
}

int runnersMeetings(std::vector<int> st, std::vector<int> speed) {
	int result = -1;
	auto max = [&result](map<int, int> &res)
	{
		for (auto x : res)
			if (x.second > result)
				result = x.second;
	};
	for (size_t i = 0; i < st.size(); i++)
	{
		map<int, int>res;
		for (size_t c = 0; c < st.size(); c++)
		{
			if (c != i)
			{
				float sp = speed[i] - speed[c];
				float dir = (st[i] - st[c]);
				if ((sp > 0) == (dir > 0) || (sp == 0 || dir == 0))
					continue;
				res[dir / (sp / 60)]++;
			}
		}
		max(res);
	}

	return result == -1 ? -1 : result + 1;
}

std::vector<std::string> christmasTree(int levelNum, int levelHeight) {
	vector<string>res;
	int mid = (3 + (2 * levelNum) + ((levelHeight - 1) * 2)) / 2;
	for (size_t i = 0; i < 2; i++)
	{
		string temp(mid, ' ');
		temp.push_back('*');
		res.push_back(temp);
		if (i == 1)
		{
			string temp(mid - 1, ' ');
			string crown(3, '*');
			res.push_back(temp + crown);
		}
	}
	for (size_t i = 0; i < levelNum; i++)
	{
		int x = 5 + (2 * i);
		for (size_t c = 0; c < levelHeight; c++)
		{
			int cr = x + (2 * c);
			string temp(cr, '*');
			string space(mid - ((cr - 1) / 2), ' ');
			res.push_back(space + temp);
		}
	}
	int x = levelHeight % 2 == 0 ? levelHeight + 1 : levelHeight;
	for (size_t i = 0; i < levelNum; i++)
	{
		string temp(mid - ((x - 1) / 2), ' ');
		string foot(x, '*');
		res.push_back(temp + foot);
	}
	return res;
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

std::vector<int> extractMatrixColumn(std::vector<std::vector<int>> matrix, int column) {
	vector<int>result;
	for (size_t i = 0; i < matrix.size(); i++)
		result.push_back(matrix[i][column]);
	return result;
}

bool areIsomorphic(std::vector<std::vector<int>> array1, std::vector<std::vector<int>> array2) {
	if (array1.size() == array2.size())
	{
		for (size_t i = 0; i < array1.size(); i++)
			if (array1[i].size() != array2[i].size())
				return false;
	}
	else
		return false;
	return true;
}

std::vector<std::vector<int>> reverseOnDiagonals(std::vector<std::vector<int>> m) {
	for (size_t i = 0; i < m.size() - 1 - i; i++)
		swap(m[i][i], m[m.size() - 1 - i][m.size() - 1 - i]);
	for (size_t x = 0, y = m.size() - 1; y > x; x++, y--)
	{
		swap(m[x][y], m[y][x]);
	}
	return m;
}

std::vector<std::vector<int>> swapDiagonals(std::vector<std::vector<int>> m) {
	for (size_t x = 0, y = m.size() - 1; x < m.size(); x++, y--)
		swap(m[x][x], m[x][y]);
	return m;
}

int crossingSum(std::vector<std::vector<int>> matrix, int a, int b) {
	int sum = 0;
	for (size_t i = 0; i < matrix[a].size(); i++)
		sum += matrix[a][i];
	for (size_t i = 0; i < matrix.size(); i++)
		sum += matrix[i][b];
	return sum - matrix[a][b];
}

std::vector<std::vector<char>> drawRectangle(std::vector<std::vector<char>> canvas, std::vector<int> r) {
	for (size_t i = r[0]; i <= r[2]; i++)
	{
		if (i == r[0] || i == r[2])
			canvas[r[1]][i] = canvas[r[3]][i] = '*';
		else
			canvas[r[1]][i] = canvas[r[3]][i] = '-';
	}
	for (size_t i = r[1] + 1; i < r[3]; i++)
		canvas[i][r[0]] = canvas[i][r[2]] = '|';
	return canvas;
}

std::vector<std::vector<std::string>> volleyballPositions(std::vector<std::vector<std::string>> f, int k) {
	vector<string*>arr = { &f[3][2],&f[1][2],&f[0][1],&f[1][0],&f[3][0],&f[2][1] };
	vector<string>temp = { f[3][2],f[1][2],f[0][1],f[1][0],f[3][0],f[2][1] };
	for (size_t i = 0; i < arr.size(); i++)
		*arr[(i + k) % 6] = temp[i];
	return f;
}

std::vector<std::vector<int>> starRotation(std::vector<std::vector<int>> matrix, int width, std::vector<int> center, int t) {
	auto res = [&matrix](int posx, int posy, int iter, int times)
	{
		vector<int*>temp;
		vector<int>resul;
		for (size_t i = 0; i < 2; i++, posx += iter + 1)
			temp.push_back(&matrix[posy][posx]);
		for (size_t i = 0; i < 2; i++, posy += iter + 1)
			temp.push_back(&matrix[posy][posx]);
		for (size_t i = 0; i < 2; i++, posx -= iter + 1)
			temp.push_back(&matrix[posy][posx]);
		for (size_t i = 0; i < 2; i++, posy -= iter + 1)
			temp.push_back(&matrix[posy][posx]);
		for (auto x : temp)
			resul.push_back(*x);
		for (size_t i = 0; i < temp.size(); i++)
			*temp[(i + times) % 8] = resul[i];
	};
	for (size_t i = 0, y = center[0] - 1, x = center[1] - 1; i < (width - 1) / 2; i++, x--, y--)
		res(x, y, i, t);
	return matrix;
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
		for (size_t c = 0; c < grid.size() - 2; c += 3)
		{
			getq(i, c);
			if (check() == false)
				return false;
			else
				clear();
		}
	return true;
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

std::vector<std::vector<int>> contoursShifting(std::vector<std::vector<int>> matrix) {
	auto copy = [&](int x, int y)
	{
		vector<vector<int*>>temp(matrix.size() - y * 2, vector<int*>(matrix[y].size() - x * 2));
		for (size_t i = 0, z = y; i < matrix.size() - y * 2; i++, z++)
			for (size_t c = 0, k = x; c < temp[i].size(); c++, k++)
				temp[i][c] = &matrix[z][k];
		return temp;
	};
	auto parse = [](vector<vector<int*>>vec, int times)
	{
		int x = 0, y = 0;
		vector<int**>res;
		vector<int>temp;
		if (vec.size() == 1)
			for (size_t i = 0; i < vec[0].size(); i++)
				res.push_back(&vec[0][i]);
		else if (vec[0].size() == 1)
			for (size_t i = 0; i < vec.size(); i++)
				res.push_back(&vec[i][0]);
		else
		{
			for (; x < vec[y].size() - 1; x++)
				res.push_back(&vec[y][x]);
			for (; y < vec.size() - 1; y++)
				res.push_back(&vec[y][x]);
			for (; x > 0; x--)
				res.push_back(&vec[y][x]);
			for (; y > 0; y--)
				res.push_back(&vec[y][x]);
		}
		for (auto n : res)
			temp.push_back(**n);
		if (times % 2 != 0)
		{
			for (size_t i = 1; i < res.size(); i++)
				**res[i] = temp[i - 1];
			**res[0] = temp[temp.size() - 1];
		}
		else
		{
			for (int i = res.size() - 2; i >= 0; i--)
				**res[i] = temp[i + 1];
			**res[res.size() - 1] = temp[0];
		}
	};
	for (size_t i = 1, x = 0, y = 0; x < matrix[0].size() - x && y < matrix.size() - y; x++, y++, i++)
		parse(copy(x, y), i);
	return matrix;
}

int polygonPerimeter(std::vector<std::vector<bool>> v) {
	int result = 0;
	for (int y = 0; y < v.size(); y++)
		for (int x = 0; x < v[y].size(); x++)
		{
			if (v[y][x] == true)
			{
				result += (y == 0 || y == v.size() - 1) + (x == 0 || x == v[y].size() - 1);
				if (y - 1 >= 0)
					result += v[y - 1][x] == false;
				if (y + 1 < v.size())
					result += v[y + 1][x] == false;
				if (x - 1 >= 0)
					result += v[y][x - 1] == false;
				if (x + 1 < v[y].size())
					result += v[y][x + 1] == false;
			}
		}
	return result;
}

std::vector<int> gravitation(std::vector<std::string> rows) {
	vector<int>result;
	int min = rows.size();
	for (size_t i = 0; i < rows[0].size(); i++)
	{
		int counter = 0;
		for (size_t c = 0, x = 0; c < rows.size(); c++)
		{
			if (rows[c][i] == '#')
				x++;
			if (x > 0)
				counter += rows[c][i] == '.';
		}
		if (counter < min)
		{
			min = counter;
			result.clear();
			result.push_back(i);
		}
		else if (counter == min)
			result.push_back(i);
	}
	return result;
}

bool isInformationConsistent(std::vector<std::vector<int>> vec) {
	for (int i = 0, mem = 0; i < vec[0].size(); i++, mem = 0)
		for (size_t c = 0; c < vec.size(); c++)
		{
			if (mem == 0 && vec[c][i] != 0)
				mem = vec[c][i];
			if (vec[c][i] != mem && vec[c][i] != 0)
				return false;
		}
	return true;
}

bool correctNonogram(int size, std::vector<std::vector<std::string>> vec) {
	regex reg("[0-9]*");
	for (int i = vec.size() - size, counter = 0; i < vec.size(); i++, counter = 0)
	{
		vector<int>cell, num;
		for (size_t c = 0; c < vec[i].size(); c++)
		{
			if (regex_match(vec[i][c].c_str(), reg))
				num.push_back(atoi(vec[i][c].c_str()));
			if (vec[i][c] == "#")
				counter++;
			if ((vec[i][c] == "." || c == vec[i].size() - 1) && counter > 0)
			{
				cell.push_back(counter);
				counter = 0;
			}
		}
		if (num != cell)
			return false;
	}
	for (int i = vec[0].size() - size, counter = 0; i < vec[0].size(); i++, counter = 0)
	{
		vector<int>cell, num;
		for (size_t c = 0; c < vec.size(); c++)
		{
			if (regex_match(vec[c][i].c_str(), reg))
				num.push_back(atoi(vec[c][i].c_str()));
			if (vec[c][i] == "#")
				counter++;
			if ((vec[c][i] == "." || c == vec.size() - 1) && counter > 0)
			{
				cell.push_back(counter);
				counter = 0;
			}
		}
		if (num != cell)
			return false;
	}
	return true;
}

std::vector<int> shuffledArray(std::vector<int> vec) {
	int sum = 0;
	for (auto x : vec)
		sum += x;
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (sum - vec[i] == vec[i])
		{
			vec.erase(vec.begin() + i);
			break;
		}
	}
	sort(vec.begin(), vec.end());
	return vec;
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

std::vector<std::string> sortByLength(std::vector<std::string> vec) {
	for (size_t i = 0; i < vec.size(); i++)
		for (size_t c = i; c < vec.size(); c++)
			if (vec[c].size() < vec[i].size())
				swap(vec[c], vec[i]);
	return vec;
}

bool boxesPacking(std::vector<int> l, std::vector<int> w, std::vector<int> h) {
	auto s = [&](int x, int y)
	{
		swap(l[x], l[y]);
		swap(w[x], w[y]);
		swap(h[x], h[y]);
	};
	auto srt = [s](vector<int>&arr)
	{
		for (size_t i = 0; i < arr.size(); i++)
			for (size_t c = i; c < arr.size(); c++)
				if (arr[c] < arr[i])
					s(c, i);
	};
	for (size_t x = 0; x < l.size(); x++)
	{
		vector<int*>vec = { &l[x],&w[x],&h[x] };
		for (size_t i = 0; i < vec.size(); i++)
			for (size_t c = i; c < vec.size(); c++)
				if (*vec[c] < *vec[i])
					swap(*vec[c], *vec[i]);
	}
	srt(l); srt(w); srt(h);
	for (size_t i = 0; i < l.size() - 1; i++)
	{
		if (l[i] >= l[i + 1] || w[i] >= w[i + 1] || h[i] >= h[i + 1])
			return false;
	}
	return true;
}

int maximumSum(std::vector<int> a, std::vector<std::vector<int>> q) {
	vector<vector<int>>pos(a.size(), vector<int>(2));
	int total = 0;
	for (size_t i = 0; i < pos.size(); i++)
		pos[i][0] = i;
	for (size_t i = 0; i < q.size(); i++)
		for (size_t c = q[i][0]; c <= q[i][1]; c++)
			pos[c][1]++;
	for (size_t i = 0; i < pos.size(); i++)
		for (size_t c = i; c < pos.size(); c++)
			if (pos[c][1] > pos[i][1])
			{
				swap(pos[c][0], pos[i][0]);
				swap(pos[c][1], pos[i][1]);
			}
	vector<int>temp(a);
	sort(temp.rbegin(), temp.rend());
	for (size_t i = 0; i < a.size(); i++)
		a[pos[i][0]] = temp[i];
	for (size_t i = 0; i < q.size(); i++)
		for (size_t c = q[i][0]; c <= q[i][1]; c++)
			total += a[c];
	return total;
}

bool rowsRearranging(std::vector<std::vector<int>> matrix) {
	auto srt = [&]()
	{
		for (size_t i = 0; i < matrix.size(); i++)
			for (size_t c = i; c < matrix.size(); c++)
				if (matrix[c][0] < matrix[i][0])
					swap(matrix[c], matrix[i]);
	};
	srt();
	for (size_t i = 0; i < matrix[0].size(); i++)
		for (size_t c = 0; c < matrix.size() - 1; c++)
			if (matrix[c][i] >= matrix[c + 1][i])
				return false;
	return true;
}

std::vector<int> digitDifferenceSort(std::vector<int> a) {
	vector<int>result;
	auto srt = [](int x)
	{
		vector<int>temp;
		while (x > 0)
		{
			temp.push_back(x % 10);
			x /= 10;
		}
		auto mm = minmax_element(temp.begin(), temp.end());
		return *mm.second - *mm.first;
	};
	for (auto x : a)
		result.push_back(srt(x));
	for (size_t i = 0; i < result.size(); i++)
		for (size_t c = i; c < result.size(); c++)
		{
			if (result[c] <= result[i])
			{
				swap(result[c], result[i]);
				swap(a[c], a[i]);
			}
		}

	return a;
}

int uniqueDigitProducts(std::vector<int> a) {
	set<int>result;
	auto num = [&result](int x)
	{
		int res = 1;
		while (x > 0)
		{
			res *= x % 10;
			x /= 10;
		}
		result.emplace(res);
	};
	for (auto x : a)
		num(x);
	return result.size();
}

bool bishopAndPawn(std::string b, std::string p) {
	return abs(p[0] - b[0]) == abs(p[1] - b[1]);
}

int chessKnightMoves(std::string cell) {
	int x = (int)cell[0] - 96;
	int y = (int)cell[1] - 48;
	int counter = 0;
	auto check = [](auto a1, auto a2)
	{
		return (a1 > 0 && a1 <= 8 && a2 > 0 && a2 <= 8);
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

std::vector<std::string> bishopDiagonal(std::string b1, std::string b2) {
	if (b1[0] > b2[0])
		swap(b1, b2);
	if (abs(b2[0] - b1[0]) != abs(b2[1] - b1[1]))
		return vector<string>{b1, b2};
	if (b1[0] == b2[0] || b1[1] == b2[1])
		return vector<string>{b1, b2};

	auto check = [](char a, char b, int dirx, int diry)
	{
		dirx = dirx < 0 ? -1 : 1;
		diry = diry < 0 ? -1 : 1;
		while ((a > 'a' && a < 'h') && (b > '1' && b < '8'))
		{
			a += dirx;
			b += diry;
		}
		return string{ a,b };
	};
	b1 = check(b1[0], b1[1], b1[0] - b2[0], b1[1] - b2[1]);
	b2 = check(b2[0], b2[1], b2[0] - b1[0], b2[1] - b1[1]);
	return vector<string>{b1, b2};
}

bool whoseTurn(std::string p) {
	bool w1, w2, b1, b2;
	w1 = (p[0] + p[1]) % 2;
	w2 = (p[3] + p[4]) % 2;
	b1 = (p[6] + p[7]) % 2;
	b2 = (p[9] + p[10]) % 2;
	if (w1 != w2 && b1 != b2)
		return true;
	if (w1 == w2 && b1 != b2)
		return false;
	if (w1 == w2 && b1 == b2)
		return true;
	if (w1 != w2 && b1 == b2)
		return false;
}

std::vector<int> chessBishopDream(std::vector<int> board, std::vector<int> pos, std::vector<int> dir, int k) {
	auto check = [](int pos, int dir, int board)
	{
		dir = (pos / board) % 2 == 0 ? dir : -(dir);
		if (dir > 0)
			pos = pos % board;
		else
			pos = (board - 1) - (pos % board);
		return pos;
	};
	pos[0] = check(dir[0] > 0 ? pos[0] + k : board[0] - 1 - pos[0] + k, dir[0], board[0]);
	pos[1] = check(dir[1] > 0 ? pos[1] + k : board[1] - 1 - pos[1] + k, dir[1], board[1]);
	return pos;
}

