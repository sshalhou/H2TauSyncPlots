# H2TauSyncPlots

- code for generating sync plots given a few sync trees with common branch names 

- To run you need to setup configuration directories containing 2 files :

		configHists.txt & configInstitutions.txt

- configHists.txt should contain comma separated histogram info with format :

		branch, bins, min, max, title, x-title, y-title

		for example : m_vis, 25, 0, 500, visible di-Tau mass, di-Tau Mass [GeV], Events/Bin

- configInstitutions.txt should contain comma separated institution & file info  
		
		 inst. label, rootFile, TTree Path/Name

		 for example : UCD, ~/Desktop/files/160_sync/Davis_SyncNtuples/davis_syncTree_EleMu.root, TauCheck

- once the txt files are in place can run with command :

		./run.py ArbitraryChannelLabel ConfigDirectoryPath		

		where ArbitraryChannelLabel = a label for the channel e.g. EleTau, MuTau (it will be added to plot titles)

		and ConfigDirectoryPath = path to directory holding the 2 config files
