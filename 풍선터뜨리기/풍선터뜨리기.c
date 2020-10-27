// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>
//
// int min(int left, int right,int* a);
// // a_len은 배열 a의 길이입니다.
// int solution(int a[], size_t a_len) {
//     int left = 0,right = 0,answer = 2;
//     if(a_len <= 2) {
//         return a_len;
//     }
//
//     for(int i = 1;i<=a_len-2;i++) {
//         left = min(0,i,a);
//         right = min(i+1,a_len-1,a);
//         if(a[i]< a[left] || a[i] < a[right] ) {
//             answer++;
//         }
//     }
//     return answer;
// }
//
// int min(int left, int right,int* a) {
//     int min = left;
//     for(int i = left; i != right;i++){
//         if(a[min] > a[i])   min = i;
//     }
//     return min;
// }
// //==============================================================================================
// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>
//
// // a_len은 배열 a의 길이입니다.
// int min(int left, int right,int* a);
//
// int solution(int a[], size_t a_len) {
//
//     int leftMin = a[0];
//     int rightMin = min(2,a_len-1,a);
//     int answer = 1;
//     if(a_len <= 2)  return a_len;
//
//     for(int i = 1; i<a_len-2; i++) {
//       if(a[i] == rightMin)  rightMin = min(i+1,a_len-1,a);
//       if(a[i]< leftMin || a[i] < rightMin ) answer++;
//       if(leftMin > a[i])  leftMin = a[i];
//
//     }
//
//     return answer;
// }
//
// int min(int left, int right,int* a) {
//     int min = left;
//     for(int i = left; i != right;i++){
//         if(a[min] > a[i])   min = i;
//     }
//     return a[min];
// }

//=====================================================================================
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// a_len은 배열 a의 길이입니다.
int solution(int a[], size_t a_len) {

    int min = a[0]; //임시최솟
    int answer = 2; //앞 뒤 값 초기화
    int least = a[0]; //배열에서 최솟값
    int temp;         //최솟값의 인덱스

    for(int i = 1;i < a_len;i++) {  //배열 중 최솟값 찾기
      if(least > a[i]) {
        least = a[i];
        temp = i;
      }
    }
    answer++; //배열에서 가장 작은 값 체크
    if(temp == 0 || temp == a_len-1)  answer--; //앞 뒤 값 중 최솟값이 존재할 경우 answer--

    for(int i = 1;i<temp;i++) { //최솟값 전까지
      if(min > a[i]) {
        answer++;
        min = a[i];
      }
    }

    min = a[a_len-1]; //가장 마지막 원소 min에 초기화
    for(int i = a_len-2;temp < i;i--) { //뒤에서 시작해서 min 찾으며 비교
      if(min > a[i]) {
        answer++;
        min = a[i];
      }
    }

    return answer;
}
