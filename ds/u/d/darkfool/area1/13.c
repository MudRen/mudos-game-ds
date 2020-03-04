// Room: /u/d/darkfool/area1/13.c

inherit ROOM;

void create()
{
	set("short", "街道盡頭");
	set("long", @LONG
這裡是街道的盡頭，住宅區在你的北方不遠處，但這裡似乎沒有
路可以通過去，你的東方有幢小屋。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"12",
]));

	setup();
}
void init() 
{
	add_action("usecomp","use");
}
int usecomp(string  arg)
{
	object me;
	me=this_player();
	if(arg != "computer") return 0;
	 else {
	 	message_vision(
	 	"門刷地一聲開了\n\n"
	 	,me);
	         set("exits",([
	        "west" : __DIR__"12",
	        "house" :__DIR__"a1",
	        ]));
	        return 1;
	       }
}	
	 	