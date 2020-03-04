#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"天梟宿舍"NOR);

 set("long",@LONG
你一踏進門內, 就發現天梟攻武一派的宿舍竟然如此奇特, 
原來天梟弟子的床都是懸吊在空中的! 你不禁感到好笑, 這是
感念他們的創派始祖嗎?還是有其他的原因? 從這裡往北走可
已到天梟的廚房, 往東則可以回到天梟後院.
LONG
    );
 set("exits",([ "north":__DIR__"bird8",
                "east":__DIR__"bird6",
                "west":__DIR__"bird9",
    ]));
set("objects", ([__DIR__"npc/bird_apprentice" : 4,

    ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}
