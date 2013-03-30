#/**********************************************************\ 
#
# Auto-Generated Plugin Configuration file
# for ohmd
#
#\**********************************************************/

set(PLUGIN_NAME "ohmd")
set(PLUGIN_PREFIX "OHMD")
set(COMPANY_NAME "grimwire")

# ActiveX constants:
set(FBTYPELIB_NAME ohmdLib)
set(FBTYPELIB_DESC "ohmd 1.0 Type Library")
set(IFBControl_DESC "ohmd Control Interface")
set(FBControl_DESC "ohmd Control Class")
set(IFBComJavascriptObject_DESC "ohmd IComJavascriptObject Interface")
set(FBComJavascriptObject_DESC "ohmd ComJavascriptObject Class")
set(IFBComEventSource_DESC "ohmd IFBComEventSource Interface")
set(AXVERSION_NUM "1")

# NOTE: THESE GUIDS *MUST* BE UNIQUE TO YOUR PLUGIN/ACTIVEX CONTROL!  YES, ALL OF THEM!
set(FBTYPELIB_GUID 77b1caeb-7428-5cc6-9358-ae52b4189548)
set(IFBControl_GUID 02d632d3-b777-5954-ad99-1d13adec2efc)
set(FBControl_GUID 0613002a-ee02-54c0-9fc3-e09939fbfe31)
set(IFBComJavascriptObject_GUID 2a4d121a-f435-536c-8f09-48bb3f246acb)
set(FBComJavascriptObject_GUID 6dec8409-f005-55af-b929-adf457a2cd60)
set(IFBComEventSource_GUID 557bbf06-2034-5e99-9e96-e26204c2bb09)
if ( FB_PLATFORM_ARCH_32 )
    set(FBControl_WixUpgradeCode_GUID 23639116-8e0c-56c6-9eb8-45fe99c727ea)
else ( FB_PLATFORM_ARCH_32 )
    set(FBControl_WixUpgradeCode_GUID e62ac4a1-71d8-5ce2-800f-f88ddd61efd7)
endif ( FB_PLATFORM_ARCH_32 )

# these are the pieces that are relevant to using it from Javascript
set(ACTIVEX_PROGID "grimwire.ohmd")
set(MOZILLA_PLUGINID "grimwire.com/ohmd")

# strings
set(FBSTRING_CompanyName "grimwire")
set(FBSTRING_PluginDescription "oculus rift head-mounted display integration")
set(FBSTRING_PLUGIN_VERSION "1.0.0.0")
set(FBSTRING_LegalCopyright "Copyright 2013 grimwire")
set(FBSTRING_PluginFileName "np${PLUGIN_NAME}.dll")
set(FBSTRING_ProductName "ohmd")
set(FBSTRING_FileExtents "")
if ( FB_PLATFORM_ARCH_32 )
    set(FBSTRING_PluginName "ohmd")  # No 32bit postfix to maintain backward compatability.
else ( FB_PLATFORM_ARCH_32 )
    set(FBSTRING_PluginName "ohmd_${FB_PLATFORM_ARCH_NAME}")
endif ( FB_PLATFORM_ARCH_32 )
set(FBSTRING_MIMEType "application/x-grimwire-ohmd")

# Uncomment this next line if you're not planning on your plugin doing
# any drawing:

set (FB_GUI_DISABLED 1)

# Mac plugin settings. If your plugin does not draw, set these all to 0
set(FBMAC_USE_QUICKDRAW 0)
set(FBMAC_USE_CARBON 0)
set(FBMAC_USE_COCOA 0)
set(FBMAC_USE_COREGRAPHICS 0)
set(FBMAC_USE_COREANIMATION 0)
set(FBMAC_USE_INVALIDATINGCOREANIMATION 0)

# If you want to register per-machine on Windows, uncomment this line
#set (FB_ATLREG_MACHINEWIDE 1)
