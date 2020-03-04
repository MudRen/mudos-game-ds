// Room: /tmr/future/hunter_forest/hole3.c

inherit ROOM;

int call_npc(object me);
void create()
{
	set("short", "山洞內");
	set("long", @LONG
你正站在一個山洞內，地上滿滿的都是果皮，散發出來的紫色光芒照
得滿室生輝，你瞧了瞧四周，似乎找不到其他的通道。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
	  "south" : __DIR__"hole1",
	]));
	set("light", 1);
	set("world", "future");

	setup();
}
void init()
{
	object me,c;
	me=this_player();
	if(!objectp(present("pulp",me)) ) return;

	if(objectp( c=present("yalen cirri",me) ) )
		if (c->query("catch_ok")==1) return;
	call_out("call_npc",1,me);
}

int call_npc(object me)
{
	object ob;
	ob=new(__DIR__"npc/gu-name");
	if(!objectp(present("gu name") ) )
	{
		tell_room(__FILE__,"忽然從地面爬出一隻動物，似乎被"+me->query("name")+"身上的香味所吸引。\n");
		ob->move(__FILE__);
	}
	return 1;
}
