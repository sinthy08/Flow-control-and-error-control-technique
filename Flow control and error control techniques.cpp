#include<bits/stdc++.h>
#include <time.h>
#include<windows.h>

using namespace std;


void sleep(unsigned milliseconds)
{
    Sleep (milliseconds);
}

int i,j,k,l;
    int temp[500],n, f[500], cpy[500];
    int data_s[500];
    int tf[500];
    //Get Frame
    int fs=50;
    int g[17]={ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 };
    int rs=16;
    int crc[16];
    char ch;
    int rrem[16];
    int flag=0;
    int data[300];
void Crc_Error ();
int dat=300;
void wait ( int seconds )
{
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC ;
  while (clock() < endwait) {}
}

int main()
{
      cout<<"Source Communicating With Destination";
  for (n=3; n>0; n--)
  {
    cout<<". ";
    wait (3);

  }
        cout<<endl;
        wait(3);
        cout<<"Sending Frame seq no."<<" 0\n";
        Crc_Error ();
        flag=0;
        wait(2);
        cout<<"Sending Frame seq no."<<" 1\n";
        wait(3);
        Crc_Error ();
        flag=0;
        wait(2);
        cout<<"Sending Frame seq no."<<" 0\n";
        wait(3);
        Crc_Error ();
        cout<<"Source sending EOT ";
        for (n=3; n>0; n--)
          {
            cout<<"!";
            wait(1);
          }
        cout<<"\n\nDisconnecting Connection With Destination";
      for (n=3; n>0; n--)
      {
        cout<<". ";
        wait (3);

      }
    return 0;
}


void Crc_Error ()
{

  //  cout<<"\nFrame size:";
   // cin>>fs;
   for(i=0;i<fs;i++)
    {
        f[i]=rand()%2 ;
    }

    //Get Generator

    cout<<"\n Source Side:";
    cout<<"\n Frame: ";
    for(i=0;i<fs;i++)
    {
        cout<<f[i];
    }
    cout<<"\n Predetermined Divisor :";
    for(i=0;i<17;i++)
    {
        cout<<g[i];
    }

    //Append 0's
    cout<<"\n Number of 0's to be appended: "<<rs;
    for (i=fs;i<fs+16+1;i++)
    {
       // cout<<"fs+16 "<<fs+16<<endl;
        f[i]=0;
    }


    for(i=0;i<fs+16;i++)
    {
        temp[i]=f[i];
    }

    cout<<"\n Frame after appending 0's :";
    for(i=0; i<fs+16;i++)
    {
        cout<<temp[i];
    }

    //Division crc
    for(i=0;i<fs;i++)
    {
        j=0;
        k=i;
        ///check whether it is divisible or not
        if (temp[k]>=g[j])
        {
            for(j=0,k=i;j<17;j++,k++)
            {
                if((temp[k]==1 && g[j]==1) || (temp[k]==0 && g[j]==0))
                {
                    temp[k]=0;
                }
                else
                {
                    temp[k]=1;
                }
            }
        }
    }

    //CRC
    for(i=0,j=fs;i<rs;i++,j++)
    {
        crc[i]=temp[j];
    }

    cout<<"\n CRC bits: ";
    for(i=0;i<rs;i++)
    {
        cout<<crc[i];
    }
////////////////////////////////////////////////////////////////////////////////////
    cout<<"\n Transmitted Frame: ";

    for(i=0;i<fs;i++)
    {
        tf[i]=f[i];
    }
    for(i=fs,j=0;i<fs+rs;i++,j++)
    {
        tf[i]=crc[j];
    }
    for(i=0;i<fs+rs;i++)
    {
        cout<<tf[i];
    }

for(i=0;i<fs+rs;i++)
    {
        cpy[i]=tf[i];
    }


    cout<<"\nWant error??? (y/n): ";
    cin>>ch;

    if(ch=='y')
    {
        cout<<"\nEnter the position where error is to be inserted : ";
        cin>>j;
        if(tf[j-1]==1)
           tf[j-1]=0;
        else tf[j-1]=1;

    }

    cout<<"\n Receiver side : ";
    cout<<"\n Received Frame: ";

    for(i=0;i<fs+rs;i++)
    {
        cout<<tf[i];
    }


 for(i=0;i<fs+rs;i++)
    {
        temp[i]=tf[i];
    }

    //Division
    for(i=0;i<fs;i++)
    {
        j=0;
        k=i;
        if (temp[k]>=g[j])
        {
            for(j=0,k=i;j<17;j++,k++)
            {
                if((temp[k]==1 && g[j]==1) || (temp[k]==0 && g[j]==0))
                {
                    temp[k]=0;
                }
                else
                {
                    temp[k]=1;
                }
            }
        }
    }

    cout<<"\n Reminder: ";
    for (i=fs,j=0;i<fs+rs;i++,j++)
    {
        rrem[j]= temp[i];
    }
    for(i=0;i<rs;i++)
    {
        cout<<rrem[i];
    }

    for(i=0;i<rs;i++)
    {
        if(rrem[i]!=0)
        {
            flag=1;
        }
    }

    if(flag==0)
    {
        cout<<"\n Remainder is 0 So Data transfered correctly\n";
        cout<<"\n ACK SEND!!!\n";
    }
    else
    {
    cout<<"\nRemainder is Not 0 So Data Contains Error";
    wait(5);
    cout<<"\n Sending NAK.......";
    cout<<"\n\nsource again sending the frame...";
    sleep(1000);
    cout<<"\n Receiver side : ";
    cout<<"\n Received Frame: ";

    for(i=0;i<fs+rs;i++)
    {
        cout<<cpy[i];
    }


 for(i=0;i<fs+rs;i++)
    {
        temp[i]=cpy[i];
    }

    //Division
    for(i=0;i<fs;i++)
    {
        j=0;
        k=i;
        if (temp[k]>=g[j])
        {
            for(j=0,k=i;j<17;j++,k++)
            {
                if((temp[k]==1 && g[j]==1) || (temp[k]==0 && g[j]==0))
                {
                    temp[k]=0;
                }
                else
                {
                    temp[k]=1;
                }
            }
        }
    }

    cout<<"\n Reminder: ";
    for (i=fs,j=0;i<fs+rs;i++,j++)
    {
        rrem[j]= temp[i];
    }
    for(i=0;i<rs;i++)
    {
        cout<<rrem[i];
    }

        cout<<"\n Remainder is 0 So Data transfered correctly\n";
        cout<<"\n ACK SEND!!!\n";
    }

}
