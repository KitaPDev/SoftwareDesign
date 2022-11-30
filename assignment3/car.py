from vehicle import Vehicle

class Car(Vehicle):
    __speed = 0.0
    __model = ""
    __color = ""
    numCars = 0

    def __init__(self, speed: float = 60.0, model: str = "Generic Car", color: str = "Silver"):
        self.__speed = speed
        self.__model = model
        self.__color = color
        Car.numCars += 1
    
    def getSpeed(self) -> float:
        return self.__speed

    def getModel(self) -> str:
        return self.__model
    
    def getColor(self) -> str:
        return self.__color
    
    def setSpeed(self, speed: float):
        self.__speed = speed

    def setModel(self, model: str):
        self.__model = model

    def setColor(self, color: str):
        self.__color = color

    def print(self):
        print("I am a " + self.__color + " " + self.__model + ", travelling at " + str(self.__speed) + " mph.")

    def decelerate(self) -> float:
        self.__speed -= 10
        return self.__speed

    def accelerate(self) -> float:
        self.__speed += 10
        return self.__speed

    def getNumCars(self) -> int:
        return Car.numCars