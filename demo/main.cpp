#include <logger.hpp>

#include <ostream>

int main() {
	log::logger_t<std::ostream> logger(std::cout);

	logger.Info("hello");
}
