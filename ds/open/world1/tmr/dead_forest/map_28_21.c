inherit ROOM;
void create()
{
	set("short", "木橋");
        set("long", @LONG
你覺得這兒的空氣非常難聞，有股惡息的味道。
LONG
);
	set("exits",([
		"south" : __DIR__"map_29_21",
		"north" : __DIR__"map_27_21",
	]));
        setup();
        set("map_long",1);     //show map as long
        //replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

void init()
{
	add_action("do_search", "search");
}

int do_search(string arg) 
{
  	object me;
   	mapping cnd_data=([]);
   	me = this_player();
	// 中沼毒
    cnd_data["damage"] = 40;
	cnd_data["duration"] = 3; // 將發作3次
	cnd_data["水"] = 10 ; // gin
	me->set_condition("marsh-poison", cnd_data);
	message_vision("$N四處翻翻找找，但卻沒有任何可疑之處，反覺得身體有點不舒服。\n" , me);
	return 1;
}