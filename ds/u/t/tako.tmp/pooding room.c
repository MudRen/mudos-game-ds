#include <ansi.h>
inherit ROOM;
void create()
{
                 set("short",HIY"布丁室"NOR);

                 set("long", 
HIC"這裡是做布丁的的房間,也是布丁店 BOSS 的最愛,這\n"NOR
HIC"間房間曾陪過 BOSS 渡過最難熬的日子,也陪 BOSS 一\n"NOR
HIC"起迎接到一位非常要好的牽手\n"NOR
          );

        set("light", 1);

set("exits", ([  /* sizeof() ==  1  */
"back" : "/u/t/tako/workroom" ,

])); 
set("objects", ([ /* sizeof() == 1 */
  "/u/t/tako/pooding oven.c" : 1, 
]));
set("valid_startroom", 1);

setup(); 

}



void init()

{
     object me=this_player();

     me->set("startroom","/u/t/tako/pooding room");

                 } 




