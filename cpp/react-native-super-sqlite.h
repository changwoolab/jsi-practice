//
//  react-native-super-sqlite.hpp
//  react-native-super-sqlite
//
//  Created by 유창우 on 1/5/24.
//

#ifndef react_native_super_sqlite_h
#define react_native_super_sqlite_h

#include <jsi/jsilib.h>
#include <jsi/jsi.h>
#include <stdio.h>

using namespace facebook;

void installSequel(jsi::Runtime &rt);

void cleanUpSequel();


#endif /* react_native_super_sqlite_h */
