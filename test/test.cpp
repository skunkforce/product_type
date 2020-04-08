#include <osf/product_type.hpp>
int main() {
	using namespace osf::product_type;
	constexpr product_type p{1, 2};
	auto a = get<0>(p);
	auto b = get<1>(p);
	(void)a;
	(void)b;
	static_assert(get<0>(p) == 1);
	static_assert(get<1>(p) == 2);
	constexpr auto p2 = p;
	constexpr auto c  = cat(p, p2);
	(void)c;
	static_assert(get<2>(c) == 1);
	static_assert(get<3>(c) == 2);
	return 0;
}
