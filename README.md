# drawing-01-ianrobison18
drawing-01-ianrobison18 created by GitHub Classroom   

See rqmts: a non-existent file shouldn't keep us from running (how would we *ever* run the program for the first time??)   
The problem is you can't initialize settings mgr based on data you get from a file that might not exist: you need to first create the instance    
of SettingsMgr with defaults, then try to load from the file (replacing those default values with values from the file...if there is a file)   
Grade: 47/50   

