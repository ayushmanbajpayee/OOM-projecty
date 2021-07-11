#include<bits/stdc++.h>
using namespace std;
#include "publisher.h"
#include "subscriber.h"
#include "plateform.h"
int main(){
    Plateform p;
    int no_of_publishers;
    cout<<"Enter number of publishers:"<<endl;
    cin>>no_of_publishers;
    for(int i=0;i<no_of_publishers;i++){
        string message;
        cout<<"Enter message to each publisher:"<<i<<endl;
        cin>>message;
        p.publisher_list[i].set_message(message);
        p.publisher_list[i].status=1;
    }
    int no_of_subscribers;
    cout<<"Enter number of subscribers:";
    cin>>no_of_subscribers;
    for(int i=0;i<no_of_subscribers;i++){
        p.subscriber_list[i].status=1;
        int Id;
        cout<<"Enter the id of publisher to subscribe:"<<i<<endl;
        cin>>Id;
        while(Id>=no_of_publishers){
            cout<<"Invalid"<<endl;
            cin>>Id;
        }
        p.subscriber_list[i].set_publisher(p.publisher_list[Id]);
        p.subscriber_list[i].Publisherid=Id;
    }
    cout<<"List of subscribers and publishers:"<<endl;
    p.published();
    cout<<"Publishing all messages:"<<endl;
    p.dessiminate();

}