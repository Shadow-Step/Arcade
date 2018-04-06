bool newRoadSystem(std::vector<std::vector<bool>> arr) {
	vector<vector<int>>result(arr.size(), vector<int>(2));
	for (size_t i = 0; i < arr.size(); i++)
		for (size_t c = 0; c < arr[i].size(); c++)
			if (arr[i][c] == true)
			{
				result[i][0]++;
				result[c][1]++;
			}
	for (size_t i = 0; i < result.size(); i++)
		if (result[i][0] != result[i][1])
			return false;
	return true;
}

std::vector<std::vector<int>> roadsBuilding(int cities, std::vector<std::vector<int>> roads) {
	vector<vector<bool>>temp(cities, vector<bool>(cities));
	vector<vector<int>>result;
	for (auto x : roads)
		temp[x[0]][x[1]] = temp[x[1]][x[0]] = 1;
	for (int i = 0; i < temp.size(); i++)
		for (int c = 0; c < temp[i].size(); c++)
			if (c != i && temp[i][c] == 0)
			{
				result.push_back(vector<int>{i, c});
				temp[c][i] = 1;
			}
	return result;
}

bool efficientRoadNetwork(int n, std::vector<std::vector<int>> roads) {
	vector<vector<int>>temp(n, vector<int>(n));
	for (auto x : roads)
		temp[x[0]][x[1]] = temp[x[1]][x[0]] = 1;

	vector<vector<int>>dir(temp);
	for (size_t i = 0; i < temp.size(); i++)
		for (size_t c = 0; c < temp[i].size(); c++)
			if (temp[i][c] != 0)
				for (size_t x = 0; x < temp[c].size(); x++)
					dir[i][x] += temp[c][x];
	for (auto x : dir)
		for (auto c : x)
			if (c == 0)
				return n > 1 ? false : true;
	return true;
}

std::vector<std::vector<std::vector<bool>>> financialCrisis(std::vector<std::vector<bool>> road) {
	vector<vector<vector<bool>>>result(road.size(), vector<vector<bool>>(road));
	for (size_t i = 0; i < result.size(); i++)
	{
		result[i].erase(result[i].begin() + i);
		for (auto &x : result[i])
			x.erase(x.begin() + i);
	}
	return result;
}

bool namingRoads(std::vector<std::vector<int>> r) {
	map<int, vector<int>>road;
	for (size_t i = 0; i < r.size(); i++)
		road[r[i][2]] = r[i];
	for (size_t i = 0; i < road.size() - 1; i++)
		if ((road[i][0] == road[i + 1][0] || road[i][0] == road[i + 1][1]) || (road[i][1] == road[i + 1][0] || road[i][1] == road[i + 1][1]))
			return false;
	return true;
}

std::vector<std::vector<bool>> greatRenaming(std::vector<std::vector<bool>> r) {
	vector<vector<bool>>temp(r.size(), vector<bool>(r.size()));
	for (size_t i = 0; i < r.size(); i++)
		for (size_t c = 0; c < r.size(); c++)
			temp[(i + 1) % r.size()][(c + 1) % r.size()] = r[i][c];
	return temp;
}

std::vector<int> citiesConquering(int n, std::vector<std::vector<int>> r) {
	map<int, set<int>>rmap;
	vector<int>result(n, 1);
	for (auto x : r)
	{
		rmap[x[0]].emplace(x[1]);
		rmap[x[1]].emplace(x[0]);
	}
	vector<int>res;
	for (size_t i = 1; i < n; i++)
	{
		for (auto x : rmap)
			if (x.second.size() < 2)
				res.push_back(x.first);
		if (res.size() == 0)
			break;
		for (auto x : res)
		{
			for (auto &a : rmap)
				a.second.erase(x);
			result[x] = i;
			rmap.erase(x);
		}
		res.clear();
	}
	for (auto x : rmap)
		result[x.first] = -1;
	return result;

}

std::vector<std::vector<bool>> mergingCities(std::vector<std::vector<bool>> road) {
	vector<vector<bool>>result(road);
	vector<int>del;
	auto merge = [&result, &del](int x, int y)
	{
		del.push_back(y);
		for (size_t i = 0; i < result[x].size(); i++)
			result[x][i] = (result[x][i] == true || result[y][i] == true);
		for (auto &a : result)
			a[x] = a[y] == true ? true : a[x];
		result[x][x] = false;
	};
	for (size_t i = 0; i < road.size() - 1; i += 2)
		if (road[i][i + 1] == 1)
			merge(i, i + 1);
	for (int i = del.size() - 1; i >= 0; i--)
		result.erase(result.begin() + del[i]);
	for (int i = del.size() - 1; i >= 0; i--)
		for (auto &x : result)
			x.erase(x.begin() + del[i]);
	return result;
}

std::vector<std::vector<bool>> livingOnTheRoads(std::vector<std::vector<bool>> road) {
	set<vector<int>>res;
	for (int i = 0; i < road.size(); i++)
		for (int c = 0; c < road[i].size(); c++)
			if (road[i][c] == true)
				res.emplace(vector<int>{i < c ? i : c, c > i ? c : i});
	vector<vector<bool>>result(res.size(), vector<bool>(res.size(), false));
	int i = 0;
	for (auto x : res)
	{
		int c = 0;
		for (auto a : res)
		{
			if ((a != x) && (a[0] == x[0] || a[0] == x[1] || a[1] == x[0] || a[1] == x[1]))
				result[i][c] = result[c][i] = true;
			c++;
		}
		i++;
	}
	return result;
}
