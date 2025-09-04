#include "Random.hpp"

std::mt19937& Random::mt() {
	thread_local static std::mt19937 instance{
		static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count())
	};
	return instance;
}

void Random::SetSeed(unsigned int seed) {
	mt() = std::mt19937(seed);
}
