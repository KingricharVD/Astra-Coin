// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2018 The Astra developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_CLIENTVERSION_H
#define BITCOIN_CLIENTVERSION_H

#if defined(HAVE_CONFIG_H)
#include "config/Astra-config.h"
#else
//! These need to be macros, as clientversion.cpp's and Astra*-res.rc's voodoo requires it
#define CLIENT_VERSION_MAJOR 1
#define CLIENT_VERSION_MINOR 00
#define CLIENT_VERSION_REVISION 4
#define CLIENT_VERSION_BUILD 00 

#define CLIENT_VERSION_IS_RELEASE true		// Todo: !! Set to true for release, false for prerelease or test build
#define COPYRIGHT_YEAR 2018					// Todo: update this when changing our copyright comments in the source
#endif //HAVE_CONFIG_H

/**
 * Converts the parameter X to a string after macro replacement on X has been performed.
 * Don't merge these into one macro!
 */
#define STRINGIZE(X) DO_STRINGIZE(X)
#define DO_STRINGIZE(X) #X

//! Copyright string used in Windows .rc files
#define COPYRIGHT_STR "2009-" STRINGIZE(COPYRIGHT_YEAR) " The Bitcoin Core Developers, 2014-" STRINGIZE(COPYRIGHT_YEAR) " The Dash Core Developers, 2015-" STRINGIZE(COPYRIGHT_YEAR) " The PIVX Developers, 2015-" STRINGIZE(COPYRIGHT_YEAR) " The Astra Core Developers"

/**
 * Astrad-res.rc includes this file, but it cannot cope with real c++ code.
 * WINDRES_PREPROC is defined to indicate that its pre-processor is running.
 * Anything other than a define should be guarded below.
 */

#if !defined(WINDRES_PREPROC)

#include <string>
#include <vector>

const int CLIENT_VERSION = 1000000 * CLIENT_VERSION_MAJOR + 10000 * CLIENT_VERSION_MINOR + 100 * CLIENT_VERSION_REVISION + 1 * CLIENT_VERSION_BUILD;


/**
* Name of client reported in the 'version' message. Report the same name
* for both Astrad and Astra-qt, to make it harder for attackers to
* target servers or GUI users specifically.
*/

extern const std::string CLIENT_BUILD;
extern const std::string CLIENT_DATE;

const std::string CLIENT_NAME_STR("Astra Core");
const std::string CLIENT_VERSION_STR("1.0.4.0");


std::string FormatFullVersion();
std::string FormatSubVersion(const std::vector<std::string>& comments);

#endif // WINDRES_PREPROC

#endif // BITCOIN_CLIENTVERSION_H
