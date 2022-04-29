import java.util.*;

public class Solution {

	// keep track of explored indecies
	static Set<Integer> exploredIndex = new HashSet<Integer>();

    public static boolean canWin(int leap, int[] game) {
        // Return true if you can win the game; otherwise, return false.
		//System.out.println("canWin("+leap+", game)"); // debug	
		
		exploredIndex.clear(); // clear HashSet
		boolean canWin = playGame(leap, game, 0);

        return canWin;
	}
	
	public static boolean playGame(int leap, int[] game, int curIndex) {
		// Check if game is won
		if (curIndex >= game.length-1)
		{
			return true;
		}

		exploredIndex.add(curIndex); // add to set of explored indecies 
		
		boolean canMoveBack, canMoveForward, canLeap;
		// set if canMoveBack
		if(curIndex-1 >= 0) // check if index is valid index
		{
			if(game[curIndex-1] == 0 && exploredIndex.contains(curIndex-1) == false ) // check if spot is 0 and hasn't been explored
				canMoveBack = true;
			else
				canMoveBack = false;
		}
		else
			canMoveBack = false;

		// set if canMoveForward
		if(game[curIndex+1] == 0 && exploredIndex.contains(curIndex+1) == false ) // check if spot is 0 and hasn't been explored
			canMoveForward = true;
		else
			canMoveForward = false;

		// set if canLeap
		if(curIndex + leap >= game.length) // spot is past last index
			canLeap = true;
		else if (game[curIndex+leap] == 0 && exploredIndex.contains(curIndex+leap) == false ) // check if spot is 0 and hasn't been explored
			canLeap = true;
		else
			canLeap = false;

		
		if(canLeap){
			if( playGame(leap, game, curIndex+leap) == true)
				return true;
		}
		if(canMoveForward && playGame(leap, game, curIndex+1) == true)
			return true;
		if(canMoveBack && playGame(leap, game, curIndex-1) == true)
			return true;

		return false;
	}

    public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		//System.out.print("Enter q: "); // debug
        int q = scan.nextInt();
        while (q-- > 0) {
			//System.out.print("Enter n: "); // debug
			int n = scan.nextInt();
			//System.out.print("Enter leap: "); // debug
            int leap = scan.nextInt();
            
			int[] game = new int[n];
			//System.out.print("Enter game: "); // debug
            for (int i = 0; i < n; i++) {
                game[i] = scan.nextInt();
            }

            System.out.println( (canWin(leap, game)) ? "YES" : "NO" );
        }
        scan.close();
    }
}

