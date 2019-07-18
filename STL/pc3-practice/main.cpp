#include "Funciones.h"

int main() {
//-----------------------------------HICIMOS EN CLASES------------------------------------------------------------------
//-----------------------------------------------------------------
    std::cout << fibo(5) << std::endl;
    std::cout << aritTerm(2.5,1,5) << std::endl;
    std::cout << aritSum(1,4,4) << std::endl;
//-----------------------------------------------------------------
    std::vector<int> v{1,3,5,7};
    int sum{0};
    for (auto it = begin(v); it != end(v) ; it++) {
        sum += *it;
    }std::cout << "Suma de la progresion: "<< sum << "\n";
//-----------------------------------------------------------------
    std::vector<int> v1 = crearPA(11,4,4);
    for(auto item: v1){ std::cout<< item << " "; } std::cout << std::endl;
    int sum1{0};
    for (auto it = begin(v1); it != end(v1) ; it++) {
        sum1 += *it;
    } std::cout << "Suma de la progresion: "<< sum1 << "\n";
//-----------------------------------------------------------------
    const int nachi = 5; int x = Fibonacci<nachi>::value;
    std::cout << "Fibonacci de "<< nachi << ": " << x << std::endl;
//------------------------------------------------------------------
    std::vector<int> v3(5);
    generatePA<int> g ( 2, 2 );
    std::generate( v3.begin(), v3.end(), g);
    std::cout << "Progresion Aritmetica: ";
    for (auto item1:v3){
        std::cout << item1 << " ";
    } std::cout << std::endl;
    int sum2{0};
    for (auto it2 = begin(v3); it2 != end(v3) ; it2++) {
        sum2 += *it2;
    } std::cout << "Suma de la progresion: "<< sum2 << std::endl << std::endl;
//----------------------------------------------------------------------------------------------------------------------


//--------------------ESTUDIANDO POR MI PARTE (HACKERRANK)--------------------------------------------------------------

//----------------BALANCED PARETHESIS HACKERRANK------------------------------------------------------------------------
    std::cout << "------------------BALANCED PARENTHESIS HACKERRANK------------------------------------\n";
    std::string s1 = "{[()]}"; std::cout << "String1: " << s1 << " "; std::cout << isBalanced(s1) << std::endl;
    std::string s2 = "{[(])}"; std::cout << "String2: " << s2 << " "; std::cout << isBalanced(s2) << std::endl;
    std::string s3 = "{{[[(())]]}}"; std::cout << "String3: " << s3 << " ";  std::cout << isBalanced(s3) << std::endl;
    std::cout << "--------------------------------------------------------------------------------------\n\n";
//----------------------------------------------------------------------------------------------------------------------

//----------------QUEUE WITH TWO STACKS HACKERRANK----------------------------------------------------------------------
    std::cout << "------------------QUEUE WITH TWO STACKS HACKERRANK------------------------------------\n";
    Queue q1; q1.enqueue(12); q1.enqueue(13); q1.enqueue(20);
    std::cout << "Primer elemento del Queue: " << q1.peek() << std::endl;
    std::cout << "Elemento borrado del Queue: " << q1.dequeue() << std::endl;
    std::cout << "Primer elemento del Queue: " << q1.peek() << std::endl;
    std::cout << "Elementos en el Queue: ";
    for (int i = 0; i < 2; ++i) {
        std::cout << q1.dequeue() << " ";
    } std::cout << std::endl;
    std::cout << "--------------------------------------------------------------------------------------\n\n";
//PARA PROBAR EN HACKERRANK
 /* std::cout << "------------------QUEUE WITH TWO STACKS HACKERRANK---------------------------\n";
    Queue q2;
    int input{0}, op{0}, val{0}; std::cin >> input;
    for (int i = 0; i < input; ++i) {
        std::cin >> op;
        if (op == 2){
            q2.dequeue();
        }
        else if(op == 3){
            std::cout << q2.peek() << std::endl;
        }else{
            std::cin >> val;
            q2.enqueue(val);
        }
    }*/
//----------------------------------------------------------------------------------------------------------------------

//--------------------MAKING ANAGRAMS HACKERRANK------------------------------------------------------------------------
    std::cout << "------------------MAKING ANAGRAMS HACKERRANK------------------------------------------\n";
    std::string str1 = "cde"; std::cout << "String1: " << str1 << std::endl;
    std::string str2 = "abc"; std::cout << "String2: " << str2 << std::endl;
    int result = makingAnagrams(str1, str2);
    std::cout << "Se deberian borrar " << result << " letras para que ambas palabras sean anagramas\n";
    std::cout << "--------------------------------------------------------------------------------------\n\n";
    //CON CIN >>
    /*string s1; getline(cin, s1);
    string s2; getline(cin, s2);
    int result = makingAnagrams(s1, s2);
    std::cout << "Se deberian borrar " << result << " letras para que ambas palabras sean anagramas";*/
//----------------------------------------------------------------------------------------------------------------------

//-------------------------------DEQUE STL HACKERRANK-------------------------------------------------------------------
    std::cout << "-----------------------DEQUE STL HACKERRANK-------------------------------------------\n";
    int arr1[5] = {3, 4, 6, 3, 4}; int arr2[7] = {3, 4, 5, 8, 1, 4, 10};
    printKMax(arr1, 5, 2);         printKMax(arr2, 7, 4);
    std::cout << "--------------------------------------------------------------------------------------\n";
    // CON CIN >>
    /*int t;
    cin >> t;
    while(t>0) {
        int n,k;
        cin >> n >> k;
        int i;
        int arr[n];
        for(i=0;i<n;i++)
            cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }*/
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------


    return 0;
}