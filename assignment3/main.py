from car import Car
from ev import EV

def main():
    # Using default constructors
    genericCar = Car()
    genericEV = EV()
    genericCar.print()
    genericEV.print()

    print("\n----------------------------------------------\n")

    # Using parameterized constructors
    myCar = Car(90, "2022 Honda Civic", "White")
    myEV = EV(90, "2022 Hyundai Ioniq 5", "Gray", 266, 2)
    myCar.print()
    myEV.print()

    print("\n----------------------------------------------\n")

    # Using getters and setters
    myCar.setSpeed(100.0)
    myCar.setColor("Gray")
    myCar.setModel("2022 Honda Accord")
    print("myCar is now a " + myCar.getColor() + " " + myCar.getModel() + ", travelling at " + str(myCar.getSpeed()) + " mph.")

    myEV.setSpeed(120.0)
    myEV.setColor("Black")
    myEV.setModel("2022 Tesla Model 3")
    myEV.setRange(275)
    myEV.setGen(3)
    print("myEV is now a " + myEV.getColor() + " " + myEV.getModel() + ", travelling at " + str(myEV.getSpeed()) + " mph.")
    print("Now, myEV is also a gen " + str(myEV.getGen()) + " EV and has a range of " + str(myEV.getRange()) + " miles.")

    print("\n----------------------- Obstruction Ahead -----------------------\n")
    # Decelerate
    myCar.decelerate()
    myEV.decelerate()
    print("myCar is now travelling at " + str(myCar.getSpeed()) + " mph and myEV is travelling at " + str(myEV.getSpeed()) + " mph.")

    print("\n----------------------- Obstruction Cleared -----------------------\n")
    # Accelerate
    myCar.accelerate()
    myEV.accelerate()
    print("myCar is now travelling at " + str(myCar.getSpeed()) + " mph and myEV is travelling at " + str(myEV.getSpeed()) + " mph.")

    print("\n----------------------- Start Car Production -----------------------\n")
    # Using static method and variable
    car1 = Car(0, "2022 Honda Civic", "White")
    car2 = Car(0, "2022 Honda Civic", "White")
    car3 = Car(0, "2022 Honda Civic", "White")
    car4 = Car(0, "2022 Honda Civic", "White")
    ev1 = EV(0, "2022 Tesla Model S", "Black", 300, 3)
    ev2 = EV(0, "2022 Tesla Model S", "Black", 300, 3)
    ev3 = EV(0, "2022 Tesla Model S", "Black", 300, 3)
    ev4 = EV(0, "2022 Tesla Model S", "Black", 300, 3)

    # Different ways to access static method and variable
    print(str(car4.getNumCars()) + " cars have been produced. (including myCar and myEV)")
    print("Yes, " + str(ev4.getNumCars()) + " cars have been produced. (including myCar and myEV)")
    print(str(Car.numCars) + " cars have definitely been produced. (including myCar and myEV)")

main()