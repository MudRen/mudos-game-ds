#include <weapon.h>
#include <ansi.h>
inherit ROOM;
void create()
{
set("short",HIY"mob研究所"NOR);
set("long", @LONG
這裡是霍格華茲的研究所, 主要是用來研究mob的地方, 這裡主要
是創造mob, 測試mob的強度, 及一些mob的設定, 這裡的設備當然是最
先進的, 在你的旁邊就有一台生物製造器, 可以用來製造千百種mob, 往
北邊是mob測試場.
LONG
);
set("light",1);
set("exits", ([ 
                                
                "west"   : __DIR__"workroom_2.c",
                "north"  : __DIR__"b_1.c",
                                    ]));

 setup();
}

