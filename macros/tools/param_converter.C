void param_converter() {



    TString califaCalFilename = "../../califa/califacalibparams_v1.root";

    UInt_t fDummyRunId=1;

    R3BCalifaCrystalCalPar *calPars;

    FairParRootFileIo* inputRoot = new FairParRootFileIo(kTRUE); // from root to par
    // FairParAsciiFileIo* inputRoot = new FairParAsciiFileIo(kTRUE); // from par to root

    FairRuntimeDb* rtdb = FairRuntimeDb::instance();

    calPars = dynamic_cast<R3BCalifaCrystalCalPar*>(rtdb->getContainer("califaCrystalCalPar"));


    inputRoot->open(califaCalFilename,"in");
    rtdb->setFirstInput(inputRoot);

    Bool_t kParameterMerged = kFALSE;
    FairParAsciiFileIo* parOut = new FairParAsciiFileIo(); // from root to par
    // FairParRootFileIo* parOut = new FairParRootFileIo(); // from par to root

    parOut->open("../../califa/califacalibparams_v1.par","out"); // from root to par
    // parOut->open("../../califa/califacalibparams_v1.root","out"); // from par
    // to root
    rtdb->setOutput(parOut);


    rtdb->addRun(1);
    rtdb->setInputVersion(fDummyRunId,(char*)"califaCrystalCalPar",1,1);

    rtdb->initContainers(kTRUE);
    rtdb->saveOutput();




}
