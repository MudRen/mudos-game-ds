#include <room.h>
inherit ROOM;
void create()
{
 set("short","客房走道");
 set("long",@LONG
這邊是向雲堂的上賓客房走道, 也因此打掃的十分乾淨, 桌面都是
手過無痕, 袖過無塵, 真令人佩服堂內家僕的清潔能力. 這邊的地板上
似乎有被什麼重物壓過的感覺, 有一點凹陷下去. 你發現前方不遠處有
個樓梯, 似乎可以通到二樓去. 咦? 南邊的門怎麼站了兩個官兵? 
LONG
    );
 set("exits",([ "west":__DIR__"inroom17",
               "north":__DIR__"inroom23",
               "south":__DIR__"inroom24",
                "east":__DIR__"inroom16",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
