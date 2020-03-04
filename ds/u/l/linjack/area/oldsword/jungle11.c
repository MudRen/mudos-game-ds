#include <room.h>
inherit ROOM;
void create()
{
 set("short","叢林中");
 set("long",@LONG
你走到這邊來, 似乎顯得比較乾燥, 路是往西北方延伸過去的,
往南走可以回到叢林中的叉路口. 你仍然可以隱隱約約的聽到一絲
絲野獸嗷嘯之聲, 而且似乎比較清晰了.
LONG
    );
 set("exits",([ "northwest":__DIR__"jungle12",
                "south":__DIR__"jungle4",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}