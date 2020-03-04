#include <room.h>
inherit ROOM;
void create()
{
 set("short","懸崖邊");
 set("long",@LONG
你應該慶幸你沒再往前走三步, 否則必定摔落懸崖之下.
這邊的雲霧滿重的, 不過你仍能看到懸崖之底, 看起來這不
會很高的樣子. 如果你對自己的雙腳有信心, 你可以試著往
下跳(jumpdown).
LONG
    );
 set("exits",([ "north":__DIR__"outroom26",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
