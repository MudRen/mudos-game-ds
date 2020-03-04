// Room: /u/m/mulder/area/road13.c

inherit ROOM;

void create()
{
	set("short", "廢車場 - 小街");
	set("long", @LONG
你現在可能不相信那些謠言，但是可你抱住「寧可信其有，
不可信其無」的心態向前進發．心想能看見那些殺手真面目，但
是傳聞那殺手是十分強勁的，曾有一些玩家組織一小隊入來殺
死這�堛滷�手，但結果「全軍覆沒」，你看見地上有一些奇怪車
輪．
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
    "south" : __DIR__"shop2",
]));
	set("no_clean_up", 0);
	set("item_desc", ([
        "wheel" : "一個十分奇怪的車輪, 或許\你可以轉轉看。\n",
        "車輪" : "一個十分奇怪的車輪, 或許\你可以轉轉看。\n",
        ]));

	set("outdoors","land");
	setup();	
}
void init()
{
	add_action("do_roll","roll");
}	
	int do_roll(string arg)
{
	object me;
	me=this_player();
	if (arg != "車輪" && arg !="wheel" )
	return 0;

	else
	{
	message_vision("$N轉動車輪，發現多出了一條路並走入去。\n",me);
	me->move(__DIR__"road16");
	tell_room(environment(me),me->query("name")+"轉動車輪，發現多出了一條路並走入去。\n",me);
	return 1;
	}
}