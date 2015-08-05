#!/usr/bin/env python 
import time
import sys
import os
import math
import fileinput
import ROOT
from ROOT import gROOT,TChain, TLorentzVector, TSelector
from ROOT import TLegend, TTree, TF1, TH1F, TCanvas, gStyle, TFile, TPad
ROOT.gROOT.Macro( os.path.expanduser( './SharedConfig/rootlogon.C'))
gStyle.SetOptStat(000000)
gROOT.SetBatch(1)


def printErrorMes():
	print "--------------------------------------------"
	print "**Error** invoke the sync plot generator using command : ./run.py ArbitraryChannelLabel ConfigDirectoryPath"
	print "where ConfigDirectoryPath contains the files configHists.txt & configInstitutions.txt"
	print "------------------"
	print "configHists.txt should contain comma separated histogram info with format : \n branch, bins, min, max, title, x-title, y-title"
	print "		e.g. : m_vis, 25, 0, 500, visible di-Tau mass, di-Tau Mass [GeV], Events/Bin"
	print "------------------"
	print "configInstitutions.txt should contain comma separated institution & file info : \n inst. label, rootFile, TTree Path/Name" 
	print "		e.g. : UCD, ~/Desktop/junk/160_sync/Davis_SyncNtuples/davis_syncTree_EleMu.root, TauCheck"
	print "--------------------------------------------"
	return

# make a dictionary of histograms, files, and dictionaries, and institutions

skip_dict = {} # keys for histograms with 0 entries (otherwise they mess up the plots)
hist_dict = {}
hist_dict_keyList = [] # preserve order

file_dict = {}
canvas_dict = {}
inst_dict = {}
treeName_dict = {}

if len(sys.argv) < 3:
	printErrorMes()
	sys.exit()

channelLabel = sys.argv[1]
configsFolder = sys.argv[2]


legendCounter = 0 # track number of legends
legendList = {} # dict of the legends so each is unique object

denominatorKEY = 'NULL' # to set the denominator in ratio plots to 1st institution in config

if os.path.isfile(str(configsFolder)+"/configInstitutions.txt") is False:
	print 'missing file : '+str(configsFolder)+'/configInstitutions.txt'
	printErrorMes()
	sys.exit()

if os.path.isfile(str(configsFolder)+"/configHists.txt") is False:
	print 'missing file : '+str(configsFolder)+'/configHists.txt'
	printErrorMes()
	sys.exit()

# add files, institution labels and TTree paths to the dicts :
for line in fileinput.input(str(configsFolder)+"/configInstitutions.txt"):
	if '#' in line:
		continue 
	holder = (line.rstrip()).split(',')
	for k in range(0, len(holder)):
		holder[k] = (holder[k].rstrip()).lstrip()

	if len(holder)!=3 :
		print 'invalid line in institution config file', holder
		printErrorMes()
		sys.exit()

	# take file name from path
	lastLocation = holder[1].split('/')
	lastFile = lastLocation[len(lastLocation)-1]

	if denominatorKEY == 'NULL':
		denominatorKEY = lastFile

	inst_dict[lastFile] = str(holder[0])		
	treeName_dict[lastFile] = str(holder[2])		
	file_dict[lastFile] = TFile(str(str(holder[1])),"READ")

print 'will use 1st institution listed : ', inst_dict[denominatorKEY], ', as denominator in ratio plots'

# generate histograms and canvases
for line in fileinput.input(str(configsFolder)+"/configHists.txt"):
	if '#' in line:
		continue 	
	holder = (line.rstrip()).split(',')
	for x in range(0, len(holder)):
		holder[x] = (holder[x].rstrip()).lstrip()
	if len(holder)!=7 :
		print 'invalid line in histogram config file', holder
		printErrorMes()
		sys.exit()

	canvas_dict[str(holder[0])] = TCanvas(str(holder[0]),str(holder[0]),1500,1100)
	for key,value in inst_dict.iteritems():
		#print str(key+'_'+holder[0])
		hist_dict[str(key+'_'+holder[0])] = TH1F(str(key+'_'+holder[0]),str(key+'_'+holder[0]),int(holder[1]),float(holder[2]),float(holder[3]))
		hist_dict[str(key+'_'+holder[0])].Sumw2()
		hist_dict[str(key+'_'+holder[0])].SetTitle(holder[4]+" ["+channelLabel+"]"+";"+holder[5]+";"+holder[6])
		hist_dict_keyList.append(str(key+'_'+holder[0]))



