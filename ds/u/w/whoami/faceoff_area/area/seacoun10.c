#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","主海政部");
set("long",@LONG
這裡往北就是海政長官處了, 你發現這裡的樑與樑之間都
嵌有一種神奇的, 狀似琉璃瓦, 但又比琉璃瓦透明許多的東西
因此你可以很清楚的看見裡面有一位正在埋頭苦幹的人....
LONG
    );
 set("exits",([ "north":__DIR__"seacoun11",
		"south":__DIR__"seacoun9",
]));
 set("objects", ([__DIR__"npc/bladeguard" : 2,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
