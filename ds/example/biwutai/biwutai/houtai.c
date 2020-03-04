// 山貓(adx) by snow 2000-05-15

inherit ROOM;

void create ()
{
	set ("short", "后台");
	set ("long", @LONG
這是比武場的后台，上面是貴賓席用來主持比武的地方，只有巫師或
者貴賓才能上去。
LONG);
	set("no_fight",1);
	set("no_clean_up",1);
	set("exits", ([
		"up"   : __DIR__"caipan",
		"southeast"   : __DIR__"kantai3",
		"southwest"   : __DIR__"kantai1",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	object ob, where;

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);

	if ( !wizardp(me) && dir=="up" ) {
		if(!me->query("snowzongshi"))
			return notify_fail("只有小雪宗師才能從這里進入貴賓席。\n");
	}
	return ::valid_leave(me, dir);
}