# fill the histograms
for canvasKEY,canvasVALUE in canvas_dict.iteritems():
	for fileKEY,fileVALUE in file_dict.iteritems():
		#print treeName_dict[fileKEY]
		tempTree = fileVALUE.Get(str(treeName_dict[fileKEY]))
		drawArg1 = canvasKEY+">>"+str(fileKEY+'_'+canvasKEY)
		#drawArg2 = canvasKEY+"!=-999"	
		drawArg2 = ""
		tempTree.Draw(drawArg1,drawArg2)
		#print str(fileKEY+'_'+canvasKEY), hist_dict[str(fileKEY+'_'+canvasKEY)].GetEntries()
		if hist_dict[str(fileKEY+'_'+canvasKEY)].GetSumOfWeights() == 0:
			skip_dict[str(fileKEY+'_'+canvasKEY)] = 1.0
		elif math.isnan((hist_dict[str(fileKEY+'_'+canvasKEY)].GetSumOfWeights())):
			skip_dict[str(fileKEY+'_'+canvasKEY)] = 1.0
		elif math.isinf((hist_dict[str(fileKEY+'_'+canvasKEY)].GetSumOfWeights())):
			skip_dict[str(fileKEY+'_'+canvasKEY)] = 1.0
		else:
			skip_dict[str(fileKEY+'_'+canvasKEY)] = 0.0
				



for canvasKEY,canvasVALUE in canvas_dict.iteritems():
	plotCount = 0
	canvasVALUE.Clear()	
	canvasVALUE.cd()
	pad1 = TPad("pad1", "pad1",0.0,0.4,1.0,1.0,-1)
	pad2 = TPad("pad2", "pad2",0.0,0.01,1.0,0.38,-1)
	pad1.Draw()
	pad2.Draw()	

	denominatorHist = TH1F() # first instution's hists will be the denominator
	denominatorInst = "NULL"
	numeratorHist = []	 # the others to be used in ratio
	numeratorInst = []	 # the institutions to be used in ratio

	for i in range(0, len(hist_dict_keyList)):		
		histKEY = hist_dict_keyList[i]
		histVALUE = hist_dict[histKEY]
		if skip_dict[histKEY] == 1.0:
			print 'invalid histogram content (0, nan, or inf) : ', histKEY, 'will skip'
			continue
		elif skip_dict[histKEY] == 1.0 and (denominatorKEY + "_" + canvasKEY) == histKEY:
			print 'invalid denominator histogram (0,nan, or, inf) :', histKEY, 'will abort [please choose a differnt denominator]'
			sys.exit()
		pad1.cd()
		if histKEY.endswith("_"+canvasKEY):
			plotCount = plotCount+1
			histVALUE.SetMarkerStyle(21+plotCount)
			histVALUE.SetMarkerSize(1.8)
			if plotCount != 3: # this shade is hard to see
				histVALUE.SetMarkerColor(plotCount)
				histVALUE.SetLineColor(plotCount)
			else :
				histVALUE.SetMarkerColor(46)
				histVALUE.SetLineColor(46)				
			if plotCount == 1:
				histVALUE.SetMaximum(1.4*histVALUE.GetMaximum())
				histVALUE.Draw("PE")				
			else:
				histVALUE.Draw("PEsames")
			if	(denominatorKEY + "_" + canvasKEY) == histKEY:
				denominatorHist = histVALUE.Clone("denominatorHist")
				denominatorInst = inst_dict[denominatorKEY]
			else :
				numeratorHist.append(histVALUE.Clone("numeratorHist"+str(plotCount)))
				numeratorInst.append(inst_dict[histKEY.split('.root_')[0]+'.root'])

