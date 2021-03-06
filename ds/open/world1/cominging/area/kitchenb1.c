inherit ROOM;

void create()
{
	set("short", "廚房下倉庫");
	set("long", @LONG
這裡是倉庫下方的小倉庫，釀有許多陳年的老酒，不禁令你想要大
喝一口，在這其中不乏女兒紅，白干，紹興等常喝的酒類，在這裡充滿
了酒的味道，令人有點眩暈，地上有一罐罐的酒甕，裡面都是裝著酒，
說不定可以偷喝幾口。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"kitchen2.c",
]));
	set("objects",([
  __DIR__"npc/obj/winepot.c":1,
]));
	set("light", 1);
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_potation","potation");
}

int do_potation(string arg)
{
	object me;
	string a;
	me = this_player();

	if( !arg || sscanf(arg,"from %s",a)!=1 )
		return notify_fail("你要喝什麼呀？(potation from <東西>)\n");
    if( a!="wine" && a!="bodega" && a!="wine bodega" )
        return notify_fail("你要從那喝酒呀？\n");
	if( this_player()->is_busy() )
		return notify_fail("你上一個動作還沒有完成。\n");
	if( this_player()->is_fighting() ) this_player()->add_block(1);
    me->receive_damage("hp",1);
    me->receive_heal("ap",20);
	if( me->query_temp("grogginess") < 35 || !me->query_temp("grogginess") )
		message_vision("$N從酒甕中喝了幾口的酒，似乎有些醉意。\n",me);
	else message_vision("$N醉意沉沉，又從酒甕中喝了幾口酒，開始有些酒醉了。\n",me);
	me->start_busy(2);
	me->add_temp("grogginess",5);
	if( (int)me->query_temp("grogginess") > 70 )
	{
		me->unconcious();
		me->delete_temp("grogginess");
	}
        return 1;
}
