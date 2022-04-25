#include <iostream>

class MyClock{
    private:
        int hours;
        int minutes;
        int seconds;
    public:
        MyClock(int Seconds): seconds(Seconds), minutes(11), hours(10){}
        MyClock(int Minutes, int Seconds): seconds(Seconds), minutes(Minutes), hours(22){}
        MyClock(int Hours, int Minutes, int Seconds): seconds(Seconds), minutes(Minutes), hours(Hours){}
        int get_total_time() const{
            return ((hours)%12)*60*60 + minutes*60 + seconds;
        }
        void currentTime() const{
            if(hours<12){
                std::cout << (((hours>0)&&(hours<10))? "0":"") << ((hours==0)? 12: hours) << ((minutes<10)? ":0":":")
                << minutes << ((seconds<10)? ":0":":") << seconds << " AM" << std::endl;
            }
            else{
                std::cout << (((hours>12)&&(hours<22))? "0":"") << ((hours==12)? 12: hours%12) << ((minutes<10)? ":0":":")
                << minutes << ((seconds<10)? ":0":":") << seconds << " PM" << std::endl;
            }
        }
        bool operator< (const MyClock& myClock1) const{
            return (get_total_time() < myClock1.get_total_time());
        }
        ~MyClock(){
            currentTime();
            return;
        }
};
