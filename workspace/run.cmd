@echo set vs variable

@set sln=.\workspace\PQMInvestigator.sln

@set CR_VC_VER=9.0
@set CR_BUILD_PLATFROM=EPCS-9000 (ARMV4I)
@set CR_ERR_INIT_COLOR=4F

@echo check Visual C++ %CR_VC_VER%
@call :GetVCDir
@if "%CR_VC_INSTALL_DIR%"=="" (
@echo Visual C++ %CR_VC_VER% not install
goto err_exit
)

@echo %CR_VC_INSTALL_DIR%vcvarsall.bat
@call "%CR_VC_INSTALL_DIR%vcvarsall.bat

@echo %sln%
devenv %sln% /Rebuild  "Release|EPCS-9000 (ARMV4I)"


@set sln=.\workspace\E6100WebService.sln

@set CR_VC_VER=9.0
@set CR_BUILD_PLATFROM=EPCS-9000 (ARMV4I)
@set CR_ERR_INIT_COLOR=4F

@echo check Visual C++ %CR_VC_VER%
@call :GetVCDir
@if "%CR_VC_INSTALL_DIR%"=="" (
@echo Visual C++ %CR_VC_VER% not install
goto err_exit
)

@echo %CR_VC_INSTALL_DIR%vcvarsall.bat
@call "%CR_VC_INSTALL_DIR%vcvarsall.bat

@echo %sln%
devenv %sln% /Rebuild  "Release|EPCS-9000 (ARMV4I)"

@call .\distribution\package_release.bat

@echo 
@goto end

:GetVCDir
@echo GetVCDir
@call :GetVCDirHelper HKLM > nul 2>&1
@if errorlevel 1 call :GetVCDirHelper HKCU > nul 2>&1
@exit /B 0

:GetVCDirHelper
@echo GetVCDirHelper
@if %PROCESSOR_ARCHITECTURE:~-1%==4 (set "ZCLIENT_REG_ARCH_KEY=Wow6432Node\" ) else "ZCLIENT_REG_ARCH_KEY="
@for /F "tokens=1,2*" %%i in ('reg query "%1\SOFTWARE\%ZCLIENT_REG_ARCH_KEY%Microsoft\VisualStudio\%CR_VC_VER%\Setup\VC" /v "ProductDir"') DO (
	if "%%i"=="ProductDir" (
		SET "CR_VC_INSTALL_DIR=%%k"
	)
)

:end 
@echo on
