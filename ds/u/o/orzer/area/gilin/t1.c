#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","祭靈森林口");
        set("long",@LONG
你來到了森林入口前，雖然森林內有著一陣陣的寒氣，可是你依然
還有著勇氣，還有著一探究竟的打算，這裡聳立著一個木牌，木牌上很
像有些文字，森林分成兩條路，看來通往不同方向。
LONG
        );
        set("exits", ([
  "northeast" : __DIR__"t12",
  "southwest" : __DIR__"t2",
   "south" : __DIR__"m7",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        set("item_desc", ([
            "木牌" : "朝廷禁地，閒人勿進，違者"HIR"殺無赦\n"NOR
                     "              "HIY"天朝  "HIC"大將軍府令\n"NOR
            ]));        
        setup();
        replace_program(ROOM);
}







