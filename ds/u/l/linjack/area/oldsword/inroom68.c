#include <room.h>
inherit ROOM;
void create()
{
 set("short","正廳");
 set("long",@LONG
這裡是正廳的右上側, 這邊看起來就比剛剛幾個地點冷清
了一點, 沒什麼人在這邊用菜, 不過桌上還有蠻多不錯的菜色,
你乾脆把它吃掉算了吧.
LONG
    );
 set("exits",([ "west":__DIR__"inroom65",
               "south":__DIR__"inroom66",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
