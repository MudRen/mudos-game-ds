// Room: /tmr/future/hunter_forest/forest8.c

inherit ROOM;

void create()
{
	set("short", "亞連樹前");
	set("long", @LONG
你正站在一棵大亞連樹前，亞連樹為一多年生藤蔓型植物，你可以很
清楚地看到亞連樹的樹枝上垂掛了數以百計的藤蔓，能生長得這麼健全、
繁茂，實在是很少見的自然環境。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	  "east" : __DIR__"forest4",
	]));
	set("item_desc",([
        "藤蔓":"亞連樹藤蔓俱有相當強的勒力，為套捕動物的好用繩索。\n藤蔓雖然堅勒難拔，但似乎可以拉扯的(pull)下來。\n",
	]) );
	set("no_clean_up", 0);
	set("world", "future");
	set("outdoors","forest");
	setup();
}

void init()
{
	add_action("do_pull","pull");
}

int do_pull(string arg)
{
	object me,ob;
	me=this_player();

	if(!arg || arg!="藤蔓" )
		return 0;
	if(me->is_busy() || me->is_fighting() )
		return notify_fail("你正忙著...\n");

	message_vision("$N靠近了亞連樹，運用雙手開始拉扯一根藤蔓。\n",me);
	me->start_busy(1);
	if(query_temp("pull_ok") )
		message_vision("$N拉扯了好一會兒，還是扯不來。\n",me);
	else {
		message_vision("$N拉扯了好一會兒，終於扯下一根藤蔓。\n",me);
		ob=new(__DIR__"obj/yalen_cirri");
		ob->move(me);
		set_temp("pull_ok",1);
	}
	return 1;
}

void reset()
{
	if(query_temp("pull_ok" ) )
		delete_temp("pull_ok");
}


