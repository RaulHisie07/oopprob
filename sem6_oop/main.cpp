#include "Circuit.h"
#include "Volvo.h"
#include "BMW.h"
#include "Fiat.h"
#include "Seat.h"
#include "RangeRover.h"
int main()
{
    Circuit c;
    c.SetLenght(100);
    c.SetWeather(ploaie);
    c.AddCar(new Volvo());
    c.AddCar(new BMW());
    c.AddCar(new Seat());
    c.AddCar(new Fiat());
    c.AddCar(new RangeRover());
    c.Race();
    c.ShowFinalRanks();
    c.ShowWhoDidNotFinish();
    return 0;

}