#include <iostream>
template<std::size_t N>
struct state {
	friend auto declartion(state<N>);
};

template<std::size_t N>
struct add_state {
	friend auto declartion(state<N>) {
		return N;
	}
	static const std::size_t value = N;
};

template struct add_state<1>;

template<typename T>
void print(T t) {
	std::cout << t << std::endl;
}


template<std::size_t N, typename T, typename U = std::void_t<decltype(declartion(state<N - 1>{})) >>  ////2
	std::size_t next(state<N>, float, T, int b = add_state<N>::value) {
	//int b = add_state<N>::value;
	//std::cout << "add state " << b << std::endl;
	return N - 1;
}

template<std::size_t N, std::size_t M, typename U = std::void_t<decltype(declartion(state<N>{})) >>  ///1
	std::size_t next(state<N>, int/*, int  r = next(state<N + 1>{}, 0)*/, state<M>, int = 0) {
	int  r = next(state<N + 1>{}, 0, state<M + 2>{});  //通过M的变化 每次都能生成新的实例
	return r;
}
int main() 
{
	auto a = next(state<1>{}, 0,state<1>{});
	std::cout << a << std::endl;

	auto b = next(state<1>{}, 0, state<2>{});
	std::cout << b << std::endl;

	auto c = next(state<1>{}, 0, state<3>{});
	std::cout << c << std::endl;

	auto c0 = next(state<1>{}, 0, state<4>{});
	std::cout << c0 << std::endl;

	std::cin.get();
}
