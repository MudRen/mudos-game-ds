#include <weapon.h>
#include <ansi.h>
inherit ROOM;
void create()
{
set("short",HIC"大廳"NOR);
set("long", @LONG
這裡是霍格華茲的大廳也是最主要的地方, 再你的上方有五個超大弔
燈, 照的這裡閃閃方光, 你可以看見這裡有很多的巫師, 在這裡聊天與交
換心得, 往北有一條走道, 西邊是區域研究所, 東邊是mob實驗室,(wiz)
是往巫師交誼聽, 往上可到名人堂, 往下到達eq研究所.
LONG
);
set("light",1);
set("exits", ([ 

                "north"  : __DIR__"a_1.c",
                "west"   : __DIR__"a_2.c",
                "east"   : __DIR__"a_3.c",
                "out"    : __DIR__"workroom_1.c",
                "up"     : __DIR__"piliykt.c",
                "down"   : __DIR__"eq.c",
                "wiz"    : "/d/wiz/hall1",         
                           ]));
 setup();
}

