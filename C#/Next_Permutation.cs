using System;
using ReadWord;
public class Next_Permutatuon
{
    public static void Main(string[] args)
    {
        ReadWord.read();
        int[] arr = {5,4,3,2,1};
        nextPermutation(arr);
        foreach (int item in arr)
        {
            System.Console.Write(item+" ");

        }
    }
    public static void nextPermutation(int[] arr)
    {
        int i=arr.Length,j=arr.Length;
        while(--i>0){if(arr[i-1]<arr[i]) break;} 
        if(i>0)while(--j>i){if(arr[i-1]<arr[j]) break;}
        swap(arr,i-1,j);
        reverse(arr,i,arr.Length-1);
    }
    public static bool swap(int[] arr,int a,int b)
    {
        if(a>=0 && a<arr.Length && b>=0 && b<arr.Length)
        {
            int temp = arr[a]; arr[a]=arr[b]; arr[b]=temp;
            return true;
        }
        else
        {
            return false;
        }
    }
    public static bool reverse(int[] arr,int begin,int end)
    {
        if(begin >= 0 && end <= arr.Length && begin <= end)
        {
            while(begin<end)
            {
                swap(arr,begin++,end--);
            }
            return true;
        }
        else
        {
            return false;
        }
    }
}