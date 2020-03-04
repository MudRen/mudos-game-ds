#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","內堂");

 set("long",@LONG
 這裡是天梟教的內堂, 你環顧了四周, 發現有四根
 用大理石做的天梟石柱, 地板和天花板也是大理石做的,
 在大廳正中央有一張石椅, 上面坐著一個人, 你想寫那
 血紅色字的人應該就是他了。

LONG
    );
 
 set("exits",(["west":__DIR__"bird18",
              ]));
 set("objects",([__DIR__"npc/fon" : 1,
     ]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 set("light",1);
 setup();
 replace_program(ROOM);
}           
