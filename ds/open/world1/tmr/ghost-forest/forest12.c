// Room: /tmr/garea/forest12.c

inherit ROOM;

void create()
{
	set("short", "綠沼");
	set("long", @LONG
在你西邊數步之外有處極大的深綠帶暗紅色沼澤，看來陰慘恐怖，沼
澤周圍赫然可見不少骸骨，沼面上也長有奇相怪狀的植物，整個沼面散發
出極惡臭的屍氣味，令人聞之欲吐。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	  "southeast" : __DIR__"forest10",
	  "northeast" : __DIR__"forest14",
	]));
	set("item_desc",([
	"沼澤":"你由東至西地橫掃了沼面一眼，似乎在澤邊看見了發出紅色光的金屬。\n"
	]) );
	set("outdoors","forest");
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_search","search");
}

int i = 1;

int do_search(string arg)
{
	object me,key;
	me=this_player();
	
	if( !arg || arg!="澤邊" ) return 0;
	message_vision("$N俯下了身子，伸手在澤邊摸來摸去。\n",me);
	if (i==1) 
	{
		tell_object(me,"你發現了一隻鑰匙！！\n");
		key=new(__DIR__"npc/obj/redkey");
		key->move(me);
		i=0;
	}
	else
	{
		tell_object(me,"你搞著一身臭沼水，卻沒有發現到什麼...\n");
	}
	return 1;
}
