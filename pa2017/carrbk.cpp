#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int t[3000][3000];
int n;

bool ispossible(int y, int x,int b, int a){
	//cout<<x<<y<<endl;

	if(!(y+1>=n)){
		if(t[y+1][x]==1)
			return 1;
	}
	if(!(y-1<0)){
		if(t[y-1][x]==1)
			return 1;
	}
	if(!(x+1>=n)){
		if(t[y][x+1]==1)
			return 1;
	}
	if(!(x-1<0)){
		if(t[y][x-1]==1)
			return 1;
	}


	if(!(y+1>=n)&&y+1!=b){
		if(t[y+1][x]==-1)
			return ispossible(y+1,x,y,x);
	}
	if(!(y-1<0)&&y-1!=b){
		if(t[y-1][x]==-1)
			return ispossible(y-1,x,y,x);
	}
	if(!(x+1>=n)&&x+1!=a){
		if(t[y][x+1]==-1)
			return ispossible(y,x+1,y,x);
	}
	if(!(x-1<0)&&x-1!=a){
		if(t[y][x-1]==-1)
			return ispossible(y,x-1,y,x);
	}
	return 0;
}

bool isempty(int y, int x){
	if(!t[y][x])
		return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	int k, res=0;
	char carac;
	cin>>n>>k;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>carac;
			if(carac=='#'){
				t[i][j]=1;
			}
		}
	}
	if(k==4){
		//1st
		for(int y1=0; y1<n; y1++){
			for(int x1=0; x1<n; x1++){
				if(isempty(y1, x1)){
					t[y1][x1]=-1;
					//2nd
					for(int y2=y1; y2<n; y2++){
						int x2;

						if(y2==y1)
							x2=x1;
						else
							x2=0;

						for(; x2<n; x2++){
							if(isempty(y2, x2)){
								t[y2][x2]=-1;
								//3rd
								for(int y3=y2; y3<n; y3++){
									int x3;

									if(y3==y2)
										x3=x2;
									else
										x3=0;

									for(; x3<n; x3++){
										if(isempty(y3, x3)){
											t[y3][x3]=-1;
											//4th
											for(int y4=y3; y4<n; y4++){
												int x4;

												if(y4==y3)
													x4=x3;
												else
													x4=0;


												for(; x4<n; x4++){
													if(isempty(y4, x4)){

														t[y4][x4]=-1;
														if(ispossible(y1, x1, -1, -1) && ispossible(y2, x2, -1, -1) && ispossible(y3, x3, -1, -1) && ispossible(y4, x4, -1, -1)){
															res++;
															res%=MOD;
														}
														t[y4][x4]=0;
													}

												}
											}
											t[y3][x3]=0;
										}
									}
								}
								t[y2][x2]=0;
							}
						}
					}
					t[y1][x1]=0;
				}
			}
		}
	}
	else if(k==3){
		//1st
		for(int y1=0; y1<n; y1++){
			for(int x1=0; x1<n; x1++){
				if(isempty(y1, x1)){
					t[y1][x1]=-1;
					//2nd
					for(int y2=y1; y2<n; y2++){
						int x2;

						if(y2==y1)
							x2=x1;
						else
							x2=0;

						for(; x2<n; x2++){
							if(isempty(y2, x2)){
								t[y2][x2]=-1;
								//3rd
								for(int y3=y2; y3<n; y3++){
									int x3;

									if(y3==y2)
										x3=x2;
									else
										x3=0;

									for(; x3<n; x3++){
										if(isempty(y3, x3)){
											t[y3][x3]=-1;

											if(ispossible(y1, x1, -1, -1) && ispossible(y2, x2, -1, -1) && ispossible(y3, x3, -1, -1)){
												res++;
												res%=MOD;
											}
											t[y3][x3]=0;
										}
									}
								}
								t[y2][x2]=0;
							}
						}
					}
					t[y1][x1]=0;
				}
			}
		}
	}
	else if(k==2){
		//1st
		for(int y1=0; y1<n; y1++){
			for(int x1=0; x1<n; x1++){
				if(isempty(y1, x1)){
					t[y1][x1]=-1;
					//2nd
					for(int y2=y1; y2<n; y2++){

						int x2;

						if(y2==y1)
							x2=x1;
						else
							x2=0;

						for(; x2<n; x2++){
							if(isempty(y2, x2)){
								t[y2][x2]=-1;
								//cout<<endl<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl<<endl;
								if(ispossible(y1, x1, -1, -1) && ispossible(y2, x2, -1, -1)){
									//cout<<"Ok"<<endl;

									res++;
									res%=MOD;
								}

								t[y2][x2]=0;
							}
						}
					}
					t[y1][x1]=0;
				}
			}
		}
	}
	else{
		//1st
		for(int y1=0; y1<n; y1++){
			for(int x1=0; x1<n; x1++){
				if(isempty(y1, x1)){
					t[y1][x1]=-1;

					if(ispossible(y1, x1, -1, -1)){
						res++;
						res%=MOD;
					}
					t[y1][x1]=0;
				}
			}
		}
	}
	cout<<res<<'\n';
	return 0;
}
