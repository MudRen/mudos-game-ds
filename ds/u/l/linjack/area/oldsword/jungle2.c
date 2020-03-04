#include <room.h>
inherit ROOM;
void create()
{
 set("short","叢林入口");
 set("long",@LONG
你非常非常小心翼翼的走著, 經過了那小徑, 來到了這片叢林
之中...., 這邊非常的昏暗而且潮濕, 偶爾可以看到一些你不常見
的生物. 明顯的出路似乎只有往北走了.
LONG
    );
 set("exits",([ "west":__DIR__"jungle1",
		"north":__DIR__"jungle3",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
