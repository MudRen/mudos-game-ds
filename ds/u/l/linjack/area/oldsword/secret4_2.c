#include <room.h>
inherit ROOM;
void create()
{
 set("short","堂主寢室上方夾層");
 set("long",@LONG
你往光線來源的小縫中一看, 很明顯的發現下面就是堂
主寢室, 原來這邊是堂主寢室上面的夾層! 咦? 堂主在下面
不知道在說什麼話, 你可以仔細聽看看.
LONG
    );
 set("exits",([ "back":__DIR__"secret4_1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
