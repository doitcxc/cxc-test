#include "fail_data"

namespace cxc
{
    namespace test
    {
        fail::fail(const std::string& message, const scope& source, const std::string& file, int line)
            : m_data(std::make_shared<fail::data>(message, source, file, line))
        {
        }

        const char* fail::what() const
        {
            return get_output().c_str();
        }

        const scope& fail::get_source() const
        {
            return m_data->get_source();
        }

        const std::string& fail::get_output() const
        {
            return m_data->get_output();
        }

        const std::string& fail::get_message() const
        {
            return m_data->get_message();
        }

        const std::string& fail::get_file() const
        {
            return m_data->get_file();
        }

        int fail::get_line() const
        {
            return m_data->get_line();
        }
    }
}
