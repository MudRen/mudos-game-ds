#include <room.h>;
#include <ansi.h>;
inherit ROOM;
void create()
{
      set("short",MAG"秘密的特殊角落"NOR);
      set("long",@LONG
這裡的是一個秘密的房間, 普通的人是難以發現這裡的秘密的, 你突
然發現有一個全身充滿的詭異的男人正站在這裡張開大嘴對你露出邪邪的
笑, 四周放著一箱一箱的大木箱子, 空氣中充斥的一股濃厚的火藥味。
LONG);
set("exits",([
     "north":__DIR__"4.c",
]) );
        set("world", "future"); 
set("objects", ([
__DIR__"weapon/weapon-man.c":   1,
]) );
setup();
replace_program(ROOM); 
}
