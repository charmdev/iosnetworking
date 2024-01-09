#ifndef STATIC_LINK
#define IMPLEMENT_API
#endif

#if defined(HX_WINDOWS) || defined(HX_MACOS) || defined(HX_LINUX)
#define NEKO_COMPATIBLE
#endif

#include <hx/CFFI.h>
#include "Utils.h"

using namespace iosnetworking;

static AutoGCRoot* _iosnetworking_onSuccess;

static void iosnetworking_addConversionListenerCallback(value onSuccess) {
	_iosnetworking_onSuccess = new AutoGCRoot(onSuccess);
}
DEFINE_PRIM (iosnetworking_addConversionListenerCallback, 1);

extern "C" void iosnetworking_returnConversionSuccess(const char* responce)
{
	printf("printf iosnetworking responce: %s\n", responce);

	val_call1(_iosnetworking_onSuccess->get(), alloc_string(responce));
}

static void iosnetworking_http_request(value urlValue, value methodValue, value headerValue, value parametersValue) {
	httpRequest(val_string(urlValue), val_string(methodValue), val_string(headerValue), val_string(parametersValue));
}
DEFINE_PRIM (iosnetworking_http_request, 4);

extern "C" void iosnetworking_main() {
	val_int(0); // Fix Neko init
	
}
DEFINE_ENTRY_POINT (iosnetworking_main);

extern "C" int iosnetworking_register_prims() { return 0; }
