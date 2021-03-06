#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set("short","料理屋");
  set("long",@LONG
這裡是一間不算大的料理店，但是好吃的料理可不少，尤其是海
鮮更是保證新鮮好吃，牆壁上掛滿了各種餐點的名稱及價錢，參考看
看吧(look menu)。
LONG);
  set("exits",([ 
      "west":__DIR__"room12",
     ]));
  set("no_clean_up",0);
  set("light",1);
  set("item_desc", ([
      "menu" : "木牌上寫了各種料理的名稱，想吃的話就點吧（order）。\n\n"
           +HIW"吸物(Suimono)                              酒(Sake)\n"NOR
           +"1.蛤吸(Hamaguri-sui)         30            10.清酒(Sake)                     100\n"
           +"2.鯛吸(Tai-sui)　　　　      50　　　  　  11.燒酒(Shoshu)　　               130\n"
           +"3.若芽吸(Wakame-sui)　　     20            12.梅酒(Umeshu)                   150\n"
           +"                                           13.純米大吟釀(Junmai daiginjo)    300\n"
           +HIW"揚物(Agemono)       \n"NOR
           +"4.海老天(Ebi-ten)　　　　    40            "HIW"鍋物(Nebemono)\n"NOR
           +"5.野菜天婦羅(Yasai-tenpura)  25            14.壽喜燒(Sukiyaki)               180\n"
           +"                                           15.涮涮鍋(Shabushabu)             180\n"
           +HIW"燒物(Yakimono)"NOR"                             16.河魨鍋(Fugu)                   250\n"
           +"6.鹽燒(Agu shioyaki)         60\n"         
           +"7.海老鹽燒(Ebi shioyaki)     50\n"
           +"\n"
           +HIW"漬物(Tsukemono)\n"NOR
           +"8.紫蘇梅干(Siso-umebosi)     10\n"
           +"9.納豆(Natto)                10\n\n",
      ]));
  set("objects",([
      __DIR__"npc/food-master":1,
     ]));
  setup();
}            
