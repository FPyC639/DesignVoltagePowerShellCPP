// PowerShellHand.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vcclr.h>
#using <mscorlib.dll>
#include <msclr/marshal_cppstd.h>
#include <iostream>
#include <string>
#include <vector>
#using <System.dll>
#using <System.Management.Automation.dll>
#using <System.Core.dll>

using namespace std;
using namespace System;
using namespace System::Collections::ObjectModel; 
using namespace System::Management::Automation;
using namespace System::Runtime::InteropServices;

std::string retrievefn(Collection<PSObject^>^ a) {
    std::string res;
    for (int i = 0; i < a->Count; i++) {
        System::String^ res2 = a[i]->ToString();
        res = msclr::interop::marshal_as<std::string>(res2);
    }
    return res;
}

int main()
{
    PowerShell^ ps = PowerShell::Create();
    ps->AddScript(gcnew String("(Get-WmiObject Win32_Battery | Select DesignVoltage).DesignVoltage"));
    auto result = ps->Invoke();
    std::cout << "Design Voltage is: ";
    for (int i = 0; i < result->Count; i++) {
        System::String^ res2 = result[i]->ToString();
        std::string res = msclr::interop::marshal_as<std::string>(res2);
        std::cout << res << std::endl;
    }
    std::vector<std::string> dynamic_fill;
    ps = PowerShell::Create();
    ps->AddScript(gcnew String("(Get-WmiObject -Namespace root\\wmi -Query \"Select DesignedCapacity From BatteryStaticData\").DesignedCapacity"));
    auto result2 = ps->Invoke();
    dynamic_fill.push_back(retrievefn(result2));
    ps->AddScript(gcnew String("(Get-WmiObject -Namespace root\\wmi -Query \"Select FullChargedCapacity From BatteryFullChargedCapacity\").FullChargedCapacity"));
    result2 = ps->Invoke();
    dynamic_fill.push_back(retrievefn(result2));
    if (dynamic_fill.size() >= 2) {
        std::cout << "Designed Capacity is: " << dynamic_fill[0] << std::endl;
        std::cout << "Full Charged Capacity is: " << dynamic_fill[1] << std::endl;
    }
    else {
        std::cout << "Failed to retrieve both values." << std::endl;
    }
   
    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
