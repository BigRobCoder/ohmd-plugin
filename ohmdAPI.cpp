/**********************************************************\

  Auto-generated ohmdAPI.cpp

\**********************************************************/

#include "JSObject.h"
#include "variant_list.h"
#include "DOM/Document.h"
#include "global/config.h"

#include <OVR.h>

#include "ohmdAPI.h"

///////////////////////////////////////////////////////////////////////////////
/// @fn ohmdPtr ohmdAPI::getPlugin()
///
/// @brief  Gets a reference to the plugin that was passed in when the object
///         was created.  If the plugin has already been released then this
///         will throw a FB::script_error that will be translated into a
///         javascript exception in the page.
///////////////////////////////////////////////////////////////////////////////
ohmdPtr ohmdAPI::getPlugin()
{
    ohmdPtr plugin(m_plugin.lock());
    if (!plugin) {
        throw FB::script_error("The plugin is invalid");
    }
    return plugin;
}

std::string ohmdAPI::get_version()
{
    return FBSTRING_PLUGIN_VERSION;
}

FB::VariantMap ohmdAPI::get_deviceInfo()
{
	FB::VariantMap hmdMap;
	ohmdPtr plugin = getPlugin();
	if (!plugin->pHMD) {
		hmdMap["error"]   = true;
		hmdMap["message"] = "HMD Device not found";
	} else {
		OVR::HMDInfo hmdInfo;
		plugin->pHMD->GetDeviceInfo(&hmdInfo);
		FB::VariantList DistortionK;
		DistortionK.push_back(hmdInfo.DistortionK[0]);
		DistortionK.push_back(hmdInfo.DistortionK[1]);
		DistortionK.push_back(hmdInfo.DistortionK[2]);
		DistortionK.push_back(hmdInfo.DistortionK[3]);
		hmdMap["error"]                  = false;
		hmdMap["displayDeviceName"]      = hmdInfo.DisplayDeviceName;
		hmdMap["interpupillaryDistance"] = hmdInfo.InterpupillaryDistance;
		hmdMap["distortionK"]            = DistortionK;
	}
	return hmdMap;
}

FB::VariantMap ohmdAPI::get_orientation()
{
	FB::VariantMap hmdMap;
	ohmdPtr plugin = getPlugin();
	if (!plugin->pHMD || !plugin->pSensor){
		hmdMap["error"]   = true;
		hmdMap["message"] = "HMD Device not found";
	} else {
		OVR::Quatf hmdOrient = plugin->SFusion.GetOrientation();
		float yaw=0.0f, pitch=0.0f, roll=0.0f;
		hmdOrient.GetEulerAngles<OVR::Axis_Y, OVR::Axis_X, OVR::Axis_Z>(&yaw, &pitch, &roll);
		FB::VariantList OrientationK;
		OrientationK.push_back(yaw);
		OrientationK.push_back(pitch);
		OrientationK.push_back(roll);
		hmdMap["error"]       = false;
		hmdMap["orientation"] = OrientationK;
	}
	return hmdMap;
}

FB::VariantMap ohmdAPI::get_acceleration()
{
	FB::VariantMap hmdMap;
	ohmdPtr plugin = getPlugin();
	if (!plugin->pHMD || !plugin->pSensor){
		hmdMap["error"]   = true;
		hmdMap["message"] = "HMD Device not found";
	} else {
		// :TODO:
		hmdMap["error"]   = true;
		hmdMap["message"] = "Property not yet implemented";
	}
	return hmdMap;
}

FB::VariantMap ohmdAPI::get_angularVelocity()
{
	FB::VariantMap hmdMap;
	ohmdPtr plugin = getPlugin();
	if (!plugin->pHMD || !plugin->pSensor){
		hmdMap["error"]   = true;
		hmdMap["message"] = "HMD Device not found";
	} else {
		// :TODO:
		hmdMap["error"]   = true;
		hmdMap["message"] = "Property not yet implemented";
	}
	return hmdMap;
}
