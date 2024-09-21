std::thread cr3RefreshThread([]() {
	uintptr_t last_cr3 = Private::CR3_Init();
	while (true) {
		auto new_cr3 = Private::CR3_Init();

		if (new_cr3 != last_cr3) {
			last_cr3 = new_cr3;
		}
		Sleep(10);
	}
});
cr3RefreshThread.detach();