# 	# print 'den', denominatorHist, denominatorInst
# 	# for x in range(0, len(numeratorHist)):
# 	# 	print 'num', numeratorHist[x], numeratorInst[x]





	# add a TLegend
	legend = TLegend(.7,.5,.85,.85) # for comparison pad
	legend.Clear()
	legend.SetTextSize(.05)
	legend.SetTextFont(22)
	legend.SetBorderSize(0)
	legend.SetFillColor(ROOT.kWhite)
	legend.AddEntry(denominatorHist,denominatorInst+" : "+str(denominatorHist.GetEntries()),"PL")
	for x in range(0, len(numeratorHist)):
		legend.AddEntry(numeratorHist[x],numeratorInst[x]+" : "+str(numeratorHist[x].GetEntries()),"PL")
	canvasVALUE.cd(1)
	legendList[legendCounter] = legend.Clone(str(legendCounter))
	legendList[legendCounter].Draw()
	legendCounter = legendCounter + 1
	canvasVALUE.Update()


	pad2.cd()
	firstRatio = 0
	for num in numeratorHist:
		ratio = num.Clone("ratio"+str(firstRatio))
		ratio.Reset()
		ratio.Divide(num,denominatorHist,1,1,"B")
		ratio.SetTitle("Ratios : "+ratio.GetTitle())
		ratio.GetYaxis().SetTitle("Ratio to "+denominatorInst)
		ratio.GetXaxis().SetTitleSize(6/4. * ratio.GetXaxis().GetTitleSize())
		ratio.GetYaxis().SetTitleSize(6/4. * ratio.GetYaxis().GetTitleSize())
		ratio.GetXaxis().SetTitleOffset(1.05*4/6. * ratio.GetXaxis().GetTitleOffset())
		ratio.GetYaxis().SetTitleOffset(4/6. * ratio.GetYaxis().GetTitleOffset())

		ratio.GetXaxis().SetLabelSize(6/4. * ratio.GetXaxis().GetLabelSize())
		ratio.GetYaxis().SetLabelSize(6/4. * ratio.GetYaxis().GetLabelSize())
		ratio.GetXaxis().SetLabelOffset(4/6. * ratio.GetXaxis().GetLabelOffset())
		ratio.GetYaxis().SetLabelOffset(4/6. * ratio.GetYaxis().GetLabelOffset())

		ratio.GetXaxis().SetTickLength(6/4. * ratio.GetXaxis().GetTickLength());
		ratio.GetYaxis().SetTickLength(6/4. * ratio.GetYaxis().GetTickLength());

		if firstRatio == 0:
			ratio.SetMaximum(2.0*ratio.GetMaximum())
			ratio.SetMinimum(0*ratio.GetMaximum())			
			firstRatio = firstRatio+1
			ratio.DrawCopy("PE")
		if firstRatio != 0:
			ratio.DrawCopy("PE sames")
			firstRatio = firstRatio+1

	legendR = TLegend(.75,.65,.85,.85) # for ratio pad
	legendR.Clear()
	legendR.SetTextSize(.05)
	legendR.SetTextFont(22)
	legendR.SetBorderSize(0)
	legendR.SetFillColor(ROOT.kWhite)
	for x in range(0, len(numeratorHist)):
		if(numeratorHist[x].GetEntries()!=0):
			legendR.AddEntry(numeratorHist[x],numeratorInst[x]+"/"+denominatorInst,"PL")
	canvasVALUE.cd(1)
	legendList[legendCounter] = legendR.Clone(str(legendCounter))
	legendList[legendCounter].Draw()
	legendCounter = legendCounter + 1
	canvasVALUE.Update()


# save all to a pdf file
numPrints = 0
canvasVALUE.Print(channelLabel+"_SYNCplots.pdf[")	 # open pdf
for canvasKEY,canvasVALUE in canvas_dict.iteritems():
	canvasVALUE.cd()
	canvasVALUE.Update()
	if numPrints == 0:		
		canvasVALUE.Print(channelLabel+"_SYNCplots.pdf")	
		numPrints = numPrints + 1
	elif numPrints != len(canvas_dict)-1:
		canvasVALUE.Print(channelLabel+"_SYNCplots.pdf")	
		numPrints = numPrints + 1
	else :
		canvasVALUE.Print(channelLabel+"_SYNCplots.pdf")	
canvasVALUE.Print(channelLabel+"_SYNCplots.pdf]")	# close pdf




