#include <ansi.h>
inherit ROOM;
void create()
{
                 set("short",HIY"布丁店"NOR);

                 set("long", 
      HIC"這是一家充滿歡樂,溫馨,快樂的一家店,裡面每個人都爭相採購,\n"NOR HIG"你慢慢的走進這家店,你彷彿也感到了這溫馨的氣息,你看到牆角\n"NOR
      HIB"總是有一個人,面帶著淡淡的笑意,你好像被她吸引了,經過打聽才\n"NOR     HIR"知道,那是店夫人,她總是面帶微笑的說:\n"NOR
      HIW"你好ㄚ..歡迎來到我跟我老公的布丁店^^\n"NOR

          );

        set("light", 1);

set("exits", ([  /* sizeof() ==  8  */
"sex" :  "/u/s/sexking/workroom" ,
"com" :  "/u/c/cominging/workroom" ,
"past" : "/open/world1/tmr/area/hotel" ,
"lin" : "/u/l/linjack/workroom" ,
"wilfred" : "/u/w/wilfred/workroom" ,
"bread" : "/u/t/tako/ovenroom" , 
"pooding" : "/u/t/tako/pooding room" ,
"area" : "/u/t/tako/area/room~1.c" ,
])); 
set("objects", ([ /* sizeof() == 2 */
  "/u/t/tako/poo-ding.c" : 1, 
  "/u/t/tako/shelf.c" : 1, ]));
set("valid_startroom", 1);

setup(); 
call_other("/obj/board/tako_b.c", "???");

}



void init()

{
     object me=this_player();

     me->set("startroom","/u/t/tako/workroom");

                 } 



