// 紫陽山第四層
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "小空地上");
	set("long", @LONG
這是一個小空地，在這裡有些動物在行走，在你的四周是片小空地
，要小心一點，不然就會摔下山下。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"4f5.c",
  "west" : __DIR__"4f4.c",
  "south" : __DIR__"4f1.c",
  "east" : __DIR__"4f3.c",
]));
	set("objects", ([
  __DIR__"npc/leopard" : 3
]));
	set("world", "past");
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
}

int dish_up()
{
	object dish = new(__DIR__"npc/obj/dish.c");
	dish->move(this_object());
	message_vision(HIR"這裡突然一陣煙霧, 突然一個石盤從地上緩緩顯形... \n"NOR, dish);
	return 1;
}

void start_animal_war(object me, object c)
{
	string file, str;
	file = __DIR__"war.log";
	str = sprintf("%s(%s) 於 %s 開啟了 Purple Sun's Animal's War 。\n", me->query("name"),geteuid(me),ctime(time()));
	write_file(file, str);
	destruct(c);
	message("world:world1:vision", 
		HIW" 紫陽山上只見一道道的白光射出∼∼ \n" NOR
		HIC"\n\n 紫陽山上突然一聲老虎長嘯…… \n\n"NOR
		HIR"接著紫陽山上突然一陣巨響﹐眾野獸在虎神的號召下﹐一個個的都逃出洞穴﹐開始肆虐了！！\n\n\n"NOR,users());
	call_out("end_animal_war", 240);
}

void end_animal_war()
{
	string file, str;
	object animal = find_living("animal-war-object");

	if( objectp(animal) )
	{
		if( !environment(animal) ) destruct(animal);
		call_out("end_animal_war", 60 );
		return;
	}
	else {
		message("world:world1:vision",
	HIM"\n\n       只見紫陽山一下子籠罩在一道紫光下… \n\n"NOR
	HIR"       虎神朝天長嘯了幾陣子﹐似乎心有不甘的樣子…… \n\n"NOR
	HIY"→ "HIG" 紫陽山又回復到了平靜 \n\n"NOR, users());
		file = __DIR__"war.log";
		str = sprintf("%s Purple Sun's Animal's War 關閉。\n", ctime(time()));
		write_file(file, str);
		this_object()->delete("war_start");
		return;
	}
}