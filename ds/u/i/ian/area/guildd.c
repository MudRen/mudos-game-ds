#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"天鷹聖廊"NOR);
 set("long",@LONG
這條通向天梟派內部的寬大走廊內有數以百計的老鷹, 在走道上翱翔
著, 鳴叫著, 在你頭上飛舞著, 僅管他們並沒有傷害你的舉動, 你不禁還
是微微的感到害怕. 
LONG
    );
 set("exits",([ "south":__DIR__"guildc",
                "north":__DIR__"guilde",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
