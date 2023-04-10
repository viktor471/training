import random

class IfaPoolIfa:

    _LENGTHS = (8, 4, 4, 4, 13)

    @staticmethod
    def _generate_random_hex(length: int):
        return "".join(hex(random.randint(0, 15)).removeprefix("0x") for i in range(length))

    @classmethod
    def get_random_ifa(cls):
        return "-".join(cls._generate_random_hex(length) for length in cls._LENGTHS)
