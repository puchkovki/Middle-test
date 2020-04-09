#include <logger.hpp>

#include <ostream>

int main() {
	// make new object
	output_log::logger_t<std::ostream> logger(std::cout);
	
	
	// output hello
	logger.Info("hello");
	std::cout << std::endl;
	return EXIT_SUCCESS;
}
