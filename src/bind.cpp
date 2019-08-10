#include <iostream>
#include <iomanip>

// #include <DTL.hpp>
#include "../dtlwandbox/DTL.hpp"

int main() {
		std::cout << "hi" << "\n";
		
		using shape_t = std::uint_fast8_t;

		std::array<std::array<shape_t, 48>, 36> matrix{ {} };
		auto succeed = dtl::shape::SimpleRogueLike<shape_t>(1, 2, 3, 4, 5, 2, 5, 2).draw(matrix);
		std::cout << std::boolalpha << succeed << "\n";
		dtl::console::OutputString<shape_t>("//", "##", "%%").draw(matrix);
}