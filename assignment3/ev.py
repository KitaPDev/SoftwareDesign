from car import Car

class EV(Car):
    __range = 0.0
    __gen = 1

    def __init__(self):
        super().__init__()
        self.__range = 200.0
        self.__gen = 1

    def __init__(self, speed: float = 60.0, model: str = "Generic EV", color: str = "Silver", range: float = "200", gen: int = 1):
        super().__init__(speed, model, color)
        self.__range = range
        self.__gen = gen

    def getRange(self) -> float:
        return self.__range

    def getGen(self) -> int:
        return self.__gen

    def setRange(self, range: float):
        self.__range = range

    def setGen(self, gen: int):
        self.__gen = gen

    def print(self):
        super().print()
        print("I am also a gen " + str(self.__gen) + " EV and has a range of " + str(self.__range) + " miles on a single charge.")