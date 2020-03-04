#include <room.h>
inherit ROOM;
void create()
{
 set("short","客房走道盡頭");
 set("long",@LONG
這裡是向雲堂客房的二樓, 上面看起來就比較空蕩的樣子,
而且這邊就要比一樓來的髒些, 不過大體來說還算乾淨. 這邊
已經是客房走道的底部了, 再往裡面一點看可以看到一扇木門,
似乎是倉房之類或什麼的. 南北兩邊的房間都沒人住. 
LONG
    );
 set("exits",([ "west":__DIR__"inroom33",
               "north":__DIR__"inroom31",
               "south":__DIR__"inroom32",
                "east":__DIR__"inroom27",]));
 set("no_clean_up", 0);
 set("light", 1);
 setup();
 replace_program(ROOM);
}
