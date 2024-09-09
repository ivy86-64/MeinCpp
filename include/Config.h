//
// Created by madeline on 24/09/08.
//

#ifndef CONFIG_H
#define CONFIG_H

#include "Core.h"
#include <libconfig.h++>

using namespace libconfig;

class ConfigHandler {
    Config cfg;

    const char* output_file{"config.cfg"};

public:

    void initConfig();

    int windowWidth{};
    int windowHeight{};
};

#endif //CONFIG_H
