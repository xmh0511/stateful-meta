#include <iostream>
template<int N>
struct state
{
	static constexpr int value = N;
	friend auto create(state<N>);
};

template<int N>
struct generat_state
{
	friend auto create(state<N>) {
		return state<N>{};
	}
	static constexpr int value = N;
};

template struct generat_state<1>;

template<int N, typename = decltype(create(state<N - 1>{})) >
std::size_t step(float, state<N>,int res = generat_state<N>::value)
{
	//std::cout << "command " << N<< std::endl;
	return (N - 1);
}

template<int N, typename = decltype(create(state<N>{}))>
std::size_t step(int, state<N>, int res = step<N + 1>(N + 1, state<N + 1>{}))
{
	//std::cout << "commandnext " << N << std::endl;
	//std::cout << typeid(decltype(create(state<N + 1>{}))).name() << std::endl;
	return res;
}
int main()
{
	auto r = step<1>(0, state<1>{});
	auto r0 = step<1>(0, state<1>{});
	std::cout << r << std::endl;
	std::cout << r0 << std::endl;
	std::cin.get();
	return 0;
}
