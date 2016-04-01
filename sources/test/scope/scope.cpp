#include "scope_data"

namespace cxc
{
    namespace test
    {
        scope::scope(const std::string& name)
            : m_data(std::make_shared<scope::data>(*this, global(), name))
        {
        }

        scope::scope(const scope& owner, const std::string& name)
            : m_data(std::make_shared<scope::data>(*this, owner, name))
        {
        }

        scope::scope(scope::data* new_data)
            : m_data(new_data)
        {
        }

        scope::~scope()
        {
        }

        scope& scope::global()
        {
            static scope global_scope("");
            return global_scope;
        }

        void scope::run()
        {
            return m_data->run();
        }

        void scope::setup()
        {
            return m_data->setup();
        }

        void scope::release()
        {
            return m_data->release();
        }

        const std::string& scope::get_name() const
        {
            return m_data->get_name();
        }

        const std::string& scope::get_path() const
        {
            return m_data->get_path();
        }

        const std::string& scope::get_full_name() const
        {
            return m_data->get_full_name();
        }

        const scope& scope::get_owner() const
        {
            return m_data->get_owner();
        }
    }
}
