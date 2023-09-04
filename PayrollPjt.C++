 #include <iostream>
     #include <fstream>     
      using namespace std;
      
      int  readalldata( long int[ ], int[ ], float[ ], const int ); 
      void findovertimehours( int[ ], int[ ], int );
      void findovertimepay( int[ ], float[ ], float[ ], int ); 
      void findregularhours( int[ ], int[ ], int );
      void findregularpay( int[ ], float[ ], float[ ], int );
     void findgrosspay( float[ ], float[ ], float[ ], int );
     void findtaxrate( float[ ], float[ ], int );
     void findtaxamount( float[ ], float[ ], float[ ], int );
     void findnetpay( float[ ], float[ ], float[ ], int );
     void printalldata( long int[ ], int[ ], float[ ], float[ ], float[ ], float[ ],float[ ], int );
     
     void main( ){
           const int MAXSIZE = 100;      
     
        
           int n;
           long int id[ MAXSIZE ];    
           int hoursworked[ MAXSIZE ], overtimehours[ MAXSIZE ];
           int regularhours[ MAXSIZE ];
           float hourlyrate[ MAXSIZE ], regularpay[ MAXSIZE ]; 
           float overtimepay[ MAXSIZE ], grosspay[ MAXSIZE ];
           float taxrate[ MAXSIZE ],  taxamount[ MAXSIZE ],netpay[ MAXSIZE] ;
     
               
           n = readalldata( id, hoursworked, hourlyrate, MAXSIZE ); 
           findovertimehours( hoursworked, overtimehours, n );
           findovertimepay( overtimehours, hourlyrate, overtimepay, n );
           findregularhours( hoursworked, regularhours, n  );
           findregularpay( regularhours, regularpay, hourlyrate, n );
           findgrosspay( regularpay, overtimepay, grosspay, n ); 
           findtaxrate( grosspay, taxrate, n );
           findtaxamount( grosspay, taxamount, taxrate, n );
           findnetpay( grosspay, netpay, taxamount, n );
           printalldata( id, hoursworked, hourlyrate, overtimepay,
                              grosspay, taxamount, netpay, n );
     }
     int readalldata( long int id[ ], int hoursworked[ ], float hourlyrate[ ], int n ){
           ifstream fin( "payroll.in" );
           n = 0;
     
           while( fin >> id[ n ] >> hoursworked[ n ] >> hourlyrate[ n ] )  n++;
     
           fin.close( );
           return n;
     }
     
     void findovertimehours( int hoursworked[ ], int overtimehours[ ], int n ){
           for( int i = 0 ; i < n ; i++){
                if( hoursworked[ i ] > 40 ) overtimehours[ i ] = hoursworked[ i ] - 40;
                else overtimehours[ i ] = 0;
           }
     }
     
     void findovertimepay( int overtimehours[ ], float hourlyrate[ ], 
           float overtimepay[ ], int n ){
           for( int i = 0 ; i < n ; i++){
                overtimepay[ i ] = overtimehours[ i ] * hourlyrate[ i ] * 1.5;
           }
     }
     
     void findregularhours( int hoursworked[ ], int regularhours[ ], int n ){
           for( int i = 0 ; i < n ; i++){
                if( hoursworked[ i ] > 40 ) regularhours[ i ] = 40;
                else   regularhours[ i ] = hoursworked[ i ];
           }
     }
     
     void findregularpay( int regularhours[ ], float regularpay[ ], 
                                       float hourlyrate[ ], int n ){
          for( int i = 0 ; i < n ; i++ ){
                regularpay[ i ] = regularhours[ i ] * hourlyrate[ i ];
          }
     }
      void findgrosspay( float regularpay[ ], float overtimepay[ ],
                                    float grosspay[ ],int n ){
                for( int i = 0 ; i < n ; i++){
                     grosspay[ i ] = regularpay[ i ] + overtimepay[ i ];   
                }
           }
    
           void findtaxrate( float grosspay[ ], float taxrate[ ], int n ){
               for( int i = 0 ; i < n ; i++){
                    if( grosspay[ i ] > 4000.00 ) taxrate[ i ] = 0.40;
                     else if(grosspay[ i ] > 3000.00 ) taxrate[ i ] = 0.30;
                    else if(grosspay[ i ] > 1000.00 ) taxrate[ i ] = 0.20;
                     else taxrate[ i ] = 0.10;
               }
           }
    
          void findtaxamount( float grosspay[ ], float taxamount[ ], 
                                         float taxrate[ ], int n ){
                for( int i = 0 ; i < n ; i++){
                     taxamount[ i ] = grosspay[ i ] * taxrate[ i ];
          }
    }
    
    void findnetpay( float grosspay[ ], float netpay[ ], float taxamount[ ], int n){
         for( int i = 0 ; i < n ; i++){
              netpay[ i ] = grosspay[ i ] - taxamount[ i ];
         }
    }
    
    void printalldata( long int id[ ], int hoursworked[ ], float hourlyrate[ ],
                               float overtimepay[ ], float grosspay[ ], float  taxamount[ ], 
                               float netpay[ ], int n ){
        cout << "EMP ID" << "\t" << "HOURS" << "\t" << "RATE " << "\t " 
               << "OVERPAY " << "\t" << "GROSSPAY" << "\t" << "TAX  "<< "\t" 
               << "  NETPAY  " << endl;
       for( int i = 0 ; i < n; i++){
            cout << " " << id[ i ] << "\t " << hoursworked[ i ] << "\t"<<hourlyrate[ i ] 
                      << "\t " << overtimepay[ i ] << "\t\t"  << grosspay[ i ] << "\t\t" 
                      << taxamount[ i ] << "\t " << netpay[ i ] << endl;
         }
    }
   