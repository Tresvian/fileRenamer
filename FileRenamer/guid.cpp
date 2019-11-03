#include "guid.h"

std::string createGuid()
{
	// If we want to add in error checking to result..
	HRESULT result;
	GUID pguid;
	std::string returnResult;
	for (int i = 0; i < 10; ++i)
	{
		result = CoCreateGuid(&pguid);

		std::stringstream sstream;

		sstream << std::hex << pguid.Data1 << "-" << std::hex << pguid.Data2 << "-" << std::hex << pguid.Data3 << "-";
		for (int i = 0; i < 7; ++i)
		{
			std::cout << std::hex << (int)pguid.Data4[i];
		}
		return sstream.str();
	}
}