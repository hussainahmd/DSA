import java.util.ArrayList;

public class Run {

    static int N = 5;
    static int[][] board;

    static ArrayList<int[][]> list = new ArrayList<>();
    public static void main(String[] args){

        board = new int[N][N];
        //display(board);

        N_Queens();

        System.out.println("SOL : " + list.size());
    }

    static void N_Queens()
    {
        rec(0);
    }

    //go to the depth of the board while checking a solution for all rows and columns
    static void rec(int row)
    {
        //a solution has been found
        if (row == N)
        {
            int[][] solution = new int[N][N];
            for(int i = 0; i < N; i++)
                solution[i] =  board[i].clone();

            list.add(solution);
            display();
        }
        else
        {
            //check for all the columns of the same row
            for (int col = 0; col < N; col++)
            {
                if (isSafe(row, col))
                {
                    board[row][col] = 1; //place a queen
                    rec(row + 1); //one complete possibility is checked
                    board[row][col] = 0; //replace the cell with 0 to check further solutions
                }
            }
        }
    }

    static boolean isSafe(int row, int col)
    {
        int col_Left = col;
        int col_Right = col;
        while (row >= 0)
        {
            //check the left upper diagonal cell
            if (col_Left >= 0 && board[row][col_Left] == 1)
                return false;

            //check the top cell
            if (board[row][col] == 1)
                return false;

            //check the right upper diagonal cell
            if (col_Right < N && board[row][col_Right] == 1)
                return false;

            row --; //go to previous row
            col_Left --;
            col_Right ++;
        }
        //return true if no threat
        return true;
    }
    static void display()
    {
        for (int i = 0; i < N; i++)
        {

            for (int j = 0; j < N; j++)

                if (board[i][j] == 1)
                    System.out.print("   Q");
                else
                    System.out.print("   _");

            System.out.print("\n\n");
        }
        System.out.print("\n");
    }
}
