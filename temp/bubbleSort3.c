#include<stdio.h>

// 这个语句的意思是：用N这个字符代替1000这个数字
// 这样设置用户可以输入的最大数量为1000个数字，可以改大
#define N 1000

// int* a 和int *a都可以，自己习惯一种写法就行
void swap(int* a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

// 这里传入的是数组a的首元素地址，也可以用“int *a”替换
// void bubbleSort(int *a, int len){
void bubbleSort(int a[], int len){
    int i, j;
    // 第一层循环，控制某次冒泡的范围为[0,i](这是一个左闭右闭的区间)
    for(i = len - 1; i >= 0; i--){
        // 第二层循环，具体执行一次冒泡，j范围是[0, i-1]（判断条件是j < i，所以只到i-1）
        // 因为if判断的时候取到了j+1,所以会比较到每个元素
        for(j = 0; j < i; j++){
            // 交换两个元素
            if(a[j] > a[j+1]){
                swap(&a[j], &a[j+1]);
            }
        }
    }
}

int main(void){
    int a[N];
    int len;
    printf("请输入待排序数字的数量：");
    scanf("%d", &len); // 需要用户先输入需要排序的数量

    int i, j;
    
    // 读入待排序的每个数字
    for(i = 0; i < len; i++){
        scanf("%d", &a[i]);
    }
    
    // 调用函数。这里是传的地址，函数的操作能对数组内部产生影响
    bubbleSort(a, len);

    // 这里进行输出，i可以重复用是因为这里重新对其赋值为0了
    // 也可以另外声明个变量k来操作
    printf("排序后的结果：");
    for(i = 0; i < len; i++){
        printf("%d ", a[i]);  // 注意%d后面有个空格，用来输出的时候分隔数字，
                              // 也可以用\n代替，显示的时候就是一个数字一排，
                              // 核心是要把数字分开
    }
    printf("\n");
    return 0;
}