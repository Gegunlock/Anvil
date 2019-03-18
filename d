* Unmerged path Anvil_DLL/Anvil_DLL.vcxproj
* Unmerged path Anvil_DLL/Anvil_DLL.vcxproj.filters
* Unmerged path Anvil_DLL/Anvil_DLL.vcxproj.user
* Unmerged path Anvil_DLL/Debug/Anvil_DLL.tlog/Anvil_DLL.lastbuildstate
* Unmerged path Anvil_DLL/Debug/Anvil_DLL.tlog/CL.read.1.tlog
[1mdiff --git a/Anvil_DLL/Main/Init/Init.cpp b/Anvil_DLL/Main/Init/Init.cpp[m
[1mindex fa2d036..d98f2d1 100644[m
[1m--- a/Anvil_DLL/Main/Init/Init.cpp[m
[1m+++ b/Anvil_DLL/Main/Init/Init.cpp[m
[36m@@ -12,7 +12,7 @@[m [mnamespace Init[m
 {[m
 	DWORD WINAPI Init(LPVOID lpThreadParameter)[m
 	{[m
[31m-		Tools::SetupConsole("Anvil Beta");[m
[32m+[m		[32mTools::SetupConsole("Anvil");[m
 		std::cout << "INJECTED" << std::endl;[m
 [m
 		Tools::VirtualMethodTableHook IVEngineClient_hook(g_Interfaces.GetIVEngineClientInterface());[m
* Unmerged path Anvil_DLL/Main/Main.cpp
[1mdiff --git a/Anvil_DLL/SDK/IVEngineClient/IVEngineClient.h b/Anvil_DLL/SDK/IVEngineClient/IVEngineClient.h[m
[1mindex 24d5a2d..0b2cba6 100644[m
[1m--- a/Anvil_DLL/SDK/IVEngineClient/IVEngineClient.h[m
[1m+++ b/Anvil_DLL/SDK/IVEngineClient/IVEngineClient.h[m
[36m@@ -27,11 +27,11 @@[m [mnamespace SDK[m
 		virtual void GetViewAngles(QAngle& Angles);  // 18[m
 		virtual int	 SetViewAngles(QAngle& Angles);  // 19[m
 		virtual int  GetMaxClients(void);  //20[m
[31m-		virtual void unknown21(void);[m
[31m-		virtual void unknown22(void);[m
[31m-		virtual void unknown23(void);[m
[31m-		virtual void unknown24(void);[m
[31m-		virtual void unknown25(void);[m
[32m+[m		[32mvirtual void unknown21(void);  //21[m
[32m+[m		[32mvirtual void unknown22(void);  //22[m
[32m+[m		[32mvirtual void unknown23(void);  //23[m
[32m+[m		[32mvirtual void unknown24(void);  //24[m
[32m+[m		[32mvirtual void unknown25(void);  //25[m
 		virtual bool IsInGame(void);  // 26[m
 		virtual bool IsConnected(void);  //27[m
 	};[m
* Unmerged path Anvil_DLL/Tools/Utilitys/Utility.h
* Unmerged path Anvil_DLL/Tools/VMT/VMTableHook.cpp
* Unmerged path Anvil_DLL/Tools/VMT/VMTableHook.h
* Unmerged path Injector_Exe/Debug/Injector_EXE.tlog/CL.read.1.tlog
* Unmerged path Injector_Exe/Debug/Injector_EXE.tlog/Injector_EXE.lastbuildstate
* Unmerged path Injector_Exe/Debug/Injector_EXE.tlog/link.read.1.tlog
* Unmerged path Injector_Exe/Injector.vcxproj
