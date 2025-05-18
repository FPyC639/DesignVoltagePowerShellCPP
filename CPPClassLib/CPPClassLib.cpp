#include "pch.h"
#include <vcclr.h>
#using <mscorlib.dll>
#include <msclr/marshal_cppstd.h>
#include <string>
#include "CPPClassLib.h"

using namespace System::Management::Automation;

namespace CPPClassLib {
	String^ BatteryStats::retrievefn(Collection<PSObject^>^ a) {
		return a[0]->ToString(); // Return the first result (or loop and format multiple if needed)
	}

	String^ BatteryStats::GetDesignedCapacity() {
		PowerShell^ ps = PowerShell::Create();
		ps->AddScript(gcnew String("(Get-WmiObject -Namespace root\\wmi -Query \"Select DesignedCapacity From BatteryStaticData\").DesignedCapacity"));
		auto result = ps->Invoke();
		return retrievefn(result);
	}
	String^ BatteryStats::GetFullChargedCapacity() {
		PowerShell^ ps = PowerShell::Create();
		ps->AddScript(gcnew String("(Get-WmiObject -Namespace root\\wmi -Query \"Select FullChargedCapacity From BatteryFullChargedCapacity\").FullChargedCapacity"));
		auto result = ps->Invoke();
		return retrievefn(result);
	}
	
}

