#include <room.h>
inherit ROOM;
void create()
{
 set("short","客房走道");
 set("long",@LONG
這邊是向雲堂的上賓客房走道, 也因此打掃的十分乾淨, 桌面都是
手過無痕, 袖過無塵, 真令人佩服堂內家僕的清潔能力. 由於許多高強
的練氣士或是道長都在這邊住過, 或是現在正住在這邊, 所以這邊總是
留下一股強烈的壓迫感, 真氣四溢, 有時令你喘不過氣來.
LONG
    );
 set("exits",([ "north":__DIR__"inroom13",
                "south":__DIR__"inroom14",
                 "east":__DIR__"inroom15",
                 "west":__DIR__"inroom7",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
