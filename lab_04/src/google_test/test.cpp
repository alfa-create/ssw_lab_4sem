#include "pch.h"
#include "Map.h"
#include <chrono>

TEST(Map, emplace_and_erase) {
	Map <int, int> map;
	map.emplace({ 123,155 });
	map.emplace({ 129,200 });
	map.emplace({ 180,900 });
	map.erase(123);
	map.erase(180);
	map.emplace({ 190,9000 });
	int i = 0;
	for (auto ptr = map.begin(); ptr != map.end(); ++ptr)
	{
		if (i == 0) EXPECT_EQ((*ptr).first, 190);
		if (i == 1) EXPECT_EQ((*ptr).first, 129);
		if (i == 0) EXPECT_EQ((*ptr).second, 9000);
		if (i == 1) EXPECT_EQ((*ptr).second, 200);
		i++;
	}
}

TEST(Map, find)
{
	Map <int, int> map;
	map.emplace({ 123,155 });
	map.emplace({ 129,200 });
	map.emplace({ 180,900 });
	map.emplace({ 195,900 });
	EXPECT_EQ((*map.find(180)).second, 900);
}

TEST(Map, size)
{
	Map <int, int> map;
	map.emplace({ 123,155 });
	map.emplace({ 129,200 });
	map.emplace({ 180,900 });
	map.emplace({ 195,900 });
	map.erase(180);
	EXPECT_EQ(map.size_map(), 3);
}

TEST(Map, rep_str)
{
	Map <int, int> map;
	map.emplace({ 123,155 });
	map.emplace({ 129,200 });
	map.emplace({ 129,200 });
	map.emplace({ 129,200 });
	EXPECT_EQ(map.size_map(), 2);
}

TEST(Map, cmp_map)
{
	Map <int, int> map1;
	Map <int, int> map2;
	map1.emplace({ 123,155 });
	map1.emplace({ 129,200 });
	map2.emplace({ 123,155 });
	map2.emplace({ 129,210 });
	EXPECT_EQ(map1 < map2, 1);
	EXPECT_EQ(map1 <= map2, 1);
	map2.erase(129);
	EXPECT_EQ(map1 < map2, 0);
	EXPECT_EQ(map1 >= map2, 1);
	map1.erase(129);
	EXPECT_EQ(map1 == map2, 1);
	EXPECT_EQ(map1 > map2, 0);
}

TEST(Map, performance)
{
	Map <int, int> map;

	auto begin = std::chrono::steady_clock::now();
	for (int i = 0; i < 10000; i++)
	{
		map.emplace({ i,i });
	}
	auto end = std::chrono::steady_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout << std::endl << "Time 10000 emplace: " << elapsed_ms.count() << "ms" << std::endl;

	begin = std::chrono::steady_clock::now();
	for (int i = 0; i < 10000; i++)
	{
		map.erase(i);
	}
	end = std::chrono::steady_clock::now();
	elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout << std::endl << "Time 10000 erase: " << elapsed_ms.count() << "ms" << std::endl;

}