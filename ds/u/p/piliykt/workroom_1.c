#include <weapon.h>
#include <ansi.h>
inherit ROOM;
void create()
{
set("short",HIC"霍"HIR"格"HIY"華"HIM"茲"NOR);
set("long", @LONG
這裡正是大名鼎鼎的魔法學校霍格華茲, 在你眼前的巨大建築物正是
霍格華茲的本部, 你的前方就有一扇大鐵門, 鐵門旁站了許多的魔法護衛
, 防止你隨便到這搗亂, 因為霍格華茲可是執行許多重要計劃的指揮總部
和培訓地點. 
LONG
);
set("valid_startroom", 1);     
set("light",1);
set("exits", ([ 
                "enter"   : __DIR__"workroom_2.c",
                                    ]));

 setup();
        
}

