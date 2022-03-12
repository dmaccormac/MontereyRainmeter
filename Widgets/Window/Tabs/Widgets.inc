[Widget1Icon]
Meter=Image
ImageName=#@#Images\Icons\Clock.png
W=50
X=(#WidgetPadding#+#SidebarWidth#+20)
Y=(#WidgetPadding#+45+20)

[Widget1Title]
Meter=String
Text=#tClock#
FontSize=12
FontFace=#FontFace#
FontColor=#ForegroundColor#
FontWeight=400
AntiAlias=1
DynamicVariables=1
X=(#WidgetPadding#+#SidebarWidth#+80)
Y=(#WidgetPadding#+45+20)

[Widget1Description]
Meter=String
Text=#tClockDescription#
FontSize=10
FontFace=#FontFace#
FontColor=#ForegroundColor#80
AntiAlias=1
DynamicVariables=1
ClipString=2
X=(#WidgetPadding#+#SidebarWidth#+80)
Y=(#WidgetPadding#+45+40)
W=120

[Widget1Add]
Meter=Shape
Shape=Rectangle 0,0,80,20,10 | Fill Color #ForegroundColor#20 | StrokeWidth 0
X=(#WidgetPadding#+#SidebarWidth#+220)
Y=(#WidgetPadding#+45+35)
DynamicVariables=1
LeftMouseUpAction=[!ActivateConfig "Monterey\Widgets\Clock" "Clock-medium.ini"]

[Widget1AddText]
Meter=String
Text=#tAdd#
FontSize=8
FontFace=#FontFace#
FontColor=#ForegroundColor#
FontWeight=600
AntiAlias=1
DynamicVariables=1
StringAlign=Center
StringCase=Upper
X=(#WidgetPadding#+#SidebarWidth#+260)
Y=(#WidgetPadding#+45+38)

[Widget2Icon]
Meter=Image
MeterStyle=Widget1Icon
ImageName=#@#Images\Icons\Calendar.png
X=(#WidgetPadding#+#SidebarWidth#+340)

[Widget2Title]
Meter=String
MeterStyle=Widget1Title
Text=#tCalendar#
X=(#WidgetPadding#+#SidebarWidth#+400)

[Widget2Description]
Meter=String
MeterStyle=Widget1Description
Text=#tCalendarDescription#
X=(#WidgetPadding#+#SidebarWidth#+400)

[Widget2Add]
Meter=Shape
MeterStyle=Widget1Add
X=(#WidgetPadding#+#SidebarWidth#+540)
LeftMouseUpAction=[!ActivateConfig "Monterey\Widgets\Calendar" "Calendar-medium.ini"]

[Widget2AddText]
Meter=String
MeterStyle=Widget1AddText
X=(#WidgetPadding#+#SidebarWidth#+580)

[Widget3Icon]
Meter=Image
MeterStyle=Widget1Icon
ImageName=#@#Images\Icons\ActivityMonitor.png
Y=(#WidgetPadding#+45+100)

[Widget3Title]
Meter=String
MeterStyle=Widget1Title
Text=#tActivityMonitor#
Y=(#WidgetPadding#+45+100)

[Widget3Description]
Meter=String
MeterStyle=Widget1Description
Text=#tActivityMonitorDescription#
Y=(#WidgetPadding#+45+120)

[Widget3Add]
Meter=Shape
MeterStyle=Widget1Add
Y=(#WidgetPadding#+45+115)
LeftMouseUpAction=[!ActivateConfig "Monterey\Widgets\Activity Monitor" "ActivityMonitor-medium.ini"]

[Widget3AddText]
Meter=String
MeterStyle=Widget1AddText
Y=(#WidgetPadding#+45+118)

[Widget4Icon]
Meter=Image
MeterStyle=Widget1Icon
ImageName=#@#Images\Icons\Weather.png
X=(#WidgetPadding#+#SidebarWidth#+340)
Y=(#WidgetPadding#+45+100)

[Widget4Title]
Meter=String
MeterStyle=Widget1Title
Text=#tWeather#
X=(#WidgetPadding#+#SidebarWidth#+400)
Y=(#WidgetPadding#+45+100)

[Widget4Description]
Meter=String
MeterStyle=Widget1Description
Text=#tWeatherDescription#
X=(#WidgetPadding#+#SidebarWidth#+400)
Y=(#WidgetPadding#+45+120)

[Widget4Add]
Meter=Shape
MeterStyle=Widget1Add
X=(#WidgetPadding#+#SidebarWidth#+540)
LeftMouseUpAction=[!ActivateConfig "Monterey\Widgets\Weather" "Weather-medium.ini"]
Y=(#WidgetPadding#+45+115)

[Widget4AddText]
Meter=String
MeterStyle=Widget1AddText
X=(#WidgetPadding#+#SidebarWidth#+580)
Y=(#WidgetPadding#+45+118)

[Widget5Icon]
Meter=Image
MeterStyle=Widget1Icon
ImageName=#@#Images\Icons\Notes.png
Y=(#WidgetPadding#+45+180)

[Widget5Title]
Meter=String
MeterStyle=Widget1Title
Text=#tNotes#
Y=(#WidgetPadding#+45+180)

[Widget5Description]
Meter=String
MeterStyle=Widget1Description
Text=#tNotesDescription#
Y=(#WidgetPadding#+45+200)

[Widget5Add]
Meter=Shape
MeterStyle=Widget1Add
Y=(#WidgetPadding#+45+195)
LeftMouseUpAction=[!ActivateConfig "Monterey\Widgets\Notes" "Notes-medium.ini"]

[Widget5AddText]
Meter=String
MeterStyle=Widget1AddText
Y=(#WidgetPadding#+45+198)

[Widget6Icon]
Meter=Image
MeterStyle=Widget1Icon
ImageName=#@#Images\Icons\Music.png
X=(#WidgetPadding#+#SidebarWidth#+340)
Y=(#WidgetPadding#+45+180)

[Widget6Title]
Meter=String
MeterStyle=Widget1Title
Text=#tMusic#
X=(#WidgetPadding#+#SidebarWidth#+400)
Y=(#WidgetPadding#+45+180)

[Widget6Description]
Meter=String
MeterStyle=Widget1Description
Text=#tMusicDescription#
X=(#WidgetPadding#+#SidebarWidth#+400)
Y=(#WidgetPadding#+45+200)

[Widget6Add]
Meter=Shape
MeterStyle=Widget1Add
X=(#WidgetPadding#+#SidebarWidth#+540)
LeftMouseUpAction=[!ActivateConfig "Monterey\Widgets\Music" "Music-medium.ini"]
Y=(#WidgetPadding#+45+195)

[Widget6AddText]
Meter=String
MeterStyle=Widget1AddText
X=(#WidgetPadding#+#SidebarWidth#+580)
Y=(#WidgetPadding#+45+198)

[Widget7Icon]
Meter=Image
MeterStyle=Widget1Icon
ImageName=#@#Images\Icons\Volume.png
Y=(#WidgetPadding#+45+260)

[Widget7Title]
Meter=String
MeterStyle=Widget1Title
Text=#tVolume#
Y=(#WidgetPadding#+45+260)

[Widget7Description]
Meter=String
MeterStyle=Widget1Description
Text=#tVolumeDescription#
Y=(#WidgetPadding#+45+280)

[Widget7Add]
Meter=Shape
MeterStyle=Widget1Add
Y=(#WidgetPadding#+45+275)
LeftMouseUpAction=[!ActivateConfig "Monterey\Widgets\Volume" "Volume-medium.ini"]

[Widget7AddText]
Meter=String
MeterStyle=Widget1AddText
Y=(#WidgetPadding#+45+278)