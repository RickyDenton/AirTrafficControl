package airport;

//The Airport's Parking Area
simple ParkingArea
{
    parameters:

        //----------------------------------Input Parameters----------------------------------
        bool isParkingTimeRandom = default(false);
        bool isTakeoffTimeRandom = default(false);
        double parkingTime = default(10);
        double takeoffTime = default(5);

  //----------------------------Statistics-related Parameters----------------------------

        //1) Number of Parked Planes
        @signal[ParkedPlanes](type="long");
        @statistic[ParkedPlanes](source="ParkedPlanes"; record=vector; );

        //2) Airplanes' Departing Queue Size
        @signal[DepartQueueSize](type="long");
        @statistic[DepartQueueSize](source="DepartQueueSize"; record=vector; );

        //3) Departing Queue Waiting Time
        @signal[DepartQueueWaitingTime](type="double");
        @statistic[DepartQueueWaitingTime](source="DepartQueueWaitingTime"; record=vector; );

        @display("i=misc/town2");
    gates:
        input in;    //From the Airspace
        output out;  //To the Airspace
}
