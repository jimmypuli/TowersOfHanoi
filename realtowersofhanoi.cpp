//Jimmy Puli
#include<iostream>
#include<vector>
using namespace std;

int main(){
  int disks, from, move = 0, candidate;//disk tells us how many disks there are 
  //from is the tower the disk is being moved from
  //move keeps track the the number of moves
  //candidate is the the disk we are moving 
  cout << "Enter the number of disks to move: ";
  cin >> disks; //now we know how many disks we dealing wit

  vector<int>tower[3];//array of vectors to hold the rings 

  for(int i = disks + 1; i >= 1; i--){
    tower[0].push_back(i);//makes vector 0 hold all the rings
  }
  tower[1].push_back(disks+1);
  tower[2].push_back(disks+1);
  //there is an extra disk(disk + 1) at the bottom so we don't have to check everytime to see if the vector is empty 
  candidate = 1; //the first disk being moved -- at the top of tw.0
  from = 0; //from the first tower (0) -- french counted 
  
  while(tower[1].size() < disks + 1){//while tower 1 doesn't have all the disks 
    if(disks%2 == 0){//if disk number is even 
    static int to = 2;//static is used for "to" so "to" is initialized once and only once -- this keeps to from resetting everytime it is declared
    cout << "Move number " << ++move << ": transfer disk " << candidate << " from tower " << from << " to tower " << to << endl;//prints first move and so on according to the values of from, to, candidate, and move   
    tower[to].push_back(tower[from].back());//moves disk 1 from  tower 0 to tower 2 or in general the disks are moved from the from tower to the to tower 
    tower[from].pop_back();//removes disk from the tower it came from 
    
    if(tower[(to+1)%3].back() < tower[(to+2)%3].back())//checks to see which tower has the smallest disk that isn't the "to" tower
    from = (to + 1)%3;//%3 is used to ensure the towers stay in between the 0 - 2 range in case the addition makes it more than 2
    else 
    from = (to + 2)%3; //the second option is considered here it becomes from if the disk at this location is the smallest 
    
    candidate = tower[from].back();//candidate is the disk we moving 
    //these else if statements I made because we got to go counter clockwise since the number of disks is even
    //our strategy has to be different compared to the one we used for odd disks
    //these if statements looks at the "from" variable and with that information we are able to determine which towers we need to go to starting and giving proirity to the tower that is firstly left of the "from" tower to tell us where the "to" tower is at 
    //so if we're at from 0 we need to look at towers 2 and 1 with priority at 2 since it is to the left of 0 if we go in a circle counter clockwise
    //if a disk is coming from 1 we need to look at 0 first then 2
    //if a disk is coming from 2 we need to look at 1 first then 0
    //else if is used so the "to" tower isn't changed by mistake everytime we go through the if statements 
    if(from == 0 && tower[2].back() > tower[from].back()){
    to = 2; 
    }else if(from == 0 && tower[2].back() < tower[from].back()){ 
    to = 1;
    }else if(from == 1 && tower[0].back() > tower[from].back()){
    to = 0; 
    }else if(from == 1 && tower[0].back() < tower[from].back()){
    to = 2;
    }else if(from == 2 && tower[1].back() > tower[from].back()){
    to = 1; 
    }else if(from == 2 && tower[1].back() < tower[from].back()){ 
    to = 0; 
    }
    }else{ //the following code only pertains to odd numbers of disks
    static int to = 1;//to is declared in this scope once and only once 
    cout << "Move number " << ++move << ": transfer disk " << candidate << " from tower " << from << " to tower " << to << endl; //printing is done here
    tower[to].push_back(tower[from].back());//pushes disk onto the appropriate "to" tower
    tower[from].pop_back();//removes disk from the tower it came from 
    if(tower[(to+1)%3].back() < tower[(to+2)%3].back())//looks for the next tower from which the smallest disk will come from that is not in the "to" tower 
    from = (to + 1)%3; //"to" is incremented by 1 
    //if it equals 3 or a num greater, the modulus will keep it within range(0-2)
    //otherwise if it is withing range the original num isn't changed 
    //ex: say "to" is = 2
    //2 plus 1 equals 3 which moded by 3 then equals to 0 or tower 0
    //if to is added by 2 like down below, it will equal 4 and then when moded by 3 it will equal 1
    //so towers 0 and 1 are considered - these are the towers that aren't the current "to" tower
    //in the conditional for the if statement this computation is done and the disks of the respective towers are compared (.back and <)
    else 
    from = (to + 2)%3; //else if the second option has the smallest disk, the from value is change to this tower
    candidate = tower[from].back();//candidate is the disk we movin -- good for when we are printing which disk we are moving
    if(tower[(from+1)%3].back() > tower[from].back())//tells us where we will be putting the disk from the "from" tower with attention to wether or not the "to" tower we are looking at has a disk bigger than the disk we are moving 
    to = (from + 1)%3; //if the disk in this tower has a bigger disk than the one we are moving this is the new "to" tower
    else 
    to = (from + 2)%3; //else this is the new "to" tower 
    }
  }
  return 0;
}
