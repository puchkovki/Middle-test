namespace log {

template<typename T>
class logger_t {

	T& m_output;

	logger_t(T& output);

	//json output format
	// {"time": time, "message": message, "threadId": threadId}
	auto Info(const std::string& message) -> void {

		json j;
		j["time"] = get_current_time();
		j["message"] = message;
		j["threadId"] = std::this_thread::get_id();

		m_output << j;
	}
}
