    
public class Q{
	
	public static void main(String[] args){
		
		int[][] matrix = new int[][] 
			{{0, 0, 0, 1, 1, 1},
			 {0, 0, 0, 1, 1, 1},
			 {1, 1, 1, 1, 1, 1},
			 {1, 1, 1, 1, 1, 1},
			 {1, 1, 1, 1, 1, 1}};
			 
		int[][] matrix3 = new int[][] 
			{{1, 1, 1, 1, 1, 1},
			 {1, 1, 1, 1, 1, 1},
			 {1, 1, 1, 1, 1, 1},
			 {1, 1, 1, 1, 1, 1},
			 {1, 1, 1, 1, 1, 1},
			 {1, 1, 1, 1, 1, 1}};
			 
		int[][] matrixQ = new int[][] 
			{{1, 0, 0, 0, 0, 0},
			 {0, 1, 0, 1, 1, 1},
			 {0, 0, 1, 0, 1, 0},
			 {1, 1, 0, 0, 1, 0},
			 {1, 0, 1, 1, 0, 0},
			 {1, 0, 0, 0, 0, 1}};
		int[][] matrixQsol = new int[][] 
			{{1, 0, 0, 0, 0, 0},
			 {0, 0, 0, 1, 1, 1},
			 {0, 0, 0, 0, 1, 0},
			 {1, 1, 0, 0, 1, 0},
			 {1, 0, 0, 0, 0, 0},
			 {1, 0, 0, 0, 0, 1}};
			 
		display(matrix);
		DeleteIslands(matrix);
		display(matrix);
		
	}
	
	public static void display(int[][] matrix)
    {
        for (int i = 0; i < matrix.length; i++)
        {
            for (int j = 0; j < matrix[0].length; j++)
            {
                System.out.print(matrix[i][j] + " ");
            }
			System.out.println();
        }
		System.out.println();
	}
	
	public static void DeleteIslands(int[][] matrix)
    {
        for (int i = 0; i < matrix.length; i++)
        {
            for (int j = 0; j < matrix[0].length; j++)
            {
                if (matrix[i][j] == 1 && !CheckIfEdge(matrix, i, j))
                {
                    matrix[i][j] = 2;
                }
            }
        }

        for (int i = 0; i < matrix.length; i++)
        {
            for (int j = 0;j < matrix[0].length; j++)
            {
                if (matrix[i][j] == 2)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    public static boolean CheckIfEdge(int[][] matrix, int i, int j)
    {
        if (i <= 0 || i >= matrix.length - 1 || j <= 0 || j >= matrix[0].length - 1)
        {
            return true;
        }

        if (matrix[i-1][j] == 0 || matrix[i+1][j] == 0 || matrix[i][j - 1] == 0 || matrix[i][j + 1] == 0 || matrix[i - 1][j - 1] == 0 || matrix[i + 1][j + 1] == 0)
        {
            return true;
        }

        return false;
    }
}