#include "scope_data"
#include <algorithm>
#include <stdexcept>

namespace cxc
{
    namespace test
    {
        namespace
        {
            const std::string SCOPE_PATH_DELIMITER = "/";
        }

        scope::data::data(scope& self, const scope& owner, const std::string& name)
            : m_self(self), m_owner(owner), m_name(name)
        {
            data& owner_data = *m_owner.m_data;
            if (owner_data.m_scope.find(name) != owner_data.m_scope.end())
            {
                throw std::runtime_error("Test suite with such name \"" + name + 
                        "\" is already presented in the test scope " + owner.get_path());
            }
            owner_data.m_scope.insert(std::make_pair(name, self));
            m_path = owner.get_full_name();
            m_full_name = m_path + SCOPE_PATH_DELIMITER + m_name;
        }

        scope::data::~data()
        {
        }

        void scope::data::run()
        {
            setup();
            std::for_each(m_scope.begin(), m_scope.end(),
                [](std::pair<const std::string, scope>& current) {
                    current.second.run();
                }
            );
            release();
        }

        void scope::data::setup()
        {
        }

        void scope::data::release()
        {
        }

        const std::string& scope::data::get_name() const
        {
            return m_name;
        }

        const std::string& scope::data::get_path() const
        {
            return m_path;
        }

        const std::string& scope::data::get_full_name() const
        {
            return m_full_name;
        }

        const scope& scope::data::get_owner() const
        {
            return m_owner;
        }
    }
}
