#include <ansi.h>
inherit ROOM;
void create()
{
                 set("short",YEL"烤麵包室"NOR);

                 set("long", 
HIW"你一進到這間房間後,馬上有一股淡淡的麵包的香味撲鼻而來\n"NOR
HIW"你仔細的一看,這裡有一臺烤箱,裡面放著波羅麵包,奶油麵包\n"NOR
HIW",草梅,葡萄等等..的麵包,那種氣息讓你的口水不斷的流出來\n"NOR
          );

        set("light", 1);

set("exits", ([  /* sizeof() ==  1  */
"back" : "/u/t/tako/workroom" ,

])); 
set("objects", ([ /* sizeof() == 1 */
  "/u/t/tako/oven.c" : 1, 
]));
set("valid_startroom", 1);

setup(); 

}



void init()

{
     object me=this_player();

     me->set("startroom","/u/t/tako/ovenroom");

                 } 



