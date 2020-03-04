// Room: /tmr/future/hunter_forest/forest7.c

inherit ROOM;

void create()
{
	set("short", "林中空地");
	set("long", @LONG
你正站在森林中一處空地，在生長濃密的森林，實在很難見到這麼一
處空闊的草地，只是你似乎發現到草地中有著一個又一個一的小洞穴，一
眼看去，少說也有三、四十個之多。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	  "east" : __DIR__"forest5.c",
	]));
	set("item_desc",([
	"小洞穴":"約只有大拇指寬，令人好奇裡頭到底有什麼東西。(embed)\n",
	]) );
	set("no_clean_up", 0);
	set("world", "future");
	set("outdoors","forest");
	setup();
}

void init()
{
	add_action("do_embed","embed");
}

int do_embed(string arg)
{
	object me;
	me=this_player();
	if(!arg || arg!="小洞穴" ) return 0;
	message_vision("$N伸長了手指頭插進了地上的一個小洞穴，結果似乎沒什麼事。\n",me);
	return 1;
}
