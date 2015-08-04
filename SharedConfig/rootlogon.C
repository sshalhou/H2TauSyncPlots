//------------------------------------------------------------------------------
//  ROOT logon macro - needs a lot of cleanup, but works for my eyes
//------------------------------------------------------------------------------
{
//#include <iomanip.h>
#include <time.h>
#include <Rtypes.h>


  gROOT->SetStyle("Plain");
//gROOT->SetStyle("Root-Style");

gStyle->SetLineScalePS(1);
//-------

gStyle->SetTitleFont(22,"x");
gStyle->SetTitleFont(22,"y");
gStyle->SetTitleOffset(.8,"x"); // 
gStyle->SetTitleOffset(1.3,"y"); // was 1.1
        gStyle->SetTitleColor(1,"x");

//	gStyle->SetTitleSize(.08,"x");		//X-axis title size

        gStyle->SetTitleSize(0.065,"y");
	gStyle->SetTitleSize(0.05,"z");









  gStyle->SetCanvasColor(kWhite);   
  gStyle->SetLineWidth(2.); //  was 3
                                                                                                          
                                                                                                          
  gStyle->SetPadTopMargin(0.1);
  gStyle->SetPadRightMargin(0.05);
  gStyle->SetPadBottomMargin(0.0); // was 0.15
  gStyle->SetPadLeftMargin(0.15);
  gStyle->SetLabelOffset(.02,"xy");



//-------

	gStyle->SetTitleX(0.182691);       //Title box x position (top left-hand corner)	
//	gStyle->SetTitleX(0.212691);       //Title box x position (top left-hand corner)	

	gStyle->SetTitleY(0.997881 ); 	//Title box y position (default value)		
	gStyle->SetTitleW(0.750771);		//Title box width as fraction of pad size
	gStyle->SetTitleH(0.091101);	//Title box height as fraction of pad size	
	gStyle->SetTitleColor(0);	//Title box fill color
	gStyle->SetTitleTextColor(1);	//Title box text color
	gStyle->SetTitleStyle(1001);	//Title box fill style!
	//TitleFont = 10*fontid + 2 (12 is normal, 22 bold 32 italic)
	gStyle->SetTitleBorderSize(0);	//Title box border thickness

	gStyle->SetLabelSize(0.05,"x");		//X-axis label size
	gStyle->SetLabelSize(0.05,"y");		
//	gStyle->SetLabelSize(0.05,"z");		

	//2x2
	gStyle->SetStatX(0.995);		//Stat box x position (top right hand corner)	
	gStyle->SetStatY(0.8); 		//Stat box y position 		
	gStyle->SetStatW(0.28);	 		//Stat box width as fraction of pad size	
	gStyle->SetStatH(0.35);
     
	 		//Size of each line in stat box	
	gStyle->SetStatColor(0);		//Stat box fill color
	gStyle->SetStatTextColor(1);		//Stat box text color
	gStyle->SetStatStyle(1001);		//Stat box fill style!
	//StatFont = 10*fontid + 2 (12 is normal, 22 bold 32 italic)
	gStyle->SetStatFont(72);  		//Stat box fond
	gStyle->SetStatBorderSize(2);		//Stat box border thickness
	//gStyle->SetStatFormat("6.4g");

	//Statistic box options 		(from left to right)
	gStyle->SetOptStat(1110); //Integral, Overflow, Underflow, RMS, Mean, Nent, Name
//	gStyle->SetOptFit(1100);     //probability, Chi2, errors, name/values of parameters

	//Go to view menu on canvas, select markers to view possible values
//	gStyle->SetMarkerStyle(20);		//Marker is a circle
	gStyle->SetMarkerSize(1);  		//Reasonable marker size

	gStyle->SetErrorX(0.00001); //Get rid of x perp line on error bars

	//gStyle->SetOptTitle(0);
	gStyle->SetTickLength(-0.02,"XYZ");
	//
	//to modify a given histogram already in a pad use this?
	//TPaveText *title = (TPavbeText*)gPad->GetPrimitive("title");
	//title->SetX2NDC(0.6);
	//gPad->Modified();


       gStyle->SetTitleColor(1,"x");
       gStyle->SetLabelSize(0.05,"x");         //X-axis label size
       gStyle->SetTitleSize(.06,"x"); 
       gStyle->SetTitleOffset(1.2,"x"); // was .97

//////
  // Paper size

  gStyle->SetPaperSize(TStyle::kUSLetter);

  // Canvas

  gStyle->SetCanvasColor     (0);
  gStyle->SetCanvasBorderSize(10);
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetCanvasDefH      (600);
  gStyle->SetCanvasDefW      (600);
  gStyle->SetCanvasDefX      (10);
  gStyle->SetCanvasDefY      (10);

  // Pads

  gStyle->SetPadColor       (0);
  gStyle->SetPadBorderSize  (2);
  gStyle->SetPadBorderMode  (0);
  gStyle->SetPadBottomMargin(0.15);
  gStyle->SetPadTopMargin   (0.10);
  gStyle->SetPadLeftMargin  (0.12); //0.14
  gStyle->SetPadRightMargin (0.07);//0.07
  gStyle->SetPadGridX       (0);
  gStyle->SetPadGridY       (0);
  gStyle->SetPadTickX       (1);
  gStyle->SetPadTickY       (1);

  // Frames

  gStyle->SetFrameFillStyle ( 0);
  gStyle->SetFrameFillColor ( 0);
  gStyle->SetFrameLineColor ( 1);
  gStyle->SetFrameLineStyle ( 0);
  gStyle->SetFrameLineWidth ( 3);
  gStyle->SetFrameBorderSize(10);
  gStyle->SetFrameBorderMode( 0);


  // Histograms

  // gStyle->SetHistFillColor(2);
//   gStyle->SetHistFillStyle(1);
  //gStyle->SetHistLineColor(1);
  //gStyle->SetHistLineStyle(0);
  gStyle->SetHistLineWidth(2);

  // Functions

  gStyle->SetFuncColor(1);
  gStyle->SetFuncStyle(0);
  gStyle->SetFuncWidth(2);

  //Legends 

  gStyle->SetStatBorderSize(1);
  gStyle->SetStatFont      (42);
  gStyle->SetOptStat       (1111);
//   gStyle->SetOptStat       (0);
  gStyle->SetStatColor     (0);
//  gStyle->SetStatX         (1.2);
//   gStyle->SetStatY         (1.2);
   gStyle->SetStatW         (0.25);
   gStyle->SetStatH         (0.20);

  // Labels, Ticks, and Titles

  gStyle->SetTickLength ( 0.015,"X");
  gStyle->SetTitleSize  ( 0.060,"X");
  gStyle->SetTitleColor ( 1    ,"X");
  gStyle->SetTitleOffset( 1.100,"X");
  gStyle->SetLabelOffset( 0.015,"X");
  gStyle->SetLabelSize  ( 0.050,"X");
  gStyle->SetLabelFont  ( 42   ,"X");
  gStyle->SetNdivisions ( 505 ,"X");

  gStyle->SetTickLength ( 0.015,"Y");
  gStyle->SetTitleSize  ( 0.060,"Y");
  gStyle->SetTitleOffset( 1.110,"Y"); //xxx
  gStyle->SetLabelOffset( 0.015,"Y");
  gStyle->SetLabelSize  ( 0.050,"Y");
  gStyle->SetLabelFont  ( 42   ,"Y");
  gStyle->SetTitleFont  ( 42   ,"Y");
  gStyle->SetNdivisions ( 505   ,"Y");

  gStyle->SetTickLength ( 0.015,"Z");
  gStyle->SetTitleSize  ( 0.060,"Z");
  gStyle->SetTitleOffset( 1.100,"Z");
  gStyle->SetLabelOffset( 0.015,"Z");
  gStyle->SetLabelSize  ( 0.050,"Z");
  gStyle->SetLabelFont  ( 42   ,"Z");
  gStyle->SetTitleFont  ( 42   ,"Z");
  gStyle->SetNdivisions ( 505   ,"Z");


  gStyle->SetTitleBorderSize  (0);
  gStyle->SetTitleFillColor  (0);  
  gStyle->SetTitleFont  (42);
  gStyle->SetTitleColor  (1);

  // Options

  gStyle->SetOptFit     (11);
  gStyle->SetOptStat    (1110);
//gStyle->SetOptFit     (0);
// gStyle->SetOptStat    (0);
 //  gStyle->SetMarkerStyle(20);
  gStyle->SetMarkerSize(0.9);
gStyle->SetErrorX(0.5);

//  gStyle->SetPalette(42, NULL);
/////       
  gStyle->SetPalette(216); // more colors	
	gROOT->ForceStyle();

   	//system("pwd");


}
