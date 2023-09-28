import telebot


BOT_TOKEN = '5987717272:AAFESsMLruCSXeD4xWEaun0wG6Z_zsOAkXI'

bot = telebot.TeleBot(BOT_TOKEN)


@bot.message_handler(commands=['start', 'hello'])
def send_welcome(message):
    bot.reply_to(message, "tfrtgyuhiuiu")
    
bot.infinity_polling()