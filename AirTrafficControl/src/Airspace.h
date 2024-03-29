#ifndef __CONTROLTOWER_AIRSPACE_H
#define __CONTROLTOWER_AIRSPACE_H

#include <omnetpp.h>

class ControlTower;               //Forward declaration of the ControlTower class

using namespace omnetpp;

namespace airport
{
  class Airspace : public cSimpleModule
   {
    private:

      /*--------------Input Parameters--------------*/
     bool isInterArrivalTimeRandom;
     bool isLandingTimeRandom;
     double interArrivalTime;
     double landingTime;
     int totalSamples;

     /*--------Statistics-related Signals----------*/
     simsignal_t holdingQueueSize;
     simsignal_t holdingQueueWaitingTime;
     simsignal_t airportResponseTime;
     simsignal_t TotalSimtime;
     simsignal_t RunwayUse;

     /*------------------Other--------------------*/
     int departedPlanes;               //Number of airplanes that departed from airport (used to stop the simulation after TOTAL_AIRPLANES samples have been collected)
     simtime_t nextArrival;            //Arrival time of the next airplane
     simtime_t nextLandingTime;        //Landing time of the next airplane
     cQueue* holdingQueue;             //FIFO queue of airplanes waiting for landing
     ControlTower* controlTower;       //Used for cross-module call purposes

    protected:
     virtual void initialize();
     virtual void refreshDisplay() const;
     virtual void handleMessage(cMessage* airplane);
     virtual ~Airspace();

    public:
     virtual simtime_t getMaxQueueTime(); //Returns the time the oldest plane entered the holding queue, or "-1.0" if the queue is empty (called by the ControlTower module)
     virtual void go();                   //Starts the landing of the oldest plane in the holding queue (called by the ControlTower module)
  };

}; //namespace

#endif
