#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Declaring main functions
void login();
void Secretary_fun();
void Main_coach_fun();
void Physical_fitness_coach_fun();
void Assistant_coach_fun();

//Declaring sub functions
void payment();
void registration();

void genReporting();
void trackFitness();

//structure to store player data in system
struct RegiSystem
{
int playerid;
char gender;
char fname[50];
char lname[50];
}Prosp_plyr[20];

struct payment
{
char firstname[50];
char lastname[50];
int id;
float amtpaid;
}player[50];

struct progress
{
char firstname[50];
char lastname[50];
int id;
char notes[500];
int won;
 59 int rank;
 60 }plyr[50];
 61 
 62 struct fitness
 63 {
 64 char firstname[50];
 65 char lastname[50];
 66 int id;
 67 char activity[200];
 68 char healthconds[500];
 69 }ply[50];
 70 
 71 //main
 72 
 73 int main()
 74 {
 75 login();
 76 return 0;
 77 }
 78 
 79 //login function
 80 void login()
 81 {
 82 char UserName[50];
 83 char PassWord[50];
 84 char Usect[]="PLewis";
 85 char Psect[]="sectGPTTC";
 86 char Umain[]="MWilson";
 87 char Pmain[]="mCoach";
 88 char Ufit[]="MBrown";
 89 char Pfit[]="FitCoach";
 90 char Uassist[]="MWilliams";
 91 char Passist[]="AsstCoach";
 92 
 93 system("cls");
 94 printf("**********GREATER PORTMORE TABLE TENNIS 
CLUB*************\n\n\n");
 95 printf("Please Enter Username: ");
 96 scanf("%s", UserName);
 97 printf("Please Enter Password: ");
 98 
 99 scanf("%s", PassWord);
100 //if...else statement to test if the input is the correct username.
101 
102 
103 
104 if (strcmp(Usect,UserName)==0&&strcmp(Psect,PassWord)==0)
105 {
106 system("cls");
107 
108 printf("*********************Welcome Miss Lewis!
****************\n\n\n");
109 Secretary_fun();
110 
111 
112 }
113 if (strcmp(Umain,UserName)==0&&strcmp(Pmain,PassWord)==0){
114 system("cls");
115 printf("*******************Welcome Mr. Wilson!!
***************\n\n");
116 Main_coach_fun();
117 }
118 if(strcmp(Ufit,UserName)==0&&strcmp(Pfit,PassWord)==0){
119 system("cls");
120 printf("********************Welcome Mr. Brown!!
***************\n\n");
121 Physical_fitness_coach_fun();
122 }
123 if (strcmp(Uassist,UserName)==0&&strcmp(Passist,PassWord)==0){
124 system("cls");
125 printf("*********************Welcome Miss Williams!!
************\n\n");
126 Assistant_coach_fun();
127 } else{
128 printf("Username or Password incorrect please try again\n\n");
129 system("pause");
130 system("cls");
131 login();
132 
133 }
134 
135 
136 }
137 
138 
139 //main functions
140 void Secretary_fun()
141 {
142 int chc;
143 
144 
145 printf("*********Secretary Section*********\n\n");
146 printf("1. Registration.\n");
147 printf("2. Payments.\n");
148 printf("3. Print reports\n");
149 printf("4. logout\n");
150 printf("Choose a number ");
151 scanf("%d", &chc);
152 switch(chc)
153 {
154 case 1:
155 registration();
156 break;
157 case 2:
158 payment();
159 break;
160 case 3:
161 genReporting();
162 break;
163 case 4:
164 login();
165 break;
166 
167 default:
168 printf("Incorrect option please try again :)\n ");
169 system("pause");
170 system("cls");
171 Secretary_fun();
172 
173 
174 }
175 
176 }
177 
178 void Main_coach_fun()
179 {
180 int ch, x, num,i;
181 char notes[500];
182 FILE*ptr;
183 printf("******Main Coach Section*********\n\n");
184 printf("1. Begin input of player information\n");
185 printf("2. Print Report\n");
186 printf("3. Logout\n");
187 scanf("%d",&ch);
188 
189 system("cls");
190 
191 switch (ch)
192 {
193 case 1:
194 ptr=fopen("progress.txt","w");
195 printf("Enter the number of records you want to enter\n");
196 scanf("%d",&num);
197 for(x=0;x<num;x++)
198 {
199 
200 printf("Enter player ID\n");
201 scanf("%d",&plyr[x].id);
202 printf("Enter player first name\n");
203 scanf("%s",plyr[x].firstname);
204 printf("Enter player Last Name\n");
205 scanf("%s",plyr[x].lastname);
206 printf("Enter number of Tournaments won\n");
207 scanf("%d",&plyr[x].won);
208 printf("Enter player's rank\n");
209 scanf("%d",&plyr[x].rank);
210 printf("Enter notes on Player\n");
211 fflush(stdin);
212 gets(notes);
213 strcpy(plyr[x].notes,notes);
214 
215 }
216 for(i=0;i<num;i++)
217 {
218 fprintf(ptr,"%d %s %s %d %d\n 
%s\n\n",plyr[i].id,plyr[i].firstname,plyr[i].lastname,plyr[i].won,plyr[i].rank
,plyr[i].notes);
219 }
220 
221 fclose(ptr);
222 system("pause");
223 system("cls");
224 Main_coach_fun();
225 break;
226 case 2:
227 genReporting();
228 case 3:
229 login();
230 default:
231 printf("Incorrect option please try again\n\n");
232 system("pause");
233 system("cls");
234 Main_coach_fun();
235 }
236 
237 
238 
239 }
240 
241 void Physical_fitness_coach_fun()
242 {//physical fitness programs;keeping track of physical activities by 
players
243 
244 int chc;
245 printf("***************Physical Fitness Coach 
Section*******************\n\n");
246 printf("1. Enter activity of player\n");
247 printf("2. Generate report.\n");
248 printf("3. Logout\n");
249 printf("Choice: ");
250 scanf("%d",&chc);
251 
252 switch(chc)
253 {
254 case 1:
255 trackFitness();
256 break;
257 case 2:
258 genReporting();
259 break;
260 case 3:
261 system("cls");
262 system("pause");
263 login();
264 default:
265 printf("Incorrect option please try again\n");
266 system("pause");
267 system("cls");
268 Physical_fitness_coach_fun();
269 }
270 
271 
272 
273 }
274 
275 void Assistant_coach_fun()
276 {
277 
278 int chc;
279 printf("***********Assistant Coach Section*********\n\n");
280 printf("1. Print reports\n");
281 printf("2. logout\n");
282 printf("Choice: ");
283 
284 scanf("%d",&chc);
285 switch (chc)
286 {
287 case 1:
288 genReporting();
289 break;
290 case 2:
291 login();
292 
293 break;
294 default:
295 printf("Incorrect Option Please try again\n");
296 system("pause");
297 system("cls");
298 Assistant_coach_fun();
299 
300 
301 }
302 
303 
304 }
305 
306 /////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////
307 
308 //sub functions down here
309 
310 
311 
312 void registration()
313 {
314 system("cls");
315 
316 FILE *fp;
317 fp = fopen("listing.txt", "w+");
318 int x;
319 int i;
320 printf("\n*********************Registering 
section.*******************\n\n");
321 printf("\nHow many players to add? ");
322 fflush(stdin);
323 scanf("%d", &i);
324 for (x=0;x<i;x++)
325 {
326 
327 
328 printf("\n\nEnter Player First Name ");
329 scanf("%s",Prosp_plyr[x].fname);
330 printf("Enter Player Last Name ");
331 scanf("%s",Prosp_plyr[x].lname);
332 printf("What is the player id no.? ");
333 scanf("%d", &Prosp_plyr[x].playerid);
334 printf("\nWhat is the gender? ");
335 fflush(stdin);
336 scanf("%c", &Prosp_plyr[x].gender);
337 
338 
339 
340 
341 }
342 
343 for (x=0;x<i;x++)
344 {
345 fprintf(fp, "%d %c %s %s\n",Prosp_plyr[x].playerid, 
Prosp_plyr[x].gender, Prosp_plyr[x].fname, Prosp_plyr[x].lname);
346 
347 }
348 fclose(fp);
349 system("pause");
350 system("cls");
351 Secretary_fun();
352 
353 }
354 
355 
356 
357 
358 
359 void genReporting()
360 {
361 system("cls");
362 FILE*fp;
363 FILE*filpay;
364 FILE*fitPr;
365 FILE*ptr;
366 int choice,x,i;
367 char notes[500];
368 char activity[200];
369 char healthconds[200];
370 
371 x=0;
372 printf("********Reporting section********\n\n");
373 printf("1. Registration report\n");
374 printf("2. Payment report\n");
375 printf("3. Fitness report\n");
376 printf("4. Progress report\n");
377 scanf("%d",&choice);
378 
379 switch (choice)
380 {
381 
382 case 1:
383 
384 fp=fopen("listing.txt","r");
385 
386 
387 fscanf(fp,"%d %c %s 
%s",&Prosp_plyr[x].playerid,&Prosp_plyr[x].gender,Prosp_plyr[x].fname,Prosp_pl
yr[x].lname);
388 while(!feof(fp))
389 {
390 x++;
391 fscanf(fp,"%d %c %s 
%s",&Prosp_plyr[x].playerid,&Prosp_plyr[x].gender,Prosp_plyr[x].fname,Prosp_pl
yr[x].lname);
392 
393 }
394 
395 
396 system("cls");
397 printf("***************Registration Report**********\n\n");
398 printf("ID number Gender First Name\t Last Name\n\n");
399 for(i=0;i<x;i++)
400 {
401 printf("%d \t %c\t %s \t %s 
\n",Prosp_plyr[i].playerid,Prosp_plyr[i].gender,Prosp_plyr[i].fname,Prosp_plyr
[i].lname);
402 }
403 fclose(fp);
404 system("pause");
405 system("cls");
406 login();
407 
408 break;
409 
410 case 2:
411 
412 filpay=fopen("payment.txt","r");
413 fscanf(filpay,"%d %s %s 
%f",&player[x].id,player[x].firstname,player[x].lastname,&player[x].amtpaid);
414 
415 while(!feof(filpay))
416 {
417 
418 x++;
419 fscanf(filpay,"%d %s %s 
%f",&player[x].id,player[x].firstname,player[x].lastname,&player[x].amtpaid);
420 }
421 system("cls");
422 printf("***********Payment Report********\n\n");
423 printf("ID number\t First Name\t Last Name\t Amount Paid\n");
424 for(i=0;i<x;i++)
425 {
426 printf("%d\t\t %s\t\t%s\t 
%f\n",player[i].id,player[i].firstname,player[i].lastname,player[i].amtpaid);
427 }
428 system("pause");
429 system("cls");
430 login();
431 break;
432 case 3:
433 fitPr=fopen("fitness.txt","r");
434 fscanf(fitPr,"%d%s
%s",&ply[x].id,ply[x].firstname,ply[x].lastname);
435 
436 fgets(activity,200,fitPr);
437 
438 fgets(healthconds,200,fitPr);
439 strcpy(ply[x].activity,activity);
440 strcpy(ply[x].healthconds,healthconds);
441 while(!feof(fitPr)){
442 
443 x++;
444 
445 fscanf(fitPr,"%d%s
%s",&ply[x].id,ply[x].firstname,ply[x].lastname);
446 fgets(activity,200,fitPr);
447 
448 fgets(healthconds,200,fitPr);
449 strcpy(ply[x].activity,activity);
450 strcpy(ply[x].healthconds,healthconds);
451 
452 
453 }
454 system("cls");
455 printf("*****FITNESS REPORT********\n\n");
456 printf("ID number First Name Last Name\n\n ");
457 for(i=0;i<x;i++){
458 printf("%d %s 
%s\n",ply[i].id,ply[i].firstname,ply[i].lastname);
459 
460 
461 
462 printf("Physical Activity: %s\n",ply[i].activity);
463 
464 printf("Health Conditions: %s\n",ply[i].healthconds);
465 }
466 fclose(fitPr);
467 system("pause");
468 system("cls");
469 login();
470 break;
471 case 4:
472 system("cls");
473 printf("ID number First Name\t Last Name\t Tournaments Won\t 
Rank\n\n");
474 ptr=fopen("progress.txt","r");
475 fscanf(ptr,"%d %s %s %d %d 
",&plyr[x].id,plyr[x].firstname,plyr[x].lastname,&plyr[x].won,&plyr[x].rank);
476 fgets(notes,500,ptr);
477 strcpy(plyr[x].notes,notes);
478 while(!feof(ptr))
479 {
480 
481 
482 
483 x++;
484 fscanf(ptr,"%d %s %s %d %d",&plyr[x].id,plyr[x].firstname,plyr[x].lastname,&plyr[x].won,&plyr[x].rank);
485 fgets(notes,500,ptr);
486 strcpy(plyr[x].notes,notes);
487 
488 }
489 
490 
491 
492 for(i=0;i<x;i++)
493 {
494 printf("%d \t %s\t %s\t %d\t\t\t %d\n\n Notes: %s\n\n 
",plyr[i].id,plyr[i].firstname,plyr[i].lastname,plyr[i].won,plyr[i].rank,plyr[
i].notes);
495 }
496 fclose(ptr);
497 system("pause");
498 system("cls");
499 login();
500 break;
501 default:
502 printf("Incorrect option please try again\n\n");
503 system("pause");
504 system("cls");
505 genReporting();
506 break;
507 }
508 
509 
510 }
511 
512 void trackFitness()
513 {
514 system("cls");
515 int num,x,i;
516 char activity[200];
517 char healthconds[200];
518 FILE *fitPR;
519 fitPR = fopen("fitness.txt", "w");
520 printf("*********Tracking Fitness************\n\n");
521 printf("Enter the number of records you want to enter\n");
522 scanf("%d",&num);
523 for(x=0;x<num;x++){
524 
525 printf("Enter the Player ID. ");
526 scanf("%d", &ply[x].id);
527 printf("First Name: ");
528 scanf("%s",ply[x].firstname);
529 printf("Last Name: ");
530 scanf("%s",ply[x].lastname);
531 printf("Enter the activity made by player.\n");
532 fflush(stdin);
533 gets(activity);
534 printf("Enter any serious health conditions\n");
535 fflush(stdin);
536 gets(healthconds);
537 strcpy(ply[x].activity,activity);
538 strcpy(ply[x].healthconds,healthconds);
539 }
540 
541 for(i=0;i<num;i++){
542 
543 fprintf(fitPR,"%d %s %s %s\n 
%s\n",ply[i].id,ply[i].firstname,ply[i].lastname,ply[i].activity,ply[i].health
conds);
544 
545 }
546 
547 fclose(fitPR);
548 
549 
550 
551 
552 system("pause");
553 system("cls");
554 Physical_fitness_coach_fun();
555 }
556 
557 //payment function
558 void payment()
559 {
560 system("cls");
561 int num,x,i;
562 FILE*filpay;
563 filpay=fopen("payment.txt","w");
564 printf("********Payments********\n\n");
565 printf("Enter the amount of records to add\n\n");
566 fflush(stdin);
567 scanf("%d",&num);
568 for(x=0;x<num;x++){
569 printf("First name: ");
570 fflush(stdin);
571 scanf("%s",player[x].firstname);
572 printf("Last name: ");
573 fflush(stdin);
574 scanf("%s",player[x].lastname);
575 printf ("\nID#: ");
576 scanf("%d",&player[x].id);
577 printf("Amount Paid: $");
578 scanf("%f",&player[x].amtpaid);
579 
580 
581 
582 
583 
584 
585 }
586 for(i=0;i<num;i++){
587 fprintf(filpay,"%d %s %s 
%f\n",player[i].id,player[i].firstname,player[i].lastname,player[i].amtpaid);
588 }
589 
590 fclose(filpay);
591 system("cls");
592 Secretary_fun();
593 
594 }
595
