#include <room.h>
inherit ROOM;
void create()
{
 set("short","叢林中");
 set("long",@LONG
你走到這裡, 並沒有發覺什麼可疑的地方的, 小徑是向北繼
續伸展下去, 過了一會兒, 你又聽見了野獸的叫聲, 但是十分難
以辨認出聲音的來源, 因為回音就在這叢林中迴盪, 你甚至連這
是哪種猛獸的叫聲都不知道.
LONG
    );
 set("exits",([ "north":__DIR__"jungle7",
		"west":__DIR__"jungle5",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}