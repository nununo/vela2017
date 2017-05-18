//
//  SystemInfo.h
//  vela2017
//
//  Created by Nuno on 31/03/2017.
//
//

#ifndef SystemInfo_h
#define SystemInfo_h

#include "ITrace.h"
#include "GeneralSettings.h"

class SystemInfo : public ITrace {
public:
  SystemInfo(GeneralSettings _generalSettings) {generalSettings = _generalSettings;}
  ~SystemInfo() {};
  
  // ITrace
  virtual std::string getTrace();
  
private:
  GeneralSettings generalSettings;
};

#endif /* SystemInfo_h */
