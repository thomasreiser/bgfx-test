#include <bx/allocator.h>
#include <bimg/encode.h>

static inline bx::AllocatorI* getDefaultAllocator() {
  static bx::DefaultAllocator allocator;
  return &allocator;
}

int main(int argc, const char** argv) {
    bimg::ImageContainer* src = bimg::imageAlloc(getDefaultAllocator(),
        bimg::TextureFormat::BGRA8, 1, 1, 1, 1, false, false);
    memcpy(src->m_data, "\xff\x00\x00\xff", 4);

    bimg::ImageContainer* dest = bimg::imageEncode(getDefaultAllocator(),
        bimg::TextureFormat::BC3, bimg::Quality::Highest, *src);

    bimg::imageFree(src);

    return EXIT_SUCCESS;
}