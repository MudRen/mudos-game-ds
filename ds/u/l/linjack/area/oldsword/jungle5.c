#include <room.h>
inherit ROOM;
void create()
{
 set("short","叢林中");
 set("long",@LONG
你走到這裡, 並沒有發覺什麼可疑的地方的, 小徑是往東西方
向延伸的, 再往東走就更深入這個叢林之中了. 你可以看到你所踏
之地是越來越潮濕了, 似乎附近有沼澤還是什麼的.
LONG
    );
 set("exits",([ "east":__DIR__"jungle6",
		"west":__DIR__"jungle4",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}