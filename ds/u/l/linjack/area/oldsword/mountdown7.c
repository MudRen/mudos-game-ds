#include <room.h>
inherit ROOM;
void create()
{
 set("short","山下道路");
 set("long",@LONG
這邊算是上國改制成為新朝之後, 所修建的主要道路末段了,
再下來便是一般旅人為了方便自己再開的路, 已經不是那麼好走
的了. 這附近開始都要算邊陲地帶. 聽說遠近馳名向天關就在這
一帶, 有機會應該去見識見識.
LONG
    );
 set("exits",([ "west":__DIR__"mountdown6",
                "south":__DIR__"mountdown8",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}