#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIC"幻"HIW"˙"HIC"光"HIW"˙"HIC"界"NOR);
        set("long",
         "這什麼都沒有，只是一片虛幻光影，讓你有點無法置信\n"
         "不過慢慢的你發現，在無數交織的虛實間，彷彿有一種東西\n"
         "似乎有個力量控制此地，在璀璨的虹光下，一切虛無的事物\n"
         "也令人覺得有如實際一般。\n" 
         );
        set("light", 1);
        set("exits", ([  /* sizeof() == 3 */            
         "start"  : "/open/world2/anfernee/start/hall", 
            "wiz" : "/d/wiz/hall1",
            "tra" : "/open/world1/tmr/area/hotel",
          "poleg" : "/u/h/hiko/poleg/po0",
          "test"  : "/u/h/hiko/trm1",
       "fongevil" : "/u/h/hiko/fongevil/mu1", 
          ]));                 
        set("valid_startroom", 1);
call_other("/obj/board/hiko_b","???");
        setup();
}


