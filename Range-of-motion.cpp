/********************************************************************
用回溯法实现，从起点出发，从每个点的左右上下开始寻找，如果任何一个方向
已经寻找过或者超出边界或者不满足条件，则停止这个方向的寻找，从另外一个
方向开始寻找每次满足条件，则满足条件个数+1，这样一直找，直到没有满足条
件的点
*************************************************************************/

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold <= 0 || rows <= 0 || cols <= 0)
            return 0;
        bool *flag = new bool[rows*cols]();
        int count = 0;
        canReachNum(threshold,rows,cols,0,0,count,flag);
        return count;
            
        
    }
private:
    void canReachNum(int threshold, int rows, int cols,int i, int j, int& count,bool* flag)
    {
        int index = i*cols + j;
        if(i < 0 || j < 0 || i >= rows || j >= cols || flag[index])
            return;
        int th = theNum(i) + theNum(j);
        if(th > threshold)
            return;
        flag[index] = true;
        count++;
        canReachNum(threshold,rows,cols,i+1,j,count,flag);
        canReachNum(threshold,rows,cols,i-1,j,count,flag);
        canReachNum(threshold,rows,cols,i,j+1,count,flag);
        canReachNum(threshold,rows,cols,i,j-1,count,flag);
        return;
    }
    int theNum(int i)
    {
        int Num = 0;
        while(i)
        {
            Num += i%10;
            i = i/10;
        }
        return Num;
    }
    
};
