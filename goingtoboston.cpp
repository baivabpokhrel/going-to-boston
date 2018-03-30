//============================================================================
// Name        : BPokhrel1.cpp
// Author      : Baivab Pokhrel
// Version     :
// Copyright   : Your copyright notice
// Description : Going to Boston
//============================================================================

#include <iostream>
#include<cstdlib>
#include<ctime>
#define AUTO_BET


using namespace std;


int check1(int a,int b,int c)
{
	if(a>=b && a>=c) return (a);
	else if(b>=a && b>=c) return (b);
	else if (c>=a &&c>=b) return (c);
	else return 0;
}

int check2(int a,int b)
{
	if(a>=b) {return (a);}
	else if(b>=a) {return (b);}
	else return 0;
}

int main()
{
	int hamount=1000,camount=1000,h1,h2,h3,c1,c2,c3;//assignment of beginning amounts and the numbers in dice
    int roundnumber=1;//to indicate the round number
	int betamount;//to initialize the bet amount
    srand (time(NULL));



	while(hamount>0 && hamount<2000)/*using this condition because the game should continue,
	                                  until either human or computer have amount between 0 and 2000
		                           */
	{


		cout<<"\n[Round "<<roundnumber<<"] ";//to indicate the round number
		roundnumber=roundnumber+1;

		int hscore=0,cscore=0;//to record the total of the dice
		  h1=rand()%6+1;
		  h2=rand()%6+1;
		  h3=rand()%6+1;
		  c1=rand()%6+1;
		  c2=rand()%6+1;
		  c3=rand()%6+1;
		  cout<<"You Rolled ("<<h1<<','<<h2<<','<<"?), ";
		  cout<<"Machine rolled ("<<c1<<','<<c2<<','<<"?)\n";


         #ifndef AUTO_BET // if auto bet is not defined it will go through this path
		  {
			  cout<<"How much are you going to bet: \n";
			           cin>>betamount;
			 		  while(betamount>10 || betamount<=0 )// if bet amount is not in the given range prompt it again
			 		     {
			 			  cout<<"- your bet must between $1 and $10, type again: \n";
			 			  cin>>betamount;
			 		     }

           }

         #else// if auto bet is defined it will take this path
		  {
			            if (h1==h2 && c1!=c2)
			  			{
			  				betamount =10;
			  				cout<<"bet placed is: $ "<<betamount<<endl;
			  			}
			  		    else if(c1==c2 && h1!=h2)
			  		    {
			  		    	betamount=2;
			  		    	cout<<"bet placed is: $ "<<betamount<<endl;
			  		    }
			  		    else if (h1==h2 && c1==c2)
			  		    {
			  		    	betamount=5;
			  		    	cout<<"bet placed is: $ "<<betamount<<endl;
			  		    }
			  			else if (h1>=5 || h2>=5)
			  			{
			  				betamount=8;
			  				cout<<"bet placed is: $ "<<betamount<<endl;
			  			}
			  			else if(h1>=4 || h2>=4)
			  			{
			  				betamount=6;
			  				cout<<"bet placed is: $ "<<betamount<<endl;
			  			}
			  			else if(h1<4 || h2<4)
			  			{
			  				betamount=4;
			  				cout<<"bet placed is: $  "<<betamount<<endl;
			  			}
			  			else if(h1<2 || h2<2)
			  			{
			  				betamount=2;
			  				cout<<"bet placed is: $ "<<betamount<<endl;
			  			}
			  			else
			  			{
			  				betamount=5;
			  				cout<<"bet placed is: $ "<<betamount<<endl;
			  			}




		  }
          #endif

		  if((h1==h2&&h2==h3) && (c1==c2&&c2==c3))// to check if both of them got the big fish , and cancel out the effect
			  {
			    cout <<"Your had ("<<h1<<","<<h2<<","<<h3<<" )...Big Fish!!\n";
			    cout <<"Machine had ("<<c1<<","<<c2<<","<<c3<<")...Big Fish\nRound Tied";
			  }

		  else if(h1==h2 && h2==h3)//if human got the big fish
         		 {

         			  cout <<"Your had ("<<h1<<","<<h2<<","<<h3<<" )...Big Fish!!\n";
         			  cout <<"Machine had ("<<c1<<","<<c2<<","<<c3<<")\n";

         			   hamount=hamount+(betamount*50);//to add the bet amount time 50 to human
         			   camount= camount-(betamount*50);//to deduct the bet amount from computer


         			 cout<<"You won :) You have $ "<<hamount;
         			 cout<<", machine has $ "<<camount<<'\n';

         		 }
		  else if(c1==c2 && c2==c3)//if computer got big fish
          		 {
                    cout <<"Machine had ("<<c1<<","<<c2<<","<<c3<<" )...Big Fish\n";
                    cout <<"You have ("<<h1<<","<<h2<<","<<h3<<")\n";

          		  	camount=camount+betamount*50;
          		    hamount= hamount-(betamount*50);


          		  		    cout<<"You lost :( You have $ "<<hamount;
          		  		cout<<", machine has $ "<<camount<<endl;


          		 }


		  else//for all other case without big fish
		  {

            cout<<"You had ("<<h1<<','<<h2<<','<<h3<<")-> You rolled";//to display the first set of numbers for human
            h1= check1(h1,h2,h3);// to check which one is the greatest out of three for human and store that value
            /*As we are using 3 dice we can store the value of largest and re roll it
             *but we could re roll any of the two dices out of three and again find the greatest
             * and re roll any of the two dices as we already know which one is greatest
             */
            h2=rand()%6+1;//rolling other two dices after storing one
            h3=rand()%6+1;
            cout<<" ("<<h2<<","<<h3<<") and then rolled";
            h2=check2(h2,h3);//to check which one is greatest out of two for human and store that value
            h3=rand()%6+1;
            cout<<" ("<<h3<<") -> ";
            hscore=h1+h2+h3;
            cout<<"You scored "<<hscore<<endl;

            cout<< "Machine had ("<<c1<<','<<c2<<','<<c3<<") -> Machine rolled ";// to display first set of numbers for computer
            c1=check1(c1,c2,c3);// to check which one is the greatest out of three for machine and store that value
            c2=rand()%6+1;//rolling other two dices after storing one
            c3=rand()%6+1;
            cout<<" ("<<c2<<","<<c3<<") and then rolled";
            c2= check2(c2,c3);//to check which one is greatest out of two for machine and store that value
            c3=rand()%6+1;
            cout<<" ("<<c3<<") -> ";
            cscore=c1+c2+c3;
            cout<<"Machine scored "<<cscore<<"\n";



		     if(cscore>hscore)// it is the case where machine scored more than computer
		      {
		    	camount= camount+betamount*(cscore-hscore);
		    	hamount=hamount-betamount*(cscore-hscore);
		    	cout<<"You lost :( ";
                cout<<"You have $ "<<hamount;
		        cout<<", machine has $ "<<camount<<"\n";
              }
		     else if(hscore>cscore)// it is the case where humna sored more than machine
		      {
		         hamount= hamount+betamount*(hscore-cscore);
		    	 camount=camount-betamount*(hscore-cscore);
		    	 cout<<"You won :) ";
		    	 cout<<"You have $ "<<hamount;
		    	 cout<<", machine has $ "<<camount<<"\n";
		      }
		     else if (hscore==cscore)//if the sum of dices become exactly the same
		    	cout<<"Round Tied!!"<<endl;

		  }


   }
	if(camount<=0 && hamount>=2000)//it is the case when machine has less than 0 and human has more than 2000 i.e. human won
		cout<<"YOU WON THE GAME :)"<<endl;

    else if(hamount<=0 && camount>=2000)//it is the case when human has less than 0 and machine has more than 2000 i.e. machine won
    	cout<<"YOU LOST THE GAME :("<<endl;



}







