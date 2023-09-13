#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;



class Cricket_team
{
public:
    string team_name;
    bool isBatting;
    bool isBowling;
    int total_runs;
    int total_wickets;
public:
    void get_teamName(string firstOrSecond)
    {
        cout<<"What is the name of "<<firstOrSecond<<" team : ";
        cin>>this->team_name;
    }
    int get_totalRuns(int runs)
    {
        this->total_runs=runs;
        return runs;
    }
    int get_totalWickets(int wickets)
    {
        this->total_wickets=wickets;
        return wickets;
    }

};

class Cricket_match
{
public:
    int number_of_overs;
    Cricket_team t1;
    Cricket_team t2;
    int target;
public:
    void get_numberOfOvers()
    {
        cout<<"How many overs this cricket match contains : ";
        cin>>this->number_of_overs;
    }
    int returnNoOfOvers()
    {
        return this->number_of_overs;
    }
};

class Batsmen{
public:
    string team_name;
    string player_name;
    bool isBowling;
    int wickets_taken;
    int overs_thrown;
    int runs_gave;
};

class Bowler{
public:
    string team_name;
    string player_name;
    bool isBatting;
    bool isOut;
    int overs_bat;
    int runs_taken;
};

int show_overs(int number_of_overs,Cricket_team t3,Cricket_team t4,Cricket_match match);
void target_reveal(int number_of_overs,int target,Cricket_team t3,Cricket_team t4);
void show_batter_details();
void show_bowler_details();

int main()
{
    Cricket_match match;
    Cricket_team t1,t2;
    match.get_numberOfOvers();
    t1.get_teamName("first");
    t2.get_teamName("second");
    system("cls");
    srand(time(0));
    int k = (rand()%60)+1;
    if(k<=30)
    {
        cout<<t1.team_name<<" won the toss and chose batting.";
        t1.isBatting=true;
        t2.isBatting=false;
        t1.isBowling=false;
        t2.isBowling=true;
    }
    else
    {
        cout<<t2.team_name<<" won the toss and chose batting.";
        t2.isBatting=true;
        t1.isBatting=false;
        t2.isBowling=false;
        t1.isBowling=true;

    }

    cout<<endl;
    int target_match1,target_match2;
    if(t1.isBatting==true&&t2.isBatting==false)
    {
        target_match1=show_overs(match.returnNoOfOvers(),t1,t2,match);
        target_reveal(match.returnNoOfOvers(),target_match1,t1,t2);
        match.target=target_match1;
        t1.isBatting=false;
        t2.isBatting=true;
        t1.isBowling=true;
        t2.isBowling=false;
    }
    else if(t2.isBatting==true&&t1.isBatting==false)
    {
        target_match1=show_overs(match.returnNoOfOvers(),t2,t1,match);
        target_reveal(match.returnNoOfOvers(),target_match1,t2,t1);
        match.target=target_match1;
        t2.isBatting=false;
        t1.isBatting=true;
        t2.isBowling=true;
        t1.isBowling=false;
    }
    cout<<"target match 1 is : "<<target_match1<<endl;
    // system("cls");
    cout<<endl;   //
    cout<<endl;  //
    cout<<"Target is "<<match.target<<" runs in "<<match.returnNoOfOvers()<<" overs."<<endl;
    if(t1.isBatting==true&&t2.isBatting==false)
    {
        cout<<endl<<t1.team_name<<" is batting."<<endl;
        target_match2=show_overs(match.returnNoOfOvers(),t1,t2,match);
        if(target_match1>target_match2){
            cout<<t2.team_name<<" won the match"<<endl;
        }else if(target_match1==target_match2){
            cout<<"The match become draw."<<endl;
        }else{
            cout<<t1.team_name<<" won the match"<<endl;
        }
    }
    else if(t2.isBatting==true&&t1.isBatting==false)
    {
        cout<<endl<<t2.team_name<<" is batting."<<endl;
        target_match2=show_overs(match.returnNoOfOvers(),t2,t1,match);
        if(target_match1>target_match2){
            cout<<t1.team_name<<" won the match"<<endl;
        }else if(target_match1==target_match2){
            cout<<"The match become draw."<<endl;
        }else{
            cout<<t2.team_name<<" won the match"<<endl;
        }
    }


    return 0;
}

int show_overs(int number_of_overs,Cricket_team t3,Cricket_team t4,Cricket_match match)
{
    int total_runs=0;
    int total_wickets=0;
    for(int i=1; i<=number_of_overs; i++)
    {
        cout<<i<<" over : "<<endl;

        for(int j=1; j<=6; j++)
        {
            int k=(rand()%100)+1;
            int sum_runs_per_ball=0;
            int sum_wickets_per_ball=0;
            if(k<=35)
            {
                cout<<"1 ";
                sum_runs_per_ball+=1;
            }
            else if(k>35 && k<=55)
            {
                cout<<"0 ";
            }
            else if(k>55 && k<=70)
            {
                cout<<"wde ";
                sum_runs_per_ball+=1;
                j--;
            }
            else if(k>70 && k<=80)
            {
                cout<<"6 ";
                sum_runs_per_ball+=6;
            }
            else if(k>80 && k<=90)
            {
                cout<<"4 ";
                sum_runs_per_ball+=4;
            }
            else
            {
                cout<<"wkt ";
                sum_wickets_per_ball++;
            }
            total_runs+=sum_runs_per_ball;
            total_wickets+=sum_wickets_per_ball;
        }
        t3.total_runs=total_runs;
        t4.total_wickets=total_wickets;
        cout<<endl<<"total runs taken by "<<t3.team_name<<" at the end of "<<i<<" over : "<<t3.total_runs<<endl;
        cout<<endl<<"total wickets taken by "<<t4.team_name<<" at the end of "<<i<<" over : "<<t4.total_wickets<<endl;

        if(total_wickets==10)
        {
            break;
        }

    }
    return t3.total_runs+1;
}

void target_reveal(int number_of_overs,int target,Cricket_team t3,Cricket_team t4)
{
    cout<<endl<<"Target : "<<t4.team_name<<" needs "<<target<<" in "<<number_of_overs<<" overs to win."<<endl;

}
