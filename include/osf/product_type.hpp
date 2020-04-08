#pragma once
#include <variant>
#include <osf/tmp.hpp>

namespace osf {
	namespace product_type {
		template <typename I, typename T>
		struct base {
			T t;
		};
		template <typename, typename...>
		struct product_type;
		template <typename... Is, typename... Ts>
		struct product_type<tmp::list_<Is...>, Ts...> : base<Is, Ts>... {};
		namespace detail {} // namespace detail

		template <typename... Ts>
		product_type(Ts...)
		        ->product_type<tmp::call_<tmp::make_sequence_<>, tmp::int_<sizeof...(Ts)>>, Ts...>;

		template <unsigned I, typename Is, typename... Ts>
		constexpr auto &get(product_type<Is, Ts...> &in) {
			using namespace tmp;
			return static_cast<base<uint_<I>, call_<index_<tmp::uint_<I>>, Ts...>> &>(in).t;
		}
		template <unsigned I, typename Is, typename... Ts>
		constexpr auto &get(const product_type<Is, Ts...> &in) {
			using namespace tmp;
			return static_cast<const base<uint_<I>, call_<index_<tmp::uint_<I>>, Ts...>> &>(in).t;
		}
		template <typename... Is1, typename... Ts1, typename... Is2, typename... Ts2>
		constexpr auto cat(const product_type<tmp::list_<Is1...>, Ts1...> &x,
		                   const product_type<tmp::list_<Is2...>, Ts2...> &y) {
			using namespace tmp;
			return product_type<list_<Is1..., uint_<Is2::value + sizeof...(Is1)>...>, Ts1...,
			                    Ts2...>{static_cast<const base<Is1, Ts1> &>(x)...,
			                            (base<uint_<Is2::value + sizeof...(Is1)>, Ts2>{
			                                    static_cast<const base<Is2, Ts2> &>(y).t})...};
		}

	} // namespace product_type
} // namespace osf