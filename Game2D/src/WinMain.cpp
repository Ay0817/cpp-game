#include <DxLib.h>

#include "../include/AppSystem.hpp"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	AppSystem app;

	if (!app.Boot()) {
		return -1;
	}

	app.Run();

	// test dayo

	return 0;
}
