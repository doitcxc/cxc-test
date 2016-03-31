#include "fail_data"
#include <sstream>

namespace cxc
{
    namespace test
    {
        fail::data::data(const std::string& message, const std::string& file, int line)
            : m_message(message), m_file(file), m_line(line)
        {
            std::stringstream output;
            output << "FAIL @ " << file << '(' << line << "): " << message;
            m_output = output.str();
        }

        fail::data::~data()
        {
        }

        const std::string& fail::data::get_output() const
        {
            return m_output;
        }

        const std::string& fail::data::get_message() const
        {
            return m_message;
        }

        const std::string& fail::data::get_file() const
        {
            return m_file;
        }

        int fail::data::get_line() const
        {
            return m_line;
        }
    }
}
