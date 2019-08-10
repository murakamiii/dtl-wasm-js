#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
// #include <DTL.hpp>
#include "../dtlwandbox/DTL.hpp"
#include <emscripten/bind.h>

// int main() {
// 		std::cout << "hi" << "\n";
		
// 		using shape_t = std::uint_fast8_t;

// 		std::array<std::array<shape_t, 48>, 36> matrix{ {} };
// 		auto succeed = dtl::shape::SimpleRogueLike<shape_t>(1, 2, 3, 4, 5, 2, 5, 2).draw(matrix);
// 		std::cout << std::boolalpha << succeed << "\n";
// 		dtl::console::OutputString<shape_t>("//", "##", "%%").draw(matrix);
// }

int plusOne(int number) {
	return number + 1;
}

std::vector<std::vector<std::uint_fast8_t>>getSimpleRogueLike() {
	using shape_t = std::uint_fast8_t;

	std::array<std::array<shape_t, 48>, 36> matrix{ {} };
	dtl::shape::SimpleRogueLike<shape_t>(1, 2, 3, 4, 5, 2, 5, 2).draw(matrix);

	std::vector<std::vector<shape_t>> vec;
	for (auto &&row : matrix)
	{
		vec.push_back(std::vector<shape_t>(std::begin(row), std::end(row)));
	}
	return vec;
}

EMSCRIPTEN_BINDINGS(my_module) {
	emscripten::function("plusOne", &plusOne);
	emscripten::function("getSimpleRogueLike", &getSimpleRogueLike);

	emscripten::register_vector<std::vector<std::uint_fast8_t>>("std::vector<std::vector<std::uint_fast8_t>>");
	emscripten::register_vector<std::uint_fast8_t>("std::vector<std::uint_fast8_t>");
}