[Variables]
WidgetHeight=500

[Logo]
Meter=Image
ImageName=#@#Images\Icons\Monterey.png
X=(#SidebarWidth# + (#WidgetWidth# - #SidebarWidth# - 250) / 2)
Y=50
W=250

[Title]
Meter=String
Text=Monterey
X=(#SidebarWidth# + 75)
Y=280
FontFace=#FontFace#
FontSize=20
FontWeight=800
FontColor=#ForegroundColor#
AntiAlias=1
DynamicVariables=1

[Title2]
Meter=String
MeterStyle=Title
Text=Rainmeter
FontWeight=100
X=0R

[Version]
Meter=String
MeterStyle=Title
Text=#tVersion#
StringAlign=Right
X=(#SidebarWidth# + (#WidgetWidth# - #SidebarWidth#) / 2)
Y=10R
FontSize=10
FontWeight=400

[VersionNumber]
Meter=String
MeterStyle=Title
Text=1.0.4
X=0r
Y=0r
FontSize=10
FontWeight=100
FontColor=#ForegroundColor#80

[Author]
Meter=String
MeterStyle=Title
Text=by Dan MacCormac
X=0r
Y=0R
FontSize=10
FontWeight=100
FontColor=#ForegroundColor#80
LeftMouseUpAction=["https://github.com/dmaccormac"]

[LicensedUnder]
Meter=String
MeterStyle=Title
Text=#tLicense#
StringAlign=Right
X=0r
Y=0R
FontSize=10
FontWeight=400

[License]
Meter=String
MeterStyle=Title
Text=CC BY-NC-SA 4.0
X=0r
Y=0r
FontSize=10
FontWeight=100
FontColor=#ForegroundColor#80
LeftMouseUpAction=["https://creativecommons.org/licenses/by-nc-sa/4.0/"]

[Inspired]
Meter=String
MeterStyle=Title
Text=#tInspired#
StringAlign=Right
X=0r
Y=0R
FontSize=10
FontWeight=400

[Inspired2]
Meter=String
MeterStyle=Title
Text=MacOS Monterey for Windows
X=0r
Y=0r
FontSize=10
FontWeight=100
FontColor=#ForegroundColor#80
LeftMouseUpAction=["https://www.deviantart.com/legend0804/art/MacOS-Monterey-for-Windows-952714758"]

[Inspired3]
Meter=String
MeterStyle=Title
Text=by creewick 
X=0r
Y=0R
FontSize=10
FontWeight=100
FontColor=#ForegroundColor#80
LeftMouseUpAction=["https://github.com/creewick"]


[GitHub]
Meter=String
Text=GitHub
X=(#SidebarWidth# + 205)
Y=20R
FontFace=#FontFace#
FontSize=10
FontColor=#ForegroundColor#
FontWeight=400
StringAlign=Center
AntiAlias=1
Padding=16,2,16,4
SolidColor=#ForegroundColor#20
DynamicVariables=1
LeftMouseUpAction=["https://github.com/dmaccormac/MontereyRainmeter"]

