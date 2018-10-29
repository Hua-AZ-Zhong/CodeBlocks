public class Array{
	public static void main(String args[]){
		int array[] = new int[10];
		for(int i=0;i<array.length;i++)
			array[i] = (i+1)*2 + 1;
		for(int i=0;i<array.length;i++)
			System.out.println("array[" + i +"] = " + array[i]);

		int dataA[] = new int[] {111,2,33,46,5};
		int dataB[] = new int[] {6,7,8,9,0};
		//System.arraycopy(dataB,1,dataA,2,3);
		printArray(dataA);
		java.util.Arrays.sort(dataA);
		printArray(dataA);

		int dataC[][] = new int[][] { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}
		};
		printTwoArray(dataC);
		reverse(dataC);
		printTwoArray(dataC);
	}

	public static void printArray(int array[]){
		for(int i=0;i<array.length;i++)
			System.out.println("array[" + i +"] = " + array[i]);
	}
	public static void reverse(int array[][]){
		for(int x=0; x < array.length; x++){
			for(int y=0; y <= x; y++){
				/*
				if(x!=y){ // This condition should be added, ohterwise the array[x][x] will be zero
					array[x][y] = array[x][y] + array[y][x];
					array[y][x] = array[x][y] - array[y][x];
					array[x][y] = array[x][y] - array[y][x];
				}
				*/
				int temp = array[x][y];
				array[x][y] = array[y][x];
				array[y][x] = temp;

			}
		}
	}
	public static void printTwoArray(int array[][]){
		for(int x=0; x < array.length; x++){
			for(int y=0; y < array[x].length; y++){
				System.out.print(array[x][y] + ",");
			}
			System.out.println();
		}
		System.out.println();
	}
}
