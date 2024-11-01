[Rainmeter]
OnRefreshAction=[!CommandMeasure CPUAnimation "Execute [&ActionList]"][!CommandMeasure RAMAnimation "Execute [&ActionList]"][!CommandMeasure DiskAnimation "Execute [&ActionList]"][!CommandMeasure NetAnimation "Execute [&ActionList]"][!CommandMeasure LANAnimation "Execute [&ActionList]"][!CommandMeasure WANAnimation "Execute [&ActionList]"][!CommandMeasure Core0Animation "Execute [&ActionList]"][!CommandMeasure Core1Animation "Execute [&ActionList]"][!CommandMeasure Core2Animation "Execute [&ActionList]"][!CommandMeasure Core3Animation "Execute [&ActionList]"]

[Variables]
CPUValue=0
RAMValue=0
DiskValue=0
NetValue=0
LANValue=0
WANValue=0
Core0Value=0
Core1Value=0
Core2Value=0
Core3Value=0

[ActionList]
Measure=Calc
Formula=1+#BatterySaverMode#

[NoneMeasure]
Measure=Calc
Formula=-1

[BatteryMeasure]
Measure=Plugin
Plugin=PowerPlugin
PowerState=Percent
UpdateDivider=(60 * 5)
MinValue=0
MaxValue=100
IfCondition=((100 - BatteryMeasure) < #YellowStarts#)
IfTrueAction=[!SetVariable BatteryColor #GreenColor#]
IfCondition2=((100 - BatteryMeasure) >= #YellowStarts#) && ((100 - BatteryMeasure) < #RedStarts#)
IfTrueAction2=[!SetVariable BatteryColor #YellowColor#]
IfCondition3=((100 - BatteryMeasure) >= #RedStarts#)
IfTrueAction3=[!SetVariable BatteryColor #RedColor#]
OnChangeAction=[!UpdateMeasure BatteryRounded]

[BatteryRounded]
Measure=Calc
Formula=Round(BatteryMeasure,0)
MinValue=0
MaxValue=100

[CPUMonitor]
Measure=Plugin
Plugin=UsageMonitor
Alias=CPU
UpdateDivider=(#BatterySaverMode# = 0 ? 10 : 20)
MinValue=0
MaxValue=100
OnChangeAction=[!UpdateMeasure CPURounded]

[CPURounded]
Measure=Calc
Formula=Round(CPUMonitor,0)
MinValue=0
MaxValue=100
IfCondition=(CPUMonitor < #YellowStarts#)
IfTrueAction=[!SetVariable CPUColor #GreenColor#]
IfCondition2=(CPUMonitor >= #YellowStarts#) && (CPUMonitor < #RedStarts#)
IfTrueAction2=[!SetVariable CPUColor #YellowColor#]
IfCondition3=(CPUMonitor >= #RedStarts#)
IfTrueAction3=[!SetVariable CPUColor #RedColor#]
OnChangeAction=[!CommandMeasure CPUAnimation "Stop [&ActionList]"][!CommandMeasure CPUAnimation "Execute [&ActionList]"]

[CPUMeasure]
Measure=Calc
Formula=#CPUValue#
MinValue=0
MaxValue=100
DynamicVariables=1

[CPUAnimation]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Repeat AddStep, 100, 10
ActionList2=Update
AddStep=[!SetVariable CPUValue ([#CPUValue]+([&CPURounded:]-[#CPUValue])/2)][!UpdateMeasure CPUMeasure]
Update=[!SetVariable CPUValue [&CPURounded:]][!UpdateMeasure CPUMeasure]
DynamicVariables=1

[RAMMonitor]
Measure=Plugin
Plugin=UsageMonitor
Category=Memory
Counter=% Committed Bytes In Use
UpdateDivider=(#BatterySaverMode# = 0 ? 10 : 20)
MinValue=0
MaxValue=100
OnChangeAction=[!UpdateMeasure RAMRounded]

[RAMRounded]
Measure=Calc
Formula=Round(RAMMonitor,0)
MinValue=0
MaxValue=100
IfCondition=(RAMMonitor < #YellowStarts#)
IfTrueAction=[!SetVariable RAMColor #GreenColor#]
IfCondition2=(RAMMonitor >= #YellowStarts#) && (RAMMonitor < #RedStarts#)
IfTrueAction2=[!SetVariable RAMColor #YellowColor#]
IfCondition3=(RAMMonitor >= #RedStarts#)
IfTrueAction3=[!SetVariable RAMColor #RedColor#]
OnChangeAction=[!CommandMeasure RAMAnimation "Stop [&ActionList]"][!CommandMeasure RAMAnimation "Execute [&ActionList]"]

[RAMMeasure]
Measure=Calc
Formula=#RAMValue#
MinValue=0
MaxValue=100
DynamicVariables=1

[RAMAnimation]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Repeat AddStep, 100, 10
ActionList2=Update
AddStep=[!SetVariable RAMValue ([#RAMValue]+([&RAMRounded:]-[#RAMValue])/2)][!UpdateMeasure RAMMeasure]
Update=[!SetVariable RAMValue [&RAMRounded:]][!UpdateMeasure RAMMeasure]
DynamicVariables=1

[DiskMonitor]
Measure=Plugin
Plugin=UsageMonitor
Category=LogicalDisk
Counter=% Disk Time
UpdateDivider=(#BatterySaverMode# = 0 ? 10 : 20)
MinValue=0
MaxValue=100
OnChangeAction=[!UpdateMeasure DiskRounded]

[DiskRounded]
Measure=Calc
Formula=Round(Clamp(DiskMonitor,0,100),0)
MinValue=0
MaxValue=100
IfCondition=(DiskMonitor < #YellowStarts#)
IfTrueAction=[!SetVariable DiskColor #GreenColor#]
IfCondition2=(DiskMonitor >= #YellowStarts#) && (DiskMonitor < #RedStarts#)
IfTrueAction2=[!SetVariable DiskColor #YellowColor#]
IfCondition3=(DiskMonitor >= #RedStarts#)
IfTrueAction3=[!SetVariable DiskColor #RedColor#]
OnChangeAction=[!CommandMeasure DiskAnimation "Stop [&ActionList]"][!CommandMeasure DiskAnimation "Execute [&ActionList]"]

[DiskMeasure]
Measure=Calc
Formula=#DiskValue#
MinValue=0
MaxValue=100
DynamicVariables=1

[DiskAnimation]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Repeat AddStep, 100, 10
ActionList2=Update
AddStep=[!SetVariable DiskValue ([#DiskValue]+([&DiskRounded:]-[#DiskValue])/2)][!UpdateMeasure DiskMeasure]
Update=[!SetVariable DiskValue [&DiskRounded:]][!UpdateMeasure DiskMeasure]
DynamicVariables=1

[NetBytes]
Measure=Plugin
Plugin=UsageMonitor
Category=Network Interface
Counter=Bytes total/sec
MinValue=0
MaxValue=100
UpdateDivider=(#BatterySaverMode# = 0 ? 10 : 20)
OnChangeAction=[!UpdateMeasure NetRounded]

[NetWidth]
Measure=Plugin
Plugin=UsageMonitor
Category=Network Interface
Counter=Current bandwidth
MinValue=0
MaxValue=100
UpdateDivider=3600
OnChangeAction=[!UpdateMeasure NetRounded]

[NetRounded]
Measure=Calc
Formula=Round(Clamp(NetBytes * 8 / NetWidth * 100, 0, 100),0)
MinValue=0
MaxValue=100
IfCondition=(NetMeasure < #YellowStarts#)
IfTrueAction=[!SetVariable NetColor #GreenColor#]
IfCondition2=(NetMeasure >= #YellowStarts#) && (NetMeasure < #RedStarts#)
IfTrueAction2=[!SetVariable NetColor #YellowColor#]
IfCondition3=(NetMeasure >= #RedStarts#)
IfTrueAction3=[!SetVariable NetColor #RedColor#]
OnChangeAction=[!CommandMeasure NetAnimation "Stop [&ActionList]"][!CommandMeasure NetAnimation "Execute [&ActionList]"]

[NetMeasure]
Measure=Calc
Formula=#NetValue#
MinValue=0
MaxValue=100
DynamicVariables=1

[NetAnimation]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Repeat AddStep, 100, 10
ActionList2=Update
AddStep=[!SetVariable NetValue ([#NetValue]+([&NetRounded:]-[#NetValue])/2)][!UpdateMeasure NetMeasure]
Update=[!SetVariable NetValue [&NetRounded:]][!UpdateMeasure NetMeasure]
DynamicVariables=1

[LANBytes]
Measure=Plugin
Plugin=UsageMonitor
Category=Network Interface
Counter=Bytes total/sec
MinValue=0
MaxValue=100
UpdateDivider=(#BatterySaverMode# = 0 ? 10 : 20)
OnChangeAction=[!UpdateMeasure NetRounded]

[LANWidth]
Measure=Plugin
Plugin=UsageMonitor
Category=Network Interface
Counter=Current bandwidth
MinValue=0
MaxValue=100
UpdateDivider=3600
OnChangeAction=[!UpdateMeasure NetRounded]

[LANRounded]
Measure=Plugin
Plugin=SysInfo
SysInfoType=IP_ADDRESS
SysInfodata=Best

[LANMeasure]
Measure=Calc
Formula=#NetValue#
MinValue=0
MaxValue=100
DynamicVariables=1

[LANAnimation]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Repeat AddStep, 100, 10
ActionList2=Update
AddStep=[!SetVariable NetValue ([#NetValue]+([&NetRounded:]-[#NetValue])/2)][!UpdateMeasure NetMeasure]
Update=[!SetVariable NetValue [&NetRounded:]][!UpdateMeasure NetMeasure]
DynamicVariables=1

[WANBytes]
Measure=Plugin
Plugin=UsageMonitor
Category=Network Interface
Counter=Bytes total/sec
MinValue=0
MaxValue=100
UpdateDivider=(#BatterySaverMode# = 0 ? 10 : 20)
OnChangeAction=[!UpdateMeasure NetRounded]

[WANWidth]
Measure=Plugin
Plugin=UsageMonitor
Category=Network Interface
Counter=Current bandwidth
MinValue=0
MaxValue=100
UpdateDivider=3600
OnChangeAction=[!UpdateMeasure NetRounded]

[WANRounded]
Measure=Plugin
Plugin=WebParser
URL=https://checkip.amazonaws.com/
UpdateRate=14400
RegExp=(?s)^(.*)$
StringIndex=1
Substitute="":"N/A"

[WANMeasure]
Measure=Calc
Formula=#NetValue#
MinValue=0
MaxValue=100
DynamicVariables=1

[WANAnimation]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Repeat AddStep, 100, 10
ActionList2=Update
AddStep=[!SetVariable NetValue ([#NetValue]+([&NetRounded:]-[#NetValue])/2)][!UpdateMeasure NetMeasure]
Update=[!SetVariable NetValue [&NetRounded:]][!UpdateMeasure NetMeasure]
DynamicVariables=1

[Core0Monitor]
Measure=Plugin
Plugin=CoreTemp
CoreTempType=Temperature
CoreTempIndex=0
Alias=Temp
UpdateDivider=(#BatterySaverMode# = 0 ? 10 : 20)
MinValue=0
MaxValue=100
OnChangeAction=[!UpdateMeasure Core0Rounded]


[Core0Rounded]
Measure=Calc
Formula=Round(Core0Monitor,0)
MinValue=0
MaxValue=100
IfCondition=(Core0Monitor < #YellowStarts#)
IfTrueAction=[!SetVariable Core0Color #GreenColor#]
IfCondition2=(Core0Monitor >= #YellowStarts#) && (Core0Monitor < #RedStarts#)
IfTrueAction2=[!SetVariable Core0Color #YellowColor#]
IfCondition3=(Core0Monitor >= #RedStarts#)
IfTrueAction3=[!SetVariable Core0Color #RedColor#]
OnChangeAction=[!CommandMeasure Core0Animation "Stop [&ActionList]"][!CommandMeasure Core0Animation "Execute [&ActionList]"]

[Core0Measure]
Measure=Calc
Formula=#Core0Value#
MinValue=0
MaxValue=100
DynamicVariables=1

[Core0Animation]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Repeat AddStep, 100, 10
ActionList2=Update
AddStep=[!SetVariable Core0Value ([#Core0Value]+([&Core0Rounded:]-[#Core0Value])/2)][!UpdateMeasure Core0Measure]
Update=[!SetVariable Core0Value [&Core0Rounded:]][!UpdateMeasure Core0Measure]
DynamicVariables=1


[Core1Monitor]
Measure=Plugin
Plugin=CoreTemp
CoreTempType=Temperature
CoreTempIndex=1
Alias=Temp
UpdateDivider=(#BatterySaverMode# = 0 ? 10 : 20)
MinValue=0
MaxValue=100
OnChangeAction=[!UpdateMeasure Core1Rounded]

[Core1Rounded]
Measure=Calc
Formula=Round(Core1Monitor,0)
MinValue=0
MaxValue=100
IfCondition=(Core1Monitor < #YellowStarts#)
IfTrueAction=[!SetVariable Core1Color #GreenColor#]
IfCondition2=(Core1Monitor >= #YellowStarts#) && (Core1Monitor < #RedStarts#)
IfTrueAction2=[!SetVariable Core1Color #YellowColor#]
IfCondition3=(Core1Monitor >= #RedStarts#)
IfTrueAction3=[!SetVariable Core1Color #RedColor#]
OnChangeAction=[!CommandMeasure Core1Animation "Stop [&ActionList]"][!CommandMeasure Core1Animation "Execute [&ActionList]"]

[Core1Measure]
Measure=Calc
Formula=#Core1Value#
MinValue=0
MaxValue=100
DynamicVariables=1

[Core1Animation]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Repeat AddStep, 100, 10
ActionList2=Update
AddStep=[!SetVariable Core1Value ([#Core1Value]+([&Core1Rounded:]-[#Core1Value])/2)][!UpdateMeasure Core1Measure]
Update=[!SetVariable Core1Value [&Core1Rounded:]][!UpdateMeasure Core1Measure]
DynamicVariables=1


[Core2Monitor]
Measure=Plugin
Plugin=CoreTemp
CoreTempType=Temperature
CoreTempIndex=2
Alias=Temp
UpdateDivider=(#BatterySaverMode# = 0 ? 10 : 20)
MinValue=0
MaxValue=100
OnChangeAction=[!UpdateMeasure Core2Rounded]

[Core2Rounded]
Measure=Calc
Formula=Round(Core2Monitor,0)
MinValue=0
MaxValue=100
IfCondition=(Core2Monitor < #YellowStarts#)
IfTrueAction=[!SetVariable Core2Color #GreenColor#]
IfCondition2=(Core2Monitor >= #YellowStarts#) && (Core2Monitor < #RedStarts#)
IfTrueAction2=[!SetVariable Core2Color #YellowColor#]
IfCondition3=(Core2Monitor >= #RedStarts#)
IfTrueAction3=[!SetVariable Core2Color #RedColor#]
OnChangeAction=[!CommandMeasure Core2Animation "Stop [&ActionList]"][!CommandMeasure Core2Animation "Execute [&ActionList]"]

[Core2Measure]
Measure=Calc
Formula=#Core2Value#
MinValue=0
MaxValue=100
DynamicVariables=1

[Core2Animation]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Repeat AddStep, 100, 10
ActionList2=Update
AddStep=[!SetVariable Core2Value ([#Core2Value]+([&Core2Rounded:]-[#Core2Value])/2)][!UpdateMeasure Core2Measure]
Update=[!SetVariable Core2Value [&Core2Rounded:]][!UpdateMeasure Core2Measure]
DynamicVariables=1


[Core3Monitor]
Measure=Plugin
Plugin=CoreTemp
CoreTempType=Temperature
CoreTempIndex=3
Alias=Temp
UpdateDivider=(#BatterySaverMode# = 0 ? 10 : 20)
MinValue=0
MaxValue=100
OnChangeAction=[!UpdateMeasure Core3Rounded]

[Core3Rounded]
Measure=Calc
Formula=Round(Core3Monitor,0)
MinValue=0
MaxValue=100
IfCondition=(Core3Monitor < #YellowStarts#)
IfTrueAction=[!SetVariable Core3Color #GreenColor#]
IfCondition2=(Core3Monitor >= #YellowStarts#) && (Core3Monitor < #RedStarts#)
IfTrueAction2=[!SetVariable Core3Color #YellowColor#]
IfCondition3=(Core3Monitor >= #RedStarts#)
IfTrueAction3=[!SetVariable Core3Color #RedColor#]
OnChangeAction=[!CommandMeasure Core3Animation "Stop [&ActionList]"][!CommandMeasure Core3Animation "Execute [&ActionList]"]

[Core3Measure]
Measure=Calc
Formula=#Core3Value#
MinValue=0
MaxValue=100
DynamicVariables=1

[Core3Animation]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Repeat AddStep, 100, 10
ActionList2=Update
AddStep=[!SetVariable Core3Value ([#Core3Value]+([&Core3Rounded:]-[#Core3Value])/2)][!UpdateMeasure Core3Measure]
Update=[!SetVariable Core3Value [&Core3Rounded:]][!UpdateMeasure Core3Measure]
DynamicVariables=1