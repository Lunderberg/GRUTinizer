#ifndef _TFASTSCINTDETECTORHIT_H_
#define _TFASTSCINTDETECTORHIT_H_

#include "TDetectorHit.h"
#include <TMath.h>


class TFastScintHit : public TDetectorHit {
public:
  TFastScintHit();
  TFastScintHit(const TDetectorHit&);

  virtual void Print(Option_t* opt = "") const;
  virtual void Clear(Option_t* opt = "");
  virtual void Copy(TObject& obj) const;

  //void SetCharge(int chg)    { fCharge  = chg;  }
  void SetChannel(int chan)  { fChannel = chan; }
  //void SetTime(int time)     { fTime = time;    }
  //void SetTimestamp(long ts) { fTimestamp = ts; }
  //void SetEnergy();

  //virtual int Charge() const { return fCharge;    }
  int  GetChannel()    const { return fChannel;   }
  //int  GetTime()       const { return fTime;      }
  //long GetTimestamp()  const { return fTimestamp; }
  //float GetEnergy()    const { return fEnergy;    }
  //
  TVector3 &GetPosition() const;


  //double GetEnergy() const { return (Charge()*0.5181 ) - 0.268; } 

  double GetDoppler(double beta,const TVector3 *vec=0) const {
    if(vec==0) {
      vec = &BeamUnitVec;
    }
    double tmp = 0.0;
    double gamma = 1/(sqrt(1-pow(beta,2)));
    tmp = GetEnergy()*gamma *(1 - beta*TMath::Cos(GetPosition().Angle(*vec)));
    return tmp;
  } 


private:
  //long  fTimestamp;
  int   fChannel;
  //int   fTime;
  //int   fCharge;
  //float fEnergy;

  ClassDef(TFastScintHit,22)
};

#endif /* _TFASTSCINTDETECTORHIT_H_ */
