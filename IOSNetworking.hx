import haxe.ds.StringMap;
import haxe.Json;

class IOSNetworking {

	private static var s_initialized:Bool = false;

	public static function Initialize() : Void
	{
		if (s_initialized)
			return;

		s_initialized = true;
	}	

	public static function httpRequest(url:String, method:String, header:StringMap<String>, parameters:StringMap<String>, onData:String->Void, onError:String->Void) {

		Initialize();

		iosnetworking_addConversionListenerCallback(onData);

		trace("IOSNetworking httpRequest", url, header, parameters);

		return iosnetworking_http_request(url, method, Json.stringify(header, null, "    "), Json.stringify(parameters, null, "    "));
	}
	
	private static var iosnetworking_addConversionListenerCallback = cpp.Lib.load("iosnetworking", "iosnetworking_addConversionListenerCallback", 1);

	private static var iosnetworking_http_request = cpp.Lib.load("iosnetworking", "iosnetworking_http_request", 4);
	
}
