#include <room.h>
#include <path.h>
inherit ROOM;
void create()
{
 set("short","潮濕的小路");
 set("long",@LONG
走過了步靈城之外一小段的護城水路, 你來道了一處頗為
陰溼的小路, 不過仔細觀察周圍你就會發現這條路本來應該很
寬的, 應該是因為非常久這邊都人煙罕見, 才會導致這裡變成
這樣子的.
LONG
    );
 set("exits",([ "northeast":COMINGING_PAST+"area/river7",
                "southwest":__DIR__"path2",]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}