//
//  ArchitectureREADME.h=
//
//  Created by Robert Russell Millward on 1/28/20.
//  Copyright © 2020 Robert Russell Millward. All rights reserved.
//
#ifndef ArchitectureREADME_h
#define ArchitectureREADME_h

/**
 * Using Java nomenclature, this set of demo code has both Classes and Instances.
 * Within those are api (functions) and data. They frequently exist independently but can be
 * packaged.
 * There are three major divisions in the code: application (meaning person, lineItem, etc),
 * quality assurance, and helpers.
 * Class related structure names have a "C" near the end. Instance related structure names
 * have an "I" near the end. Application structure names have an "A" near the end. Quality
 * structure names have a "Q" near the end. Helper structure names have an "H" near the
 * end.
 * Further, to keep code files small levels have been implemented. Level "0" is at the very
 * bottom. Level "8" is currently the top. The higher the level the highrr the complexity or
 * interaction with other levels.
 * Further, to simplify versions and inheritance a version letter has been implemented.
 * The version letter starts at "O" and works toward "A". The letter "Z" is the bottom level
 * that can support all other versions.
 * Finally, the test data generators have "T" through "P" near the end of the name and
 * "Y" is the root.
 * So from this, the purpose of the various file names might be easy to deduce:
 * - PersonO0AIapi would be level O, version 0 application instance function pointers
 * - PersonO0AIdata would be an instance data structure
 * - PersonO0AInew would be the combined api and data structures with a pointer to
 * the api if size is an issue or including the api structure if not. Thus:
 * - PersonO0AInewT myPerson = PersonO0ACapi.new(...);
 * - PersonO0AIdataT myPersonData = PersonO0ACapiP->newData(...);
 * - are two ways to instantiate Person data with one also giving the api.
 * - As can be seen, the data type ends in "T".
 * - If a pointer is being used then it has a "P" before the "T" as myPersonDataPT.
 *
 * One last example set:
 * - PersonO0QIdata is a Quality Instance
 * - TimeSerNbrO0HCapi.getIt(...) is a Helper structure function call
 * - TimeSerNbrZ0HCapiT and TimeSerNbrZ0HCdataT is root data and functions.
 *
 * FInally, many header files end with Z0Plan.h and these are how the data is accessed
 * and contain the definitions that the code is built around. There can be a function structure
 * at the end which exposes some of the internal information as a testing hook. Those
 * functions and data are, as they say, subject to change without notice.
 */

#endif /* ArchitectureREADME_h */
/**
 *
 */
