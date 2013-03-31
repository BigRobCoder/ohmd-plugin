/**********************************************************\

  Auto-generated ohmdAPI.h

\**********************************************************/

#include <string>
#include <sstream>
#include <boost/weak_ptr.hpp>
#include "JSAPIAuto.h"
#include "BrowserHost.h"
#include "ohmd.h"

#ifndef H_ohmdAPI
#define H_ohmdAPI

class ohmdAPI : public FB::JSAPIAuto
{
public:
    ////////////////////////////////////////////////////////////////////////////
    /// @fn ohmdAPI::ohmdAPI(const ohmdPtr& plugin, const FB::BrowserHostPtr host)
    ///
    /// @brief  Constructor for your JSAPI object.
    ///         You should register your methods, properties, and events
    ///         that should be accessible to Javascript from here.
    ///
    /// @see FB::JSAPIAuto::registerMethod
    /// @see FB::JSAPIAuto::registerProperty
    /// @see FB::JSAPIAuto::registerEvent
    ////////////////////////////////////////////////////////////////////////////
    ohmdAPI(const ohmdPtr& plugin, const FB::BrowserHostPtr& host) :
        m_plugin(plugin), m_host(host)
    {
        //registerMethod("echo",      make_method(this, &ohmdAPI::echo));
        
        registerProperty("version", make_property(this, &ohmdAPI::get_version));
        registerProperty("deviceInfo", make_property(this, &ohmdAPI::get_deviceInfo));
        registerProperty("orientation", make_property(this, &ohmdAPI::get_orientation));
        registerProperty("acceleration", make_property(this, &ohmdAPI::get_acceleration));
        registerProperty("angularVelocity", make_property(this, &ohmdAPI::get_angularVelocity));
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @fn ohmdAPI::~ohmdAPI()
    ///
    /// @brief  Destructor.  Remember that this object will not be released until
    ///         the browser is done with it; this will almost definitely be after
    ///         the plugin is released.
    ///////////////////////////////////////////////////////////////////////////////
    virtual ~ohmdAPI() {};

    ohmdPtr getPlugin();

	// exported API
    std::string get_version();
    FB::VariantMap get_deviceInfo();
    FB::VariantMap get_orientation();
    FB::VariantMap get_acceleration();
    FB::VariantMap get_angularVelocity();
    //FB::variant echo(const FB::variant& msg);
    
    // Event helpers
    //FB_JSAPI_EVENT(test, 0, ());
    //FB_JSAPI_EVENT(echo, 2, (const FB::variant&, const int));

private:
    ohmdWeakPtr m_plugin;
    FB::BrowserHostPtr m_host;
};

#endif // H_ohmdAPI

