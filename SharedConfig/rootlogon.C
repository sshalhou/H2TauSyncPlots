//------------------------------------------------------------------------------
//  ROOT logon macro - needs a lot of cleanup, but works for my eyes
//------------------------------------------------------------------------------
{
//#include <iomanip.h>
#include <time.h>
#include <Rtypes.h>

gROOT->SetStyle("Plain");
gStyle->SetLineScalePS(2);

gStyle->SetTitleX(0.182691);       //Title box x position (top left-hand corner)	
gStyle->SetTitleY(0.997881 ); 	//Title box y position (default value)		
gStyle->SetTitleW(0.750771);		//Title box width as fraction of pad size
gStyle->SetTitleH(0.091101);	//Title box height as fraction of pad size	
	

gStyle->SetTitleBorderSize  (0);
gStyle->SetTitleFillColor  (0);  
gStyle->SetTitleFont  (42);
gStyle->SetTitleColor  (1);
gStyle->SetTitleStyle(1001);	//Title box fill style!

gStyle->SetStatX(0.995);		//Stat box x position (top right hand corner)	
gStyle->SetStatY(0.8); 		//Stat box y position 		
gStyle->SetStatW(0.28);	 		//Stat box width as fraction of pad size	
gStyle->SetStatH(0.35);
     
gStyle->SetStatBorderSize(1);
gStyle->SetStatFont      (42);
gStyle->SetStatColor     (0);
gStyle->SetStatW         (0.25);
gStyle->SetStatH         (0.20);
gStyle->SetOptFit     (11);
gStyle->SetOptStat    (1110);

gStyle->SetMarkerStyle(22);
gStyle->SetMarkerSize(1.5);  		
gStyle->SetErrorX(0.5); 
gStyle->SetTickLength(0.025,"XYZ");

gStyle->SetPaperSize(TStyle::kUSLetter);


gStyle->SetCanvasColor     (0);
gStyle->SetCanvasBorderSize(10);
gStyle->SetCanvasBorderMode(0);
gStyle->SetCanvasDefH      (600);
gStyle->SetCanvasDefW      (1200);
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

gStyle->SetHistLineWidth(2);

// Functions

gStyle->SetFuncColor(1);
gStyle->SetFuncStyle(0);
gStyle->SetFuncWidth(2);


//  gStyle->SetTickLength ( 0.015,"X");
gStyle->SetTitleSize  ( 0.060,"X");
gStyle->SetTitleColor ( 1    ,"X");
gStyle->SetTitleOffset( 1.100,"X");
gStyle->SetLabelOffset( 0.015,"X");
gStyle->SetLabelSize  ( 0.050,"X");
gStyle->SetLabelFont  ( 42   ,"X");
gStyle->SetNdivisions ( 505 ,"X");

//  gStyle->SetTickLength ( 0.015,"Y");
gStyle->SetTitleSize  ( 0.060,"Y");
gStyle->SetTitleOffset( 1.110,"Y"); //xxx
gStyle->SetLabelOffset( 0.015,"Y");
gStyle->SetLabelSize  ( 0.050,"Y");
gStyle->SetLabelFont  ( 42   ,"Y");
gStyle->SetTitleFont  ( 42   ,"Y");
gStyle->SetNdivisions ( 505   ,"Y");

//  gStyle->SetTickLength ( 0.015,"Z");
gStyle->SetTitleSize  ( 0.060,"Z");
gStyle->SetTitleOffset( 1.100,"Z");
gStyle->SetLabelOffset( 0.015,"Z");
gStyle->SetLabelSize  ( 0.050,"Z");
gStyle->SetLabelFont  ( 42   ,"Z");
gStyle->SetTitleFont  ( 42   ,"Z");
gStyle->SetNdivisions ( 505   ,"Z");

    
gStyle->SetPalette(216); // more colors	
gROOT->ForceStyle();



}
