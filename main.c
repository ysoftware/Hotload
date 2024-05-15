#include <stdio.h>
#include <dlfcn.h>

void *library_handle;
void (*greet)();

int load_library() {
    library_handle = dlopen("./build/libmylibrary.so", RTLD_LAZY);

    if (!library_handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    greet = dlsym(library_handle, "greet");
    if (!greet) {
        fprintf(stderr, "Error: %s\n", dlerror());
        dlclose(library_handle);
        return 2;
    }

    return 0;
}

int main() {
    printf("Hello from the main!\n");

    int code = load_library();
    if (code != 0) return code;

    greet();

    dlclose(library_handle);
    return 0;
}
