#include <iostream>
#include <fstream>
#include <combaseapi.h>

int main(int argc, char* argv[])
{
	/*
	typedef struct _GUID {
	  unsigned long  Data1;
	  unsigned short Data2;
	  unsigned short Data3;
	  unsigned char  Data4[8];
	}
	*/
	HRESULT result;
	GUID pguid;
	for (int i = 0; i < 10; ++i)
	{
		result = CoCreateGuid(&pguid);
		
		std::cout << std::hex << pguid.Data1 << "-" << std::hex << pguid.Data2 << "-" << std::hex << pguid.Data3 << "-";
		for (int i = 0; i < 7; ++i)
		{
			std::cout << std::hex << (int)pguid.Data4[i];
		}
		std::cout << std::endl;
	}

	std::cin.get();
	return 0;
}

