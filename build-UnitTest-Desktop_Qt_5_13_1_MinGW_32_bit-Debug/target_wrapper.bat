@echo off
SetLocal EnableDelayedExpansion
(set PATH=C:\Qt\Qt5.13.1\5.13.1\mingw73_32\bin;!PATH!)
if defined QT_PLUGIN_PATH (
    set QT_PLUGIN_PATH=C:\Qt\Qt5.13.1\5.13.1\mingw73_32\plugins;!QT_PLUGIN_PATH!
) else (
    set QT_PLUGIN_PATH=C:\Qt\Qt5.13.1\5.13.1\mingw73_32\plugins
)
%*
EndLocal
