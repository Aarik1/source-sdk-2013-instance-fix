# func_instance_io_proxy fix

This does not work with stock hammer!
You must have hammer++ installed or else you can not access the instance logic.

## How to setup 
1. First compile vbsp, and the client and server dlls
2. Go into your gameinfo.txt and put these lines at the top
```
"GameData"		"yourmodsfgd.fgd"
"InstancePath"	"maps/instances/"
```

Please note that instances will only work when they are located in a folder structure like this
```
maps-|
	instances-|
		instance.vmf
```

3. Modify the base.fgd with an updated entry for func_instance

Search for func_instance and replace the entry with this one.
```
@PointClass base(Angles) size( -8 -8 -8, 8 8 8 ) instance() = func_instance : 
	"An entity for placing an instance of a map file.  You may translate and rotate this entity. " +
	"You can use the replace keys to do parameter changes on the instance contents.  In a $ at the " +
	"beginning of a variable name.  Then just use the $variable name inside of the instance contents on any "+
	"value portion of a key/value pair."
[
	targetname(target_source) : "Fix Up Name" : : "The name that all entities will be fixed up with based upon the fix up style."
	file(instance_file) : "VMF Filename" : : "This indicates a map file relative to the map's file name"
	fixup_style(Choices) : "Entity Name Fix Up" : 0 : "Fixup style for instanced entity names.  Uses the 'Fix Up Name' field." =
	[
		0 : "Prefix"
		1 : "Postfix"
		2 : "None"
	]

	replace01(instance_variable) : "Replace" : : "This is a replacement parameter.  It goes in the form of $variable value.  All entities inside of that instance that have $variable somewhere will be replaced with the value contents.  Example: $color 255 0 0"
	replace02(instance_variable) : "Replace" : : "This is a replacement parameter.  It goes in the form of $variable value.  All entities inside of that instance that have $variable somewhere will be replaced with the value contents.  Example: $color 255 0 0"
	replace03(instance_variable) : "Replace" : : "This is a replacement parameter.  It goes in the form of $variable value.  All entities inside of that instance that have $variable somewhere will be replaced with the value contents.  Example: $color 255 0 0"
	replace04(instance_variable) : "Replace" : : "This is a replacement parameter.  It goes in the form of $variable value.  All entities inside of that instance that have $variable somewhere will be replaced with the value contents.  Example: $color 255 0 0"
	replace05(instance_variable) : "Replace" : : "This is a replacement parameter.  It goes in the form of $variable value.  All entities inside of that instance that have $variable somewhere will be replaced with the value contents.  Example: $color 255 0 0"
	replace06(instance_variable) : "Replace" : : "This is a replacement parameter.  It goes in the form of $variable value.  All entities inside of that instance that have $variable somewhere will be replaced with the value contents.  Example: $color 255 0 0"
	replace07(instance_variable) : "Replace" : : "This is a replacement parameter.  It goes in the form of $variable value.  All entities inside of that instance that have $variable somewhere will be replaced with the value contents.  Example: $color 255 0 0"
	replace08(instance_variable) : "Replace" : : "This is a replacement parameter.  It goes in the form of $variable value.  All entities inside of that instance that have $variable somewhere will be replaced with the value contents.  Example: $color 255 0 0"
	replace09(instance_variable) : "Replace" : : "This is a replacement parameter.  It goes in the form of $variable value.  All entities inside of that instance that have $variable somewhere will be replaced with the value contents.  Example: $color 255 0 0"
	replace10(instance_variable) : "Replace" : : "This is a replacement parameter.  It goes in the form of $variable value.  All entities inside of that instance that have $variable somewhere will be replaced with the value contents.  Example: $color 255 0 0"
]
```

4. Now its time to add func_instance_io_proxy
You can either add it here in base.fgd or add it to your own fgd.

Here is the entry for func_instance_io_proxy
```
@PointClass iconsprite("editor/func_instance_parms.vmt") = func_instance_io_proxy : 
	"Place one copy of this entity inside of an instance.  Sending messages to entities inside the instance from the Proxy's OnProxyRelay output " +
	"will allow you to trigger these entities from outside the instance by sending messages to the func_instance.  " +
	"Send the ProxyRelay message from entities inside the instance to the proxy and you will be able to use these events to send messages to other entities " +
	"outside the instance from the func_instance. NOTE: The instance, the proxy, and all entities involved should be named descriptively."
[
	targetname(target_source) : "Name" : : "The name that other entities refer to this entity by."

	input ProxyRelay(string) : "This message will get relayed and will be available from the instance."

	output OnProxyRelay(void) : "A message from outside can trigger this to cause something to happen in the instance."
]
```

5. Replace the vbsp exe in the Source SDK 2013 Singleplayer bin folder
6. Compile your map with your instances

If you did all these steps correctly you should have working instances in your mod.

Feel free to import the changes I did here into your own mod.








               SOURCE 1 SDK LICENSE

Source SDK Copyright(c) Valve Corp.  

THIS DOCUMENT DESCRIBES A CONTRACT BETWEEN YOU AND VALVE 
CORPORATION ("Valve").  PLEASE READ IT BEFORE DOWNLOADING OR USING 
THE SOURCE ENGINE SDK ("SDK"). BY DOWNLOADING AND/OR USING THE 
SOURCE ENGINE SDK YOU ACCEPT THIS LICENSE. IF YOU DO NOT AGREE TO 
THE TERMS OF THIS LICENSE PLEASE DON’T DOWNLOAD OR USE THE SDK.  

  You may, free of charge, download and use the SDK to develop a modified Valve game 
running on the Source engine.  You may distribute your modified Valve game in source and 
object code form, but only for free. Terms of use for Valve games are found in the Steam 
Subscriber Agreement located here: http://store.steampowered.com/subscriber_agreement/ 

  You may copy, modify, and distribute the SDK and any modifications you make to the 
SDK in source and object code form, but only for free.  Any distribution of this SDK must 
include this LICENSE file and thirdpartylegalnotices.txt.  
 
  Any distribution of the SDK or a substantial portion of the SDK must include the above 
copyright notice and the following: 

    DISCLAIMER OF WARRANTIES.  THE SOURCE SDK AND ANY 
    OTHER MATERIAL DOWNLOADED BY LICENSEE IS PROVIDED 
    "AS IS".  VALVE AND ITS SUPPLIERS DISCLAIM ALL 
    WARRANTIES WITH RESPECT TO THE SDK, EITHER EXPRESS 
    OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, IMPLIED 
    WARRANTIES OF MERCHANTABILITY, NON-INFRINGEMENT, 
    TITLE AND FITNESS FOR A PARTICULAR PURPOSE.  

    LIMITATION OF LIABILITY.  IN NO EVENT SHALL VALVE OR 
    ITS SUPPLIERS BE LIABLE FOR ANY SPECIAL, INCIDENTAL, 
    INDIRECT, OR CONSEQUENTIAL DAMAGES WHATSOEVER 
    (INCLUDING, WITHOUT LIMITATION, DAMAGES FOR LOSS OF 
    BUSINESS PROFITS, BUSINESS INTERRUPTION, LOSS OF 
    BUSINESS INFORMATION, OR ANY OTHER PECUNIARY LOSS) 
    ARISING OUT OF THE USE OF OR INABILITY TO USE THE 
    ENGINE AND/OR THE SDK, EVEN IF VALVE HAS BEEN 
    ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.  
 
       
If you would like to use the SDK for a commercial purpose, please contact Valve at 
sourceengine@valvesoftware.com.
