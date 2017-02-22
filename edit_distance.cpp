/*This is an implementation of smith-waterman algorithm.
 *The problem aims to align two strings with minimum costs
 *For example, to align grade and grid, the minimum cost is 2:
 * g r a d e
 * g r i d _
 */

//returns the minimum distance; word1 is the 1st string; word2 is 2nd string
int minDistance(string word1, string word2) {
  int size1 = word1.size(); int size2 = word2.size();

  int **arr = new int*[size1+1];
  for(int i = 0; i < size1 + 1; i++){
    arr[i] = new int[size2+1];
    for(int j = 0; j < size2 + 1; j++){
      arr[i][j] = 0;
    }
  }
  //When aligning string with a string with length 0, the cost the deleting one string
  for(int i = 1; i < size2 + 1; i++)
    arr[0][i] = i;

  for(int j = 1; j < size1 + 1; j++)
    arr[j][0] = j;

  for(int i = 1; i  < size1 + 1; i++){
    for(int j = 1; j < size2 + 1; j++){
      int cost = word1[i-1] == word2[j-1] ? 0 : 1;
      //here are the 3 cases for the recurrence relation
      arr[i][j] = min(min(cost+arr[i-1][j-1],1+arr[i-1][j]),1+arr[i][j-1]);
    }
  }

  return arr[size1][size2];
}
