#include "suite_data"

namespace cxc
{
    namespace test
    {
        namespace
        {
            const std::string GLOBAL_SUITE_NAME = "";
        }

        suite::suite(const std::string& name)
            : m_data(std::make_shared<suite::data>(global(), name))
        {
        }

        suite::suite(const suite& owner, const std::string& name)
            : m_data(std::make_shared<suite::data>(owner, name))
        {
        }

        suite::~suite()
        {
        }

        suite& suite::global()
        {
            static suite scope(GLOBAL_SUITE_NAME);
            return scope;
        }

        void suite::add(const test_case& new_case)
        {
            m_data->add(new_case);
        }

        void suite::run()
        {
            m_data->run();
        }

        void suite::setup()
        {
            m_data->setup();
        }

        void suite::release()
        {
            m_data->release();
        }

        const std::string& suite::get_name() const
        {
            return m_data->get_name();
        }

        const std::string& suite::get_path() const
        {
            return m_data->get_path();
        }

        const suite & suite::get_owner() const
        {
            return m_data->get_owner();
        }
    }
}
