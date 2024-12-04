# O3DE project for tests

This repository was created for test purposes, serving as a sandbox for experimenting with different O3DE failures and crashes. Note that the repository content is not intended for production use and may include experimental or unstable code.

## Background

The codebase was initialized with O3DE 2409.1 from the source. The engine was registered (with python installed properly) and the is correctly defined in `o3de_manifest.json` file. Next, the script from the repo was used to generate the project, followed by marginal changes to update `.gitignore` file and add `.clang-format` file to the repo. The changes are marked in git history accordingly.

The command to generate the project was as follows:

```
~/devroot/o3de/scripts/o3de.sh create-project --project-path ~/devroot/projects/JHO3DETestProject
```

## Release build issue

Commit `280d703` fails to build in release mode with the following combination of commands:

```
cmake -B build/linux -G "Ninja Multi-Config" -DLY_STRIP_DEBUG_SYMBOLS=OFF -DLY_DISABLE_TEST_MODULES=ON -DLY_UNITY_BUILD=OFF -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build build/linux --config release --target Editor 
```

and the following outcome:

```
[158/267] Linking CXX shared module bin/release/libScriptCanvas.Editor.so
FAILED: bin/release/libScriptCanvas.Editor.so 
: && /usr/bin/clang++-14 -fPIC -fno-exceptions -fvisibility=hidden -fvisibility-inlines-hidden -Wall -Werror -Wno-inconsistent-missing-override -Wrange-loop-analysis -Wno-unknown-warning-option -Wno-parentheses -Wno-reorder -Wno-switch -Wno-undefined-var-template -msse4.1  -O2  -Wl,--no-undefined -fpie -Wl,-z,relro,-z,now -Wl,-z,noexecstack -shared  -o bin/release/libScriptCanvas.Editor.so External/ScriptCanvas-ad8df5c6/Code/CMakeFiles/ScriptCanvas.Editor.dir/release/Editor/ScriptCanvasEditorGem.cpp.o  -Wl,-rpath,"\$ORIGIN"  lib/release/libAzToolsFramework.a  lib/release/libScriptCanvas.Editor.Static.a  bin/release/libEditorCore.so  lib/release/libCryCommon.a  lib/release/libScriptCanvas.API.a  lib/release/libScriptCanvasDebugger.a  lib/release/libScriptCanvas.Extensions.a  lib/release/libScriptEvents.Static.a  lib/release/libGraphCanvasWidgets.a  lib/release/libAssetBuilderSDK.a  lib/release/libAzToolsFramework.a  /home/jhanca/.o3de/3rdParty/packages/SQLite-3.37.2-rev1-linux/SQLite/lib/libsqlite3.a  lib/release/libAzFramework.NativeUI.a  /usr/lib/x86_64-linux-gnu/libxcb-xkb.so  /usr/lib/x86_64-linux-gnu/libxcb-xfixes.so  /usr/lib/x86_64-linux-gnu/libxcb.so  /usr/lib/x86_64-linux-gnu/libxkbcommon-x11.so  /usr/lib/x86_64-linux-gnu/libxkbcommon.so  /usr/lib/x86_64-linux-gnu/libX11.so  -lxcb-xinput  bin/release/libAzQtComponents.so  /home/jhanca/.o3de/3rdParty/packages/qt-5.15.2-rev9-linux/qt/lib/libQt5Svg.so.5.15.1  /home/jhanca/.o3de/3rdParty/packages/qt-5.15.2-rev9-linux/qt/lib/libQt5Widgets.so.5.15.1  /home/jhanca/.o3de/3rdParty/packages/qt-5.15.2-rev9-linux/qt/lib/libQt5Gui.so.5.15.1  /home/jhanca/.o3de/3rdParty/packages/qt-5.15.2-rev9-linux/qt/lib/libQt5Xml.so.5.15.1  /home/jhanca/.o3de/3rdParty/packages/qt-5.15.2-rev9-linux/qt/lib/libQt5Core.so.5.15.1  lib/release/libExpressionEvaluation.Static.a  lib/release/libAzFramework.a  lib/release/libAzNetworking.a  lib/release/libAzCore.a  /usr/lib/x86_64-linux-gnu/libunwind.so  -lpthread  -latomic  -lpthread  -latomic  /home/jhanca/.o3de/3rdParty/packages/Lua-5.4.4-rev1-linux/Lua/lib/release/liblualib.a  -ldl  /home/jhanca/.o3de/3rdParty/packages/zlib-1.2.11-rev5-linux/zlib/lib/libz.a  /home/jhanca/.o3de/3rdParty/packages/cityhash-1.1-multiplatform/cityhash/build/linux/clang-3.8/release/libcityhash.a  bin/release/libO3DEKernel.so  /usr/lib/x86_64-linux-gnu/libzstd.so  /home/jhanca/.o3de/3rdParty/packages/OpenSSL-1.1.1t-rev1-linux/OpenSSL/lib/libssl.a  /home/jhanca/.o3de/3rdParty/packages/OpenSSL-1.1.1t-rev1-linux/OpenSSL/lib/libcrypto.a  /home/jhanca/.o3de/3rdParty/packages/lz4-1.9.4-rev2-linux/lz4/lib/liblz4.a && cd /home/jhanca/devroot/projects/JHO3DETestProject/build/linux/External/ScriptCanvas-ad8df5c6/Code && /usr/bin/cmake -P /home/jhanca/devroot/o3de/cmake/Platform/Linux/ProcessDebugSymbols.cmake /usr/bin/strip /usr/bin/objcopy /home/jhanca/devroot/projects/JHO3DETestProject/build/linux/bin/release/libScriptCanvas.Editor.so dbg MODULE_LIBRARY DETACH
/usr/bin/ld: lib/release/libScriptCanvasDebugger.a(Logger.cpp.o): in function `ScriptCanvas::Debugger::Logger::Logger()':
Logger.cpp:(.text+0x88): undefined reference to `ScriptCanvas::ExecutionLogAsset::ExecutionLogAsset(AZ::Data::AssetId const&, AZ::Data::AssetData::AssetStatus)'
/usr/bin/ld: lib/release/libScriptCanvasDebugger.a(Logger.cpp.o): in function `ScriptCanvas::Debugger::Logger::~Logger()':
Logger.cpp:(.text+0x1dd): undefined reference to `ScriptCanvas::ExecutionLogData::~ExecutionLogData()'
/usr/bin/ld: lib/release/libScriptCanvasDebugger.a(Logger.cpp.o): in function `ScriptCanvas::Debugger::Logger::ClearLog()':
Logger.cpp:(.text+0x388): undefined reference to `ScriptCanvas::ExecutionLogData::Clear()'
/usr/bin/ld: lib/release/libScriptCanvasDebugger.a(Logger.cpp.o): in function `non-virtual thunk to ScriptCanvas::Debugger::Logger::ClearLog()':
Logger.cpp:(.text+0x398): undefined reference to `ScriptCanvas::ExecutionLogData::Clear()'
/usr/bin/ld: lib/release/libScriptCanvasDebugger.a(Logger.cpp.o): in function `ScriptCanvas::ExecutionLogAsset::~ExecutionLogAsset()':
Logger.cpp:(.text._ZN12ScriptCanvas17ExecutionLogAssetD2Ev[_ZN12ScriptCanvas17ExecutionLogAssetD2Ev]+0x13): undefined reference to `ScriptCanvas::ExecutionLogData::~ExecutionLogData()'
/usr/bin/ld: lib/release/libScriptCanvasDebugger.a(Logger.cpp.o): in function `ScriptCanvas::ExecutionLogAsset::~ExecutionLogAsset()':
Logger.cpp:(.text._ZN12ScriptCanvas17ExecutionLogAssetD0Ev[_ZN12ScriptCanvas17ExecutionLogAssetD0Ev]+0x16): undefined reference to `ScriptCanvas::ExecutionLogData::~ExecutionLogData()'
clang: error: linker command failed with exit code 1 (use -v to see invocation)
ninja: build stopped: subcommand failed.

```

## AZStd::string serialization within prefab issue

Commit `6d78645` adds an empty level `asdf` with a prefab `TestPrefab` using a `TestComponent`. The component uses `AZStd::string` field. When modifying with an override in the O3DE Editor, the Editor crashes each time the modification is followed by `Enter` key. It works correctly when the modification is completed by changing the focus using the mouse (clicking somewhere in the editor).

Backtrace for two debuggers are available:
- [GDB](./docs/Backtrace_gdb.log)
- [LLDB](./docs/Backtrace_lldb.log)
