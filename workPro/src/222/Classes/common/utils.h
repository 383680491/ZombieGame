#pragma once

void hexEncode(const char* str, int len, char* hex);
bool hexDecode(const char* hex, int len, char* str);

void getMd5HexStr(const void* data, int len, char hexstr[33]);