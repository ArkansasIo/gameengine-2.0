$vstoolsPath = "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Tools\MSVC\14.50.35717\bin\Hostx64\x64"
$cl = "$vstoolsPath\cl.exe"
$lib = "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Tools\MSVC\14.50.35717\bin\Hostx64\x64\lib.exe"

$sourceDir = "d:\New folder (5)\LunaLite\cpp_src"
$buildDir = "d:\New folder (5)\LunaLite\build_direct"

if (Test-Path $buildDir) { Remove-Item -Recurse -Force $buildDir }
mkdir $buildDir

# Compile all C++ files
cd $buildDir

$cppFiles = @((Get-ChildItem "$sourceDir" -Filter "*.cpp" -Recurse).FullName)

foreach ($file in $cppFiles) {
    Write-Host "Compiling: $(Split-Path $file -Leaf)"
    & $cl /c /EHsc /std:c++17 /I"$sourceDir" "$file" /Fo"$(Split-Path $file -Leaf).obj"
    if ($LASTEXITCODE -ne 0) {
        Write-Host "Error compiling: $file"
    }
}

Write-Host ""
Write-Host "Compilation complete. Generated object files: $(ls *.obj | measure -Line).Lines"
