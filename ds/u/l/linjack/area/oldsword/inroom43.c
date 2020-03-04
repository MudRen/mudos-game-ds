#include <room.h>
inherit ROOM;
void create()
{
 set("short","休息室走道");
 set("long",@LONG
這邊和對面的外賓客房正好相反, 這裡的房間全是給向雲堂
內的部屬在休息的地方. 北邊傳來一陣陣嘻嘻哈哈的笑聲, 還有
人在裡面說一些像是發酒瘋的人在說的話, 口齒不清胡言亂語的,
你最好不要往裡面走比較好.
LONG
    );
 set("exits",([ "north":__DIR__"inroom44",
                 "east":__DIR__"inroom40",
                "south":__DIR__"inroom45",
                 "west":__DIR__"inroom46",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
