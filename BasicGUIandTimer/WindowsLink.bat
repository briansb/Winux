rem not used
rem /PGD:"D:\Winux\BasicGUIandTimer\Release\BasicGUIandTimer.pgd" 
rem /PDB:"D:\Winux\BasicGUIandTimer\Release\BasicGUIandTimer.pdb" 
rem /ManifestFile:"Release\BasicGUIandTimer.exe.intermediate.manifest" 
link /OUT:"D:\Winux\BasicGUIandTimer\BasicGUIandTimer.exe" /MANIFEST /LTCG:incremental /NXCOMPAT /DYNAMICBASE "kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib" /DEBUG:FULL /MACHINE:X86 /OPT:REF /SAFESEH /MANIFESTUAC:"level='asInvoker' uiAccess='false'" /OPT:ICF /ERRORREPORT:PROMPT /NOLOGO /LIBPATH:"D:\wxWidgets_3.1.3\lib\vc_lib" /TLBID:1 MyApp.obj MyFrame.obj