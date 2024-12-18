#include "../exercise.h"
#include <numeric>

// READ: `std::accumulate` <https://zh.cppreference.com/w/cpp/algorithm/accumulate>

int main(int argc, char **argv) {
    using DataType = float;
    int shape[]{1, 3, 224, 224};
    // TODO: 调用 `std::accumulate` 计算：
    //       - 数据类型为 float；
    //       - 形状为 shape；
    //       - 连续存储；
    //       的张量占用的字节数
    size_t totalElements = std::accumulate(
        std::begin(shape), // 起始迭代器
        std::end(shape),   // 结束迭代器
        1,                 // 初始值为 1（乘法的单位元素）
        std::multiplies<>()// 乘法运算
    );
    size_t size = totalElements * sizeof(DataType);
    ASSERT(size == 602112, "4x1x3x224x224 = 602112");
    return 0;
}
