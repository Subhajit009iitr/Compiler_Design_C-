using System; class Program {     
    static void Main(string[] args)     {
        int x = 10;
        int y = 20;
        int sum = AddNumbers(x, y);
        Console.WriteLine("Sum: " + sum);
        }  
    static int AddNumbers(int a, int b)     {         
        return a + b;     
    } 
} 