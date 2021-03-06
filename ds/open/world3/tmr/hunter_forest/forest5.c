// Room: /tmr/future/hunter_forest/forest5.c

inherit ROOM;

void create()
{
	set("short", "淡霧林間");
	set("long", @LONG
你正處在一重重的淡霧之間，四週長相特異的樹林，更是顯得難以分
辨。你不經意的發現在四周環繞的樹林，赫然有棵發出紫色光芒的樹，樹
幹的粗大顯示出這棵樹的年齡已有數百年之久。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"forest7",
  "south" : __DIR__"forest3.c",
  "north" : __DIR__"forest6.c",
]));
	set("item_desc", ([ /* sizeof() == 2 */
   "紫色光芒的樹" : "你抬起頭來仔細地觀察了這棵奇異的樹，似乎發現樹上結了一些果實！？
",
  "果實" : "一顆放散著紫色光芒的果實，一陣微風吹來，你似乎可以聞到一股舒服的香味。
",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("world", "future");

	setup();
}

void init()
{
	add_action("do_shake","shake");
}


int do_shake(string arg)
{
	object me,ob;
	me=this_player();

	if(!arg || arg!="紫色光芒的樹")
		return 0;
	message_vision("$N抱住了發出紫色光芒的大樹，奮力的搖了起來。\n",me);
	if(query("shake_ok") )
		return notify_fail("結果什麼事也沒發生。\n");	
	else {
		message_vision("經過一陣搖動，樹上似乎掉下了一個發出紫色光芒的東西。\n",me);
		ob=new(__DIR__"obj/fruit");
		ob->move(__FILE__);
		set("shake_ok",1);
	}	
	return 1;
}

void reset()
{
	if(query("shake_ok") )
		delete("shake_ok");
}
