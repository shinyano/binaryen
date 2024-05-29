#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input file> [wasm-opt options]\n", argv[0]);
        return 1;
    }

    // 构建命令字符串
    char command[1024];
    snprintf(command, sizeof(command), "./wasm-opt %s -o /dev/null", argv[1]);

    // 将额外的参数添加到命令中
    for (int i = 2; i < argc; ++i) {
        strncat(command, " ", sizeof(command) - strlen(command) - 1);
        strncat(command, argv[i], sizeof(command) - strlen(command) - 1);
    }

    int ret = system(command);
    if (ret != 0) {
        fprintf(stderr, "wasm-opt failed\n");
    }

    return ret;
}
