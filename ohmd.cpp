/**********************************************************\

  Auto-generated ohmd.cpp

  This file contains the auto-generated main plugin object
  implementation for the ohmd project

\**********************************************************/

#include <OVR.h>

#include "ohmdAPI.h"
#include "ohmd.h"

OVR::Ptr<OVR::DeviceManager> ohmd::pManager;
OVR::Ptr<OVR::HMDDevice>     ohmd::pHMD;
OVR::Ptr<OVR::SensorDevice>  ohmd::pSensor;
OVR::SensorFusion            ohmd::SFusion;

///////////////////////////////////////////////////////////////////////////////
/// @fn ohmd::StaticInitialize()
///
/// @brief  Called from PluginFactory::globalPluginInitialize()
///
/// @see FB::FactoryBase::globalPluginInitialize
///////////////////////////////////////////////////////////////////////////////
void ohmd::StaticInitialize()
{
    // Place one-time initialization stuff here; As of FireBreath 1.4 this should only
    // be called once per process

	// init ovr
	using namespace OVR;
	System::Init(Log::ConfigureDefaultLog(LogMask_All));
	pManager = *DeviceManager::Create();
	pHMD     = *pManager->EnumerateDevices<HMDDevice>().CreateDevice();
	if (!pHMD)
        return;

	// setup sensor
	pSensor  = *pHMD->GetSensor();
	if (pSensor) {
		// pSensor->SetRange(SensorRange(4 * 9.81f, 8 * Math<float>::Pi, 1.0f), true); :TODO: needed?
		SFusion.AttachToSensor(pSensor);
	}
}

///////////////////////////////////////////////////////////////////////////////
/// @fn ohmd::StaticInitialize()
///
/// @brief  Called from PluginFactory::globalPluginDeinitialize()
///
/// @see FB::FactoryBase::globalPluginDeinitialize
///////////////////////////////////////////////////////////////////////////////
void ohmd::StaticDeinitialize()
{
    // Place one-time deinitialization stuff here. As of FireBreath 1.4 this should
    // always be called just before the plugin library is unloaded

	pSensor.Clear();
    pHMD.Clear();
    pManager.Clear();
	OVR::System::Destroy();
}

///////////////////////////////////////////////////////////////////////////////
/// @brief  ohmd constructor.  Note that your API is not available
///         at this point, nor the window.  For best results wait to use
///         the JSAPI object until the onPluginReady method is called
///////////////////////////////////////////////////////////////////////////////
ohmd::ohmd()
{
}

///////////////////////////////////////////////////////////////////////////////
/// @brief  ohmd destructor.
///////////////////////////////////////////////////////////////////////////////
ohmd::~ohmd()
{
    // This is optional, but if you reset m_api (the shared_ptr to your JSAPI
    // root object) and tell the host to free the retained JSAPI objects then
    // unless you are holding another shared_ptr reference to your JSAPI object
    // they will be released here.
    releaseRootJSAPI();
    m_host->freeRetainedObjects();
}

void ohmd::onPluginReady()
{
    // When this is called, the BrowserHost is attached, the JSAPI object is
    // created, and we are ready to interact with the page and such.  The
    // PluginWindow may or may not have already fire the AttachedEvent at
    // this point.
}

void ohmd::shutdown()
{
    // This will be called when it is time for the plugin to shut down;
    // any threads or anything else that may hold a shared_ptr to this
    // object should be released here so that this object can be safely
    // destroyed. This is the last point that shared_from_this and weak_ptr
    // references to this object will be valid
}

///////////////////////////////////////////////////////////////////////////////
/// @brief  Creates an instance of the JSAPI object that provides your main
///         Javascript interface.
///
/// Note that m_host is your BrowserHost and shared_ptr returns a
/// FB::PluginCorePtr, which can be used to provide a
/// boost::weak_ptr<ohmd> for your JSAPI class.
///
/// Be very careful where you hold a shared_ptr to your plugin class from,
/// as it could prevent your plugin class from getting destroyed properly.
///////////////////////////////////////////////////////////////////////////////
FB::JSAPIPtr ohmd::createJSAPI()
{
    // m_host is the BrowserHost
    return boost::make_shared<ohmdAPI>(FB::ptr_cast<ohmd>(shared_from_this()), m_host);
}

bool ohmd::onMouseDown(FB::MouseDownEvent *evt, FB::PluginWindow *)
{
    //printf("Mouse down at: %d, %d\n", evt->m_x, evt->m_y);
    return false;
}

bool ohmd::onMouseUp(FB::MouseUpEvent *evt, FB::PluginWindow *)
{
    //printf("Mouse up at: %d, %d\n", evt->m_x, evt->m_y);
    return false;
}

bool ohmd::onMouseMove(FB::MouseMoveEvent *evt, FB::PluginWindow *)
{
    //printf("Mouse move at: %d, %d\n", evt->m_x, evt->m_y);
    return false;
}
bool ohmd::onWindowAttached(FB::AttachedEvent *evt, FB::PluginWindow *)
{
    // The window is attached; act appropriately
    return false;
}

bool ohmd::onWindowDetached(FB::DetachedEvent *evt, FB::PluginWindow *)
{
    // The window is about to be detached; act appropriately
    return false;
}

