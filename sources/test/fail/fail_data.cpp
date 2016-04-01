#include "fail_data"
#include <sstream>

namespace cxc
{
    namespace test
    {
        fail::data::data(const std::string& message, const scope& source, 
                         const std::string& file, int line)
            : m_message(message),
              m_source(source),
              m_file(file),
              m_line(line)
        {
            std::stringstream output;
            output << "FAIL!"
                      "\n > Source: " << source.get_full_name() 
                   << "\n > File: " << file 
                   << "\n > Line: " << line
                   << "\n > Message : " << message;
            m_output = output.str();
        }

        fail::data::~data()
        {
        }

        const scope& fail::data::get_source() const
        {
            return m_source;
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
