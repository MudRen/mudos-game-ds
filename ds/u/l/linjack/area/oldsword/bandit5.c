#include <room.h>
inherit ROOM;
void create()
{
 set("short","山中小徑");
 set("long",@LONG
透過叢生的樹林, 你似乎隱約的看到有幾個影子在晃動,
不知道有什麼東西在那邊....你最好提高警覺.
LONG
    );
 set("exits",([ "west":__DIR__"bandit4",
                "north":__DIR__"bandit6",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
