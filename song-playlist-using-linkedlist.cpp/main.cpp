// 1.Add Playlist
// 2.Remove Playlist
// 3.Display Playlist
// 4.Play Next song
// 5.Exit

#include<iostream>
#include<cstring>
using namespace std;

struct song{
    string name;
    song *next;
};

class Playlist{
    private:
        song *head;
        song *tail;
        
    public:
        int c=1;
        Playlist(){
            head=tail=NULL;
        }
        
        void addSong(const string &songName){
            song *newSong=new song{songName, nullptr};
            if(head==NULL){
                head=tail=newSong;
            }
            else{
                tail->next=newSong;
                tail=newSong;
            }
        }
        
        void removeSong(const string &songName){
            if(head==NULL){
                cout<<"No song in the playlist to remove";
                return;
            }
            if(head->name == songName){
                song *temp=head;
                head=head->next;
                delete temp;
                if(head==NULL){
                    tail=nullptr;
                }
                cout<<"Song removed\n";
                return;
            }
            song *cur=head;
            while(cur->next!=NULL){
                if(cur->next->name == songName){
                    song *temp=cur->next;
                    cur->next=temp->next;
                    if(temp==tail)
                        tail=cur;
                    delete temp;
                    cout<<"Song removed\n";
                    return;
                }
                cur=cur->next;
            }
            cout<<"Song not found!\n";
        }
        
        void displayPlaylist(){
            song *temp=head;
            if(temp==NULL){
                cout<<"No songs in playlist";
                return;
            }
            else{
                while(temp!=NULL){
                    cout<<temp->name<<endl;
                    temp=temp->next;
                }
            }
        }
        
        void playNextSong(){
            song *temp=head;
            if(temp==NULL){
                cout<<"No next song\n";
                return;
            }
            for(int i=1;i<=c;i++){
                temp=temp->next;
            }
            cout<<"Next song: "<<temp->name;
            c++;
        }
};

int main(){
    int ch;
    string songName;
    Playlist list;
    do{
        cout<<"---Song Playlist---\n"
        <<"1.Add Song\n2.Remove Song\n3.Display Playlist\n4.Play Next Song\n"
        <<"5.Exit\n";
    cout<<"Enter your choice no.\n";
    cin>>ch;
    cin.ignore();
    switch(ch){
        case 1:
            cout<<"Enter song name: ";
            getline(cin,songName);
            list.addSong(songName);
            break;
        case 2:
            cout<<"Enter the song name to remove: ";
            getline(cin,songName);
            list.removeSong(songName);
            break;
        case 3:
            cout<<"Current Playlist:\n";
            list.displayPlaylist();
            break;
        case 4:
            list.playNextSong();
            break;
        case 5:
            cout<<"Thank You\n";
            break;
        default:
            cout<<"Invalid choice!";
    }
    }
    while(ch!=5);
}