#include "suite_data"

namespace cxc
{
    namespace test
    {
        namespace
        {
            const std::string PATH_DELIMITER = "/";
            const std::string NAME_GLOBAL = "";
        }

        suite::data::data(const suite& owner, const std::string& name)
            : m_owner(owner), m_name(name)
        {

        }
    }
}