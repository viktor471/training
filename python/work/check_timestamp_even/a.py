from datetime import datetime

class Time:

    @staticmethod
    def get_seconds_since_midnight():
        now = datetime.now()
        midnight = now.replace(hour=0, minute=0, second=0, microsecond=0)
        delta = now - midnight
        return int(delta.total_seconds())

    @staticmethod
    def get_current_date():
        return datetime.today().strftime('%Y-%m-%d')


limit = 200


for i, line in enumerate(open("limits")):
    first = f"{int(limit * (i / (3600 * 24)))}"
    second = f"{(limit * i)// (3600 * 24)}"
    third = line.strip()
    if not (first == second == third):
        print(f"first [{first}], second: [{second}], third: [{third}]")