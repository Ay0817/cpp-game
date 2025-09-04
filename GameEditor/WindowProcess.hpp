#ifndef WINDOW_PROCESS_HPP
#define WINDOW_PROCESS_HPP

#include <Windows.h>

#include "../GameLib2D/ImGui/imgui_impl_win32.h"

LRESULT WINAPI WindowProcess(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

#endif
