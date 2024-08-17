#pragma once

// メモリ安全解放
#ifndef SAVE_RELEASE || _SAVE_RELEASE
#define SAVE_RELEASE

#define SAVE_FREE(p) {if((p)!=nullptr){free(p);(p)=nullptr;}}
#define SAVE_DELETE(p) {if((p)!=nullptr){delete (p);(p) = nullptr;}}
#define SAVE_DELETE_ARRAY(p) {if((p)!=nullptr){delete[] (p);(p) = nullptr;}}
#endif
