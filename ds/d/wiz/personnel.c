// personnel.c 人事管理處

inherit ROOM;

void create()
{
	set("short", "人事管理處");
	set("long",@LONG
這裡是夢幻七域管理人事的地方...玩家應徵巫師必需要在這裡Post
...巫師可以在這查詢每一位巫師的等級及職務...
LONG
	);
	set("exits",([
		"west" : __DIR__"hall1",
		"east" : __DIR__"entrance",
	]));

	set("light",1);
	set("no_clean_up",0);
	setup();
	call_other("obj/board/personnel_b.c", "???");
//	replace_program(ROOM);
}

void init()
{
	add_action("do_list","list");
}

int do_list(string arg)
{

	write("yes...\n");
	return 1;
}