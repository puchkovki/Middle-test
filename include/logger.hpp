#include <nlohmann/json.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <sstream>

// for convenience
using json = nlohmann::json;

namespace get_current {
	std::string time() {
                std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
                std::time_t now_time = std::chrono::system_clock::to_time_t(now);
                return std::string(std::ctime(&now_time));
        }

        std::string thread_id() {
                std::stringstream ss;
                ss << std::this_thread::get_id();
                return ss.str();
        }
}

using namespace get_current;

namespace output_log {

template<typename T>
class logger_t {

public:
	T& m_output;

	logger_t(T& output) :
	m_output(output) {


	}

	//json output format
	// {"time": time, "message": message, "threadId": threadId}
	auto Info(const std::string& message) -> void {

		json j;
		j["time"] = time();
		j["message"] = message;
		j["threadId"] = thread_id();

		m_output << j;
	}
};
}
