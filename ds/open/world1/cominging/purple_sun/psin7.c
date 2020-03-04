inherit ROOM;

void create()
{
	set("short", "山腳下");
	set("long", @LONG
這裡已是紫陽山的山腳正下方了，往上就是一層層的山路了，山路
陡峭崎嶇不易行走，常有些不知名的人就此一去不回，近來事件也因江
湖上的另一謠言而淡淡減少。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"1f5.c",
  "southwest" : __DIR__"psin6.c",
]));
	set("no_clean_up", 0);
    set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

/*int valid_leave(object me, string dir)
{
	if( !query("fall_stone") )
		return ::valid_leave(me, dir);
	if( query("fall_stone") && dir == "up" )
	{
		write(HIW"往山上的路被落石所擋住, 而不能通行！\n"NOR);
		return 1;
	}
}

void fall_stone()
{
	object b_stone = new(__DIR__"npc/obj/b_stone.c");
	if( !objectp(b_stone) ) CHANNEL_D->do_channel(this_object(), "sys", "ERROR: 找不到 stone .");
	b_stone->move(this_object());
	set("fall_stone", 1);
	return;
}

void clean_stone()
{
	object b_stone = present("stack-road", this_object());
	destruct(b_stone);
	delete("fall_stone");
}*/
