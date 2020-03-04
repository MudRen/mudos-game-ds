#include <room.h>
inherit ROOM;
void create()
{
 set("short","柵門前");
 set("long",@LONG
走了幾步路, 你來到了一個木製柵門的前面, 這邊的林木
看起來就稀疏了不少, 你已經可以清楚的見到四周的景物. 前
面似乎也是一個營地, 說不定是什麼土匪山寨, 最好快離開這
裡, 或許還有離開的機會.
LONG
    );
 set("exits",([ "north":__DIR__"bandit10",
                "south":__DIR__"bandit8",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
