  #ifndef Notesh

//#include "Notes.h"

///// Assign each note a step position  /////
//sh = sharp
//h = high
//hsh = high sharp

int C = 0;
int D = 116;
int E = 233;
int F = 349;
int G = 466;
int A = 582;
int B = 698;

int Ch = 815;
int Dh = 931;
int Eh = 1047;
int Fh = 1164;
int Gh = 1280;
int Ah = 1397;

/*
int Song[42] = {
            C, C, G, G,
            A, A, G, F,
            F, E, E, D,
            D, C-50, G-50, G-50,
            F-50, F-50, E-70, E-70,
            D-90, G-100, G-100, F-120,
            F-120, E-140, E-140, D-170, 
            C-190, C-190, G-120, G-120, 
            A-140, A-140, G-120, F-140,
            F-140, E-160, E-160, D-180,
            D-180, C-200
};
int SongKeyDelay [42] = {
            
            1000, 1000, 1000, 1000,
            1000, 1000, 3000, 1000,
            1000, 1000, 1000, 1000,
            1000, 3000,
            
            1000, 1000,
            1000, 1000, 1000, 1000,
            1000, 1000, 1000, 1000,
            1000, 1000, 1000, 3000, 
            1000, 1000, 1000, 1000,
            1000, 1000, 1000, 1000,
            1000, 1000, 1000, 1000,
            1000, 3000
  };
*/
//Jingle Bells
/*
int Song[48] = {
              E, E, E,
              E, E, E,
              E, G-50, C-50, D,
              E,
              F, F, F, F,
              F, E, E, E,
              D, D, E, D,
              G-50,
              E, E, E,
              E, E, E,
              E, G-50, C-50, D,
              E,
              F, F, F, F,
              F, E, E, E,
              D, D, E, D,
              C-50
};
int SongKeyDelay [48] = {
              500, 500, 1500,
              500, 500, 1500,
              500, 500, 500, 500,
              1500,
              500, 500, 500, 500,
              500, 500, 500, 500,
              500, 500, 500, 500,
              1500,
              500, 500, 1500,
              500, 500, 1500,
              500, 500, 500, 500,
              1500,
              500, 500, 500, 500,
              500, 500, 500, 500,
              500, 500, 500, 500,
              1500
  };
*/
//Mary Had A Little Lamb

int Song [25] = {
            E, D-20, C-50, D-20,
            E, E, E, D-20,
            D-20, D-20, E, E,
            E,
            E, D-20, C-50,
            D-20, E, E, E,
            D-20, D-20, E,
            D-20, C-50
  };
int SongKeyDelay [25] = {
            500, 500, 500, 500,
            500, 500, 1000, 500,
            500, 1000, 500, 500,
            1000,
            500, 500, 500,
            500, 500, 500, 1000,
            500, 500, 500,
            500, 1000
  };

//Twinkle Twinke Little Star
//int SongMaxKeyTime = 1000;

//Jingle Bells
//int SongMaxKeyTime = 300;

//Mary had a Little Lamb
int SongMaxKeyTime = 300;

#endif
