#include "XmlStore.h"

//--------------------------------------------------------------
bool XmlStore::setup(string _filename) {
  filename = ofToDataPath(_filename);
	if( XML.loadFile(filename) ){
	  cout << "Loaded xml settings from file " << filename << endl;
		return true;
	}else{
	  cout << "Error loading xml settings from file " << filename << endl;
	  return false;
	}
}

//--------------------------------------------------------------
bool XmlStore::save() {
  XML.saveFile(filename);
}
