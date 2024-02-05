cl /std:c++latest /EHsc /MD /c "%VCToolsInstallDir%\modules\std.ixx" geometry-core.ixx
cl /std:c++latest /EHsc /MD /c geometry-literals.ixx
cl /std:c++latest /EHsc /MD /c /interface geometry.ixx
cl /std:c++latest /EHsc /MD /Femain "%VCToolsInstallDir%\modules\std.ixx" main.cpp geometry-core.obj geometry-literals.obj
