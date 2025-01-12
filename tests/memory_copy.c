#include <memory.h>
#include <string.h>

int main()
{
    /*
        Condition 1
        inputs:
            dest = "0000"
            from = "1234"
            bytes = 4
        result:
            dest = "1234"
    */
    {
        char input_dest[] = "0000";
        char input_from[] = "1234";
        int input_bytes = 4;
        memory_copy(input_dest,input_from,input_bytes);
        char result_dest[] = "1234";
        if (memcmp(input_dest,result_dest,4)!=0) return 1;
    }

    /*
        Condition 2
        inputs:
            dest = "0000"
            from = "1234"
            bytes = 2
        result:
            dest = "1200"
    */
    {
        char input_dest[] = "0000";
        char input_from[] = "1234";
        int input_bytes = 2;
        memory_copy(input_dest,input_from,input_bytes);
        char result_dest[] = "1200";
        if (memcmp(input_dest,result_dest,4)!=0) return 2;
    }

    /*
        Condition 3
        inputs:
            dest = "0000"
            from = "1234"
            bytes = 0
        result:
            dest = "0000"
    */
    {
        char input_dest[] = "0000";
        char input_from[] = "1234";
        int input_bytes = 0;
        memory_copy(input_dest,input_from,input_bytes);
        char result_dest[] = "0000";
        if (memcmp(input_dest,result_dest,4)!=0) return 3;
    }

    /*
        Condition 4
        inputs:
            dest = "ijkl"
            from = "abcdefgh"
            bytes = 4
        result:
            dest = "abcd"
    */
    {
        char input_dest[] = "ijkl";
        char input_from[] = "abcdefgh";
        int input_bytes = 4;
        memory_copy(input_dest,input_from,input_bytes);
        char result_dest[] = "abcd";
        if (memcmp(input_dest,result_dest,4)!=0) return 4;
    }

    /*
        Condition 5
        inputs:
            dest = "abcdefgh"
            from = "ijkl"
            bytes = 2
        result:
            dest = "ijcdefgh"
    */
    {
        char input_dest[] = "abcdefgh";
        char input_from[] = "ijkl";
        int input_bytes = 2;
        memory_copy(input_dest,input_from,input_bytes);
        char result_dest[] = "ijcdefgh";
        if (memcmp(input_dest,result_dest,8)!=0) return 5;
    }

    /*
        Condition 6
        inputs:
            dest = [200,201,202]
            from = [100,101,102]
            bytes = 4
        result:
            dest = [100,201,202]
    */
    {
        int input_dest[] = {200,201,202};
        int input_from[] = {100,101,102};
        int input_bytes = 4;
        memory_copy((char*)input_dest,(char*)input_from,input_bytes);
        int result_dest[] = {100,201,202};
        if (memcmp(input_dest,result_dest,12)!=0) return 6;
    }

    /*
        Condition 7
        inputs:
            dest = [-1,-1]
            from = [2048,4096]
            bytes = 8
        result:
            dest = [2048,4096]
    */
    {
        int input_dest[] = {-1,-1};
        int input_from[] = {2048,4096};
        int input_bytes = 8;
        memory_copy((char*)input_dest,(char*)input_from,input_bytes);
        int result_dest[] = {2048,4096};
        if (memcmp(input_dest,result_dest,8)!=0) return 7;
    }

    return 0;
}