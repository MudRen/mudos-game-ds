inherit ROOM;
void create()
{
	set("short", "步靈城西大門前");
	set("long",@LONG
這裡是西大門的前面，在這裡有許許多多的旅客來來往往，防備好
像比東大門還要弱的樣子，在城門旁有一個守衛塔，不過好像不能隨隨
便便的就進去的樣子，西邊就是西大門了，而東邊則是步靈城中的西大
街上。
LONG
	);
	set("exits", ([
  "east" : __DIR__"bwest4.c",
  "west" : __DIR__"bdoor3.c",
]));
	set("objects",([
  __DIR__"npc/traveller.c": 3,
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
}

void init()
{
	add_action("do_enter","enter");
}

int do_enter(string arg)
{
	object me;
	me = this_player();

	if( me->is_busy() || me->is_fighting() )
		return notify_fail("你還在忙喔！\n");
	message_vision("$N打開了守衛塔下的一扇門，然後偷偷摸摸的進了去。\n",me);
	me->move(__DIR__"tower.c");
	return 1;
}