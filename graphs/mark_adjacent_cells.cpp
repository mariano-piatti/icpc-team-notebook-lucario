//m = number of columns
//n = number of rows

void mark(int i,int j){
	if(i==0&&j==0){
		g[i][j].pb(mp(i,j+1));
		g[i][j].pb(mp(i+1,j));
	}else if(j==0&&i<n-1){
		g[i][j].pb(mp(i+1,j));
		g[i][j].pb(mp(i-1,j));
		g[i][j].pb(mp(i,j+1));
	}else if(j==0&&i==n-1){
		g[i][j].pb(mp(i-1,j));
		g[i][j].pb(mp(i,j+1));
	}else if(i==0&&j<m-1){
		g[i][j].pb(mp(i+1,j));
		g[i][j].pb(mp(i,j+1));
		g[i][j].pb(mp(i,j-1));
	}else if(i==0&&j==m-1){
		g[i][j].pb(mp(i,j-1));
		g[i][j].pb(mp(i+1,j));
	}else if(j==m-1&&i<n-1){
		g[i][j].pb(mp(i+1,j));
		g[i][j].pb(mp(i,j-1));
		g[i][j].pb(mp(i-1,j));
	}else if(j==m-1&&i==n-1){
		g[i][j].pb(mp(i,j-1));
		g[i][j].pb(mp(i-1,j));
	}else{
		g[i][j].pb(mp(i+1,j));
		g[i][j].pb(mp(i,j+1));
		g[i][j].pb(mp(i,j-1));
		g[i][j].pb(mp(i-1,j));
	}
}
