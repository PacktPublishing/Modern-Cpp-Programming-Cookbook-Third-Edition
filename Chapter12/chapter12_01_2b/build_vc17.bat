cl /std:c++latest /MD /EHsc /W4 /c "%VCToolsInstallDir%\modules\std.ixx" geometry.ixx
cl /std:c++latest /MD /EHsc /W4 /Femain "%VCToolsInstallDir%\modules\std.ixx" main.cpp geometry.obj