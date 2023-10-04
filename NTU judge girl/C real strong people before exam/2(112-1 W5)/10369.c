#include <stdio.h>
int main(){
	int n;
	double mean=0.0,stdev2=0.0,l[100156];
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%lf",l+i);
		mean+=l[i];
	}
	mean=mean/n;
	for(int i=0;i<n;++i)
		stdev2+=(l[i]-mean)*(l[i]-mean);
	stdev2=stdev2/n;
	printf("%lf\n%lf",mean,stdev2);
}
