for (auto i = 0; i < 255; i++) {
    if (NA::Read<__int32>(virtualaddy + (i * 0x1000)) == 0x905A4D) {
        va_text = virtualaddy + ((i + 1) * 0x1000);
    }
}
