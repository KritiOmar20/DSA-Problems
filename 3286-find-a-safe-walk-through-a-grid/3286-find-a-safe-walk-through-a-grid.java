class Solution {
    static int[] dr={-1,1,0,0};
    static int[] dc={0,0,-1,1};
    static class Pair{
        int row;
        int col;
        int health;
        Pair(int row,int col,int health){
            this.row=row;
            this.col=col;
            this.health=health;
        }
    }
    public boolean findSafeWalk(List<List<Integer>> grid, int health) {
        int n=grid.size();
        int m=grid.get(0).size();
        boolean[][] vis=new boolean[n][m];
        PriorityQueue<Pair> pq=new PriorityQueue<>((a,b) -> Integer.compare(b.health,a.health));
        if(grid.get(0).get(0)==1){
            pq.offer(new Pair(0,0,health-1));
        }else{
            pq.offer(new Pair(0,0,health));
        }
        while(!pq.isEmpty()){
            Pair curr=pq.poll();
            int r=curr.row;
            int c=curr.col;
            int h=curr.health;
            if(r==n-1 && c==m-1 && h >=1){
                return true;
            }
            for(int i=0;i<4;i++){
                int nR=r+dr[i];
                int nC=c+dc[i];
                if(nR>=0 && nC>=0 && nR<n && nC<m && !vis[nR][nC]){
                    vis[nR][nC]=true;
                    if(grid.get(nR).get(nC)==1){
                        pq.offer(new Pair(nR,nC,h-1));
                    }else{
                        pq.offer(new Pair(nR,nC,h));
                    }

                }
            }
        }
        return false;
    }
}