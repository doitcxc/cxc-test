#include "suite_data"
#include <algorithm>

namespace cxc
{
    namespace test
    {
        class suite::data
        {
        public:
            void bind();

            suite& m_owner;
            std::string m_name;
            std::string m_path;
            std::deque<test_case> m_cases;
            std::map<std::string, suite> m_scope;
        private:
        };

        suite::suite(const std::string& name)
            : m_owner(global()), m_name(name)
        {
            bind();
        }

        suite::suite(const suite& owner, const std::string& name)
            : m_owner(owner), m_name(name)
        {
            bind();
        }

        suite::suite()
            : m_owner(*this), m_name(NAME_GLOBAL)
        {
        }

        void suite::bind()
        {
            if (m_owner.m_scope.find(m_name) != m_owner.m_scope.end())
                std::runtime_error("TODO: text");
            m_owner.m_scope[m_name] = *this;
            m_path = m_owner.get_path() + PATH_DELIMITER + m_owner.get_name();
        }

        suite::~suite()
        {
        }

        suite& suite::global()
        {
            static suite scope;
            return scope;
        }

        void suite::add(const test_case& new_case)
        {
            m_cases.push_back(new_case);
        }

        void suite::run()
        {
            setup();
            std::for_each(m_cases.begin(), m_cases.end(),
                [this](test_case& current) {
                    try
                    {
                        current(*this);
                    }
                    catch (std::exception& e)
                    {
                        // TODO: hierarchy of abort/ignore test exceptions
                    }
                }
            );
            std::for_each(m_scope.begin(), m_scope.end(),
                [this](suite& current) {
                    current.run();
                }
            );
            release();
        }

        void suite::setup()
        {
        }

        void suite::release()
        {
        }

        const std::string& suite::get_name() const
        {
            return m_name;
        }

        const std::string& suite::get_path() const
        {
            return m_path;
        }
    }
}
