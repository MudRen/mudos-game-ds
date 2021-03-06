/**
 * Shadow's area [荒廢漁村 - 義莊 - graveyard3]
 */ 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG"義莊"NOR);
	set("long",@LONG
這兒似乎是義莊東南側的邊緣地帶，南邊沒有出路可去，而朝東
望去亦只見重重密林，同樣無法從中找到出路。北邊一樣是無法計數
的墓地，看樣子若不硬著頭皮走下去是不可能會找到出路了！
LONG
	);
	set("outdoors","land");
	set("light", 0);
	set("exits",([
		"west": __DIR__"graveyard2",	
		"north": __DIR__"graveyard31",
	]));
  
	setup();
}

int room_effect(object me)
{
	switch(random(3))
	{ 
		case 1:
			message_vision("你似乎感覺有雙手摸了摸你的腳！\n", me);
			return 1;
		default:
			return 1;
	}
}
