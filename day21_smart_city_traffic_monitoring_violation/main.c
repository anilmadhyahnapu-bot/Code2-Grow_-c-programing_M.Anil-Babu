#include <stdio.h>
#include <stdlib.h>
#define MAX_V 30
#define SLMT 80
#define NL 4
void inputData(int v[], int s[], int l[], int *c) {
int i = 0, id, sp, ln;
printf("Enter (ID Speed Lane), ID=-1 to stop:\n");
while (i < MAX_V) {
printf("%d: ", i + 1);
if (scanf("%d %d %d", &id, &sp, &ln) != 3 || id == -1) break;
if (id < 1000 || id > 9999 || sp <= 0 || ln < 1 || ln > NL) { printf("Invalid!\n"); continue; }
v[i]=id; s[i]=sp; l[i]=ln; i++;
}
*c = i;
}
int countSpeedViolations(const int s[], int c, int *hS, int *lS) {
int v = 0;
if (c == 0) return 0;
*hS = s[0]; *lS = s[0];
for (int i = 0; i < c; i++) {
if (s[i] > SLMT) v++;
if (s[i] > *hS) *hS = s[i];
if (s[i] < *lS) *lS = s[i];
}
return v;
}
int countLaneViolations(const int v[], const int l[], int c, int *mI, int *mS) {
int vls = 0; *mI = -1; *mS = -1;
for (int i = 0; i < c; i++) {
int expected = v[i] % NL;
if (expected != l[i]) {
vls++;
int sev = abs(expected - l[i]); // Severity: abs((VehicleID % 4) - lane)
if (sev > *mS) { *mS = sev; *mI = i; }
}}
return vls;
}
int busiestLane(const int lc[]) {
int mx = lc[0], ln = 1;
for (int i = 1; i < NL; i++) if (lc[i] > mx) { mx = lc[i]; ln = i+1; }
return ln;
}
int leastBusyLane(const int lc[]) {
int mn = MAX_V + 1, ln = 1;
for (int i = 0; i < NL; i++) {
if (lc[i] < mn) { mn = lc[i]; ln = i+1; }
}
return ln;
}
void displayReport(const int v[], const int s[], const int l[], const int sv[], const int lv[], int c) {
printf("\nID |Spd|Ln|SV|LV\n");
for (int i = 0; i < c; i++)
printf("%4d|%3d|%2d|%2d|%2d\n", v[i], s[i], l[i], sv[i], lv[i]);
}
int main() {
int v[MAX_V], s[MAX_V], l[MAX_V], c=0, sv[MAX_V]={0}, lv[MAX_V]={0}, lc[NL]={0};
inputData(v, s, l, &c);
if (!c) return 0;
int hS=0, lS=100000, mI=-1, mS=-1, tSV, tLV;
tSV = countSpeedViolations(s, c, &hS, &lS);
tLV = countLaneViolations(v, l, c, &mI, &mS);
for (int i=0; i<c; i++) {
if (s[i] > SLMT) sv[i]=1;
if ((v[i] % NL) != l[i]) lv[i]=1;
if (l[i]>0 && l[i]<=NL) lc[l[i]-1]++;
}
displayReport(v, s, l, sv, lv, c);
int busy = busiestLane(lc);
int least = leastBusyLane(lc);
printf("\nSUMMARY:\n");
printf("Speed Violations: %d (High: %d, Low: %d)\n", tSV, hS, lS);
printf("Lane Violations: %d (Max Severity: %d, VehID: %d)\n", tLV, mS, mI!=-1?v[mI]:0);
printf("Density (Total: %d): Busy Lane %d(%d), Least Busy %d(%d)\n",
c, busy, lc[busy-1], least, lc[least-1]);
return 0;
}
