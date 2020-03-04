#include <room.h>
inherit ROOM;
void create()
{
 set("short","山路上");
 set("long",@LONG
這邊花草濃密, 還有些鳥兒和蝴蝶們在這邊飛舞, 你好似
進入了一個世外桃源, 空氣傳來一股幽幽的香味, 你慢慢的走
著這段山路, 讓你感覺清新愉快.
LONG
    );
 set("exits",([
               "eastdown":__DIR__"mount11",
               "westup":__DIR__"mount9",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
