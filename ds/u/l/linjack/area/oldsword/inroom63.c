#include <room.h>
inherit ROOM;
void create()
{
 set("short","正廳");
 set("long",@LONG
這邊是正廳的右下方, 你可以看到仍然有一兩個人在進食,
有一些侍衛也在旁邊待命. 桌布鋪設的漂漂亮亮的, 讓人看了
就覺得心情舒快.
LONG
    );
 set("exits",(["north":__DIR__"inroom66",
                "west":__DIR__"inroom4",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
