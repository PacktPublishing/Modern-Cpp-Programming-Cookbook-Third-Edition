cl /std:c++latest /EHsc /W4 /MD /c "%VCToolsInstallDir%\modules\std.ixx" geometry-core.ixx
cl /std:c++latest /EHsc /W4 /MD /c geometry-literals.ixx
cl /std:c++latest /EHsc /W4 /MD /c geometry.ixx
cl /std:c++latest /EHsc /W4 /MD /Femain "%VCToolsInstallDir%\modules\std.ixx" main.cpp geometry-core.obj geometry-literals.obj
