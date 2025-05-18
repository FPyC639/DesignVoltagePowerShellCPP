#pragma once
#include <string>


using namespace System;
using namespace System::Collections::ObjectModel;
using namespace System::Management::Automation;
using namespace System::Runtime::InteropServices;



namespace CPPClassLib {
	public ref class BatteryStats
	{
		// TODO: Add your methods for this class here.
	public:
		String^ GetDesignedCapacity();
		String^ GetFullChargedCapacity();
	private:
		String^ retrievefn(Collection<PSObject^>^ a);
	};
}
