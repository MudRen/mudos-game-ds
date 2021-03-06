// Room: /tmr/garea/forest6.c

inherit ROOM;

void create()
{
	set("short", "林間空地");
	set("long", @LONG
這是林間的一小片黃土空地，方圓不過數尺，兩旁除了青草綠樹，不
時可看見螻蟻之類的小昆蟲，兼可聽得鳥叫蟲嗚，為這寂靜的林野增加了
些許熱鬧。在你西邊有片草原，其高過人數尺，往西向的視野皆被遮敝。
映入眼簾的尚有一簇雜草叢，隱約可聽到人聲。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	  "southeast" : __DIR__"forest4",
	  "northeast" : __DIR__"forest8",
	]));
        set("item_desc",([
        "草叢":"一簇青綠草叢，頗有間隙能容人穿過去。\n",
        ]) );

	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
}

void init()
{
	add_action("do_pass","pass");
}

int do_pass(string arg)
{
	object me;
	me=this_player();
	if(!arg || arg!="草叢") return 0;
	message_vision(
"$N穿過了高可及人的草叢。\n",
	me );
	me->move(__DIR__"lea");
	
	tell_room(
	environment(this_player() ),
	me->query("name")+"穿過了草叢，走了過來。\n",
	me
	);
	return 1;
}

