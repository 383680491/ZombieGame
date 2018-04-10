cd %~dp0
cd .\proto
for %%i in (*.proto) do (    
echo %%i  
"..\plugin\protoc.exe" --plugin=protoc-gen-lua="..\plugin\tolua.bat" --lua_out=. %%i
)  
echo end  
pause