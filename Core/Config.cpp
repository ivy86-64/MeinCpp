#include "Core.h"
#include <iomanip>
#include <cstdlib>
#include <string_view>
#include <libconfig.h++>
#include "Config.h"

using namespace libconfig;

void ConfigHandler::initConfig() {
    //Read the file
    try {
        cfg.readFile("config.cfg");
    }

    catch(const FileIOException &fioex) {
        std::cerr << "I/O error while reading file:";
    }
    catch(const ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                  << " - " << pex.getError() << '\n';
    }
    Setting &root = cfg.getRoot();

    if(! root.exists("video"))
        root.add("video", Setting::TypeGroup);

    Setting &video = root["video"];

    if(! video.exists("windowWidth"))
        video.add("windowWidth", Setting::TypeInt) = 800;

    if(! video.exists("windowHeight"))
        video.add("windowHeight", Setting::TypeInt) = 600;

    // address.add("monitor", Setting::TypeArray) = glfwGetPrimaryMonitor();


    try {
         cfg.writeFile(output_file);
            std::cout << "New configuration successfully written to: " << output_file << '\n';
    }
    catch(const FileIOException &fioex) {
    std::cout << "I/O error while writing file: " << output_file << '\n';
    }



}


