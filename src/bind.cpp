#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
// #include <DTL.hpp>
#include "dtlwandbox/DTL.hpp"
#include <emscripten/bind.h>

/**
 * @fn
 * see https://github.com/Kasugaccho/DungeonTemplateLibrary/
 * https://github.com/Kasugaccho/DungeonTemplateLibrary/blob/8e32c732b1/include/DTL/Shape/SimpleRogueLike.hpp
 * 
 */
std::vector<std::vector<int>>getSimpleRogueLike(
		int map_witdh,
		int map_height,
		int room_value,
		int road_value,
		int division_min,
		int division_rand_max,
		int room_min_x,
		int room_rand_max_x,
		int room_min_y,
		int room_rand_max_y
) {
	using shape_t = std::uint_fast8_t;

	std::vector<std::vector<shape_t>> matrix{};
	for (int i = 0; i < map_height; i++)
	{
		matrix.push_back(std::vector<shape_t>(map_witdh));
	}
	dtl::shape::SimpleRogueLike<shape_t>(
		room_value, 
		road_value, 
		division_min,
		division_rand_max,
		room_min_x, 
		room_rand_max_x, 
		room_min_y,
		room_rand_max_y
	).draw(matrix);

	std::vector<std::vector<int>> vec;
	for (auto &&row : matrix)
	{
		vec.push_back(std::vector<int>(std::begin(row), std::end(row)));
	}
	return vec;
}

EMSCRIPTEN_BINDINGS(my_module) {
	emscripten::function("getSimpleRogueLike", &getSimpleRogueLike);

	emscripten::register_vector<int>("vector<int>");
	emscripten::register_vector<std::vector<int>>("vector<vector<int>>");
}