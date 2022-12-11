public static int findWidestLevel(Node root) {
        List<Node> children = NULL;
        int level = 0, maxlevel = 0;
        List <int> levelwidth = new ArrayList<>();
      
        findNumberOfChildren(root, levelwidth, level++);
      
        for (int i = 0; i < levelwidth.size(); i++) {
          System.out.print(levelwidth[i]);
        }
        System.out.println();
        maxlevel = findMaxIndex(levelwidth);
      
        return maxlevel;
    }

   private int findNumberOfChildren(Node node, List<int> levelwidth, int level)
   {
      List<Node> children = NULL;
     
      children = node.getChildren();
      
      if (children.size() == 0)
        return 0;
     
      levelwidth[level] += children.size();
     
      for (int i = 0; i <children.size(); i++) {
        findNumberofChildren(children[i], levelwidth, level++);
      }
     
      return 0;
   }
  
   private int findMaxIndex(List<int> arr) {
     int maxindex = 0, max = 0;
     
     for (int i = 0; i < arr.size(); i++) {
       if (arr[i] > max) {
         maxindex = i;
         max = arr[i];
       }
     }
     
     return maxindex;
   }
  



