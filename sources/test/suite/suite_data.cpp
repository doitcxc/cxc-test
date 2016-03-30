#include "suite_data"
#include <algorithm>

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
            // TODO: bind to owner
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
                [this](suite current) {
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
