#include <room.h>
inherit ROOM;
void create()
{
 set("short","新門生練功\房");
 set("long",@LONG
這間是向雲堂新進弟子平日練功休息之所, 看起來這邊有
兩三人的樣子, 有一名資歷較深的師兄正在這邊帶著他們修練
內家心法. 如果你也是向雲堂的弟子, 應該可以和他們一起練
功吧.
LONG
    );
 set("exits",([ "south":__DIR__"inroom52",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
