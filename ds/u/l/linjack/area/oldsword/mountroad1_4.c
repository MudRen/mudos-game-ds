#include <room.h>
inherit ROOM;
void create()
{
 set("short","木屋的外面");
 set("long",@LONG
你來到這著個陰涼的地方. 空氣不錯, 你環顧四周發現到
南邊有一個小小的木屋, 應該是山野中一些樵夫所居住的小房
子. 你感到有一股陰風吹到你的附近, 這附近有什麼奇怪的地
方嗎?
LONG
    );
 set("exits",([ "northeast":__DIR__"grave",
                "south":__DIR__"woodhouse",
                "west":__DIR__"mountroad1_3",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}