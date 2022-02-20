#! /usr/bin/env python
from aiogram import Bot, types
from aiogram.dispatcher import Dispatcher
from aiogram.utils import executor

import os

# token = os.getenv("TOKEN")
token = "1830714909:AAGh9WUDcopXzpaUyITNb-F-M4ROVAppH80"
bot = Bot(token)

dp = Dispatcher(bot)

@dp.message_handler()

executor.start_polling(dp, skip_updates=True)

def main():
    pass


if __name__ == "__main__":
    main()
