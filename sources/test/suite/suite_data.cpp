#include "suite_data"
#include <algorithm>
#include <stdexcept>

namespace cxc
{
    namespace test
    {
        namespace
        {
            const std::string SUITE_PATH_DELIMITER = "/";
        }

        suite::data::data(suite& self, const suite& owner, const std::string& name)
            : m_self(self), m_owner(owner), m_name(name)
        {
            data& owner_data = *m_owner.m_data;
            if (owner_data.m_scope.find(name) != owner_data.m_scope.end())
            {
                throw std::runtime_error("Test suite with such name \"" + name + 
                        "\" is already presented in the test scope " + owner.get_path());
            }
            owner_data.m_scope.insert(std::make_pair(name, self));
            m_path = owner.get_path() + SUITE_PATH_DELIMITER + owner.get_name();
        }

        suite::data::~data()
        {
        }

        void suite::data::add(const test_case& new_case)
        {
            m_cases.push_back(new_case);
        }

        void suite::data::run()
        {
            std::for_each(m_cases.begin(), m_cases.end(),
                [this](const test_case& current) {
                    current(this->m_self);
                }
            );
            std::for_each(m_scope.begin(), m_scope.end(),
                [](std::pair<const std::string, suite>& value) {
                    suite current = value.second;
                    current.run();
                }
            );
        }

        void suite::data::setup()
        {
        }

        void suite::data::release()
        {
        }

        const std::string& suite::data::get_name() const
        {
            return m_name;
        }

        const std::string& suite::data::get_path() const
        {
            return m_path;
        }

        const suite& suite::data::get_owner() const
        {
            return m_owner;
        }
    }
}
