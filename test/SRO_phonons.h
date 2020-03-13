#ifdef HAVE_CONFIG_H
#include "agate.h"
#undef HAVE_CONFIG_H
#endif

#include <cxxtest/TestSuite.h>
#include "canvas/canvasphonons.hpp"
#include "base/utils.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include "diff_files.h"

class CanvasPhononsProj : public CxxTest::TestSuite
{

  CanvasPhonons *canvas;

  public:

  void setUp()
  {
    canvas = nullptr;
    canvas = new CanvasPhonons(false);
#ifdef HAVE_NETCDF
    try {
#include "SRO_HIST.hxx"
#include "SRO_DDB.hxx"
      canvas->openFile("SRO_DDB");
    }
    catch ( Exception &e ) {
      std::cerr << e.fullWhat() << std::endl;
      TS_FAIL("Unable to create Canvas");
    }
#endif
  }

  void tearDown() {
    if ( canvas != nullptr ) delete canvas;
  }

  void testFindQpt( void )
  {
#ifndef HAVE_NETCDF
    TS_SKIP("NetCDF is needed");
#endif
    try {
#include "SRO_HIST_qpt.hxx"
      std::istringstream input;
      input.str("SRO_HIST.nc");
      canvas->alter(std::string("findqpt"),input);
      std::ifstream fref("ref_SRO_HIST_qpt.dat",std::ios::in);
      std::ifstream fnew("SRO_HIST_qpt.dat",std::ios::in);
      DIFF_FILES(fref,fnew)
    }
    catch ( Exception &e ) {
      std::cerr << e.fullWhat() << std::endl;
      TS_FAIL("Unable to calculate qpt projection");
    }
  }

  void testAnalyze( void )
  {
#ifndef HAVE_NETCDF
    TS_SKIP("NetCDF is needed");
#endif
    try {
#include "SRO_HIST_Analysis.hxx"
#include "SRO_HIST_Analysis_fullnormalized.hxx"
      std::istringstream input;
      input.str("1/2 1/2 1/2 1 2 3 15");
      canvas->alter(std::string("add"),input);
      input.clear();
      input.str("SRO_HIST.nc");
      canvas->alter(std::string("analyze"),input);
      std::ifstream fref("ref_SRO_HIST_Analysis.dat",std::ios::in);
      std::ifstream fnew("SRO_HIST_Analysis.dat",std::ios::in);
      DIFF_FILES(fref,fnew);
      fref.close();
      fnew.close();
      input.clear();
      input.str("SRO_HIST.nc fullnormalized");
      canvas->alter(std::string("analyze"),input);
      std::ifstream fref2("ref_SRO_HIST_Analysis_fullnormalized.dat",std::ios::in);
      std::ifstream fnew2("SRO_HIST_Analysis.dat",std::ios::in);
      DIFF_FILES(fref2,fnew2);
      fref2.close();
      fnew2.close();
    }
    catch ( Exception &e ) {
      std::cerr << e.fullWhat() << std::endl;
      TS_FAIL("Unable to calculate mode projection");
    }
  }

  void testPumpingPhonons( void )
  {
#ifndef HAVE_NETCDF
    TS_SKIP("NetCDF is needed");
#endif
    try {
      std::istringstream input;
      input.str("1/2 1/2 1/2 1 2 3 15");
      canvas->alter(std::string("add"),input);
#include "SRO_HIST_pumped.hxx"
      input.clear();
      input.seekg(0);
      input.str("structure=SRO_HIST.nc time=2");
      canvas->alter("pump",input);
      std::ifstream fref("ref_SRO_HIST_pumped.dat",std::ios::in);
      std::ifstream fnew("SRO_HIST_pumped.dat",std::ios::in);
      DIFF_FILES(fref,fnew)
    }
    catch ( Exception &e ) {
      if ( e.getReturnValue() != ERRCOM ) {
        std::cerr << e.fullWhat() << std::endl;
        TS_FAIL("Unable to pump phonons");
      }
    }
  }

};

