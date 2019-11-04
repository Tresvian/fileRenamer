#include "guid.h"

std::string createGuid()
{
	/*
	If we want to add in error checking to result, then do something with the 'result'
	 Real return is the returnResult as a string. The format of the raw GUID is:
	typedef struct _GUID {
		unsigned long  Data1;
		unsigned short Data2;
		unsigned short Data3;
		unsigned char  Data4[8];
	}
	*/
	HRESULT result;
	GUID pguid;
	std::string returnResult;

	for (int i = 0; i < 10; ++i)
	{
		result = CoCreateGuid(&pguid);

		// Creating hex strings requires the use of a stringStream
		std::stringstream sstream;

		sstream << std::hex << pguid.Data1 << "-" << std::hex << pguid.Data2 << "-" << std::hex << pguid.Data3 << "-";
		for (int i = 0; i < 7; ++i)
		{
			std::cout << std::hex << (int)pguid.Data4[i];
		}
		return sstream.str();
	}
}