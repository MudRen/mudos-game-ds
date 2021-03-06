#include <room.h> //要加門要這一行
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "大牢內");
	set("long", @LONG
你身處在大牢內，大牢裡燈光昏暗，在你旁邊有個給犯人解禁的
小坑洞，不時的傳來惡臭之味，許多蟑螂在牆上爬，地上還有老鼠在
啃食著犯人吃剩的饅頭。在這種環境裡，你不禁嘆道：還是不要犯罪
的好！
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
    "north" : __DIR__"jail4",
]));
set("objects",([
    __DIR__"npc/mouse": 3,
    __DIR__"npc/prisoner" : 1,
]) );
     set("item_desc", ([ /* sizeof() == 1 */
       "燭檯" : "這個燭檯竟會擺\在牆角，十分古怪，你可以試著轉動(roll)它。\n",
       "坑洞" : "這個坑洞又臭又髒，放了什麼大概只有問住在這裡的囚犯才知道。\n",
     ]));
	 set("no_recall",1);
	set("no_clean_up", 0);

	setup();
	create_door("north","牢門","south",DOOR_LOCKED,"jailkey");
}
void init()
{ 
         add_action("do_dig","dig");
         add_action("do_roll","roll");
}

int do_dig(string arg)
{
	object me;
	me=this_player();
	if(arg != "坑洞") return 0;
	if( me->is_busy() ) return notify_fail("你的動作還沒有完成﹐不能做動作。\n");
	else {
		message_vision("$N伸手往坑洞裡挖，竟挖得滿手的大便！好噁哦！\n",me);
		me->start_busy(2);
		return 1;
	}
}

int do_roll(string arg)
{
	object me;
	me=this_player();
	if( arg != "燭檯" ) return 0;
	else {
		if(me->query_temp("SKYCITY/shout")>1)
		{
			message_vision("$N輕輕地轉動著燭檯，突然地板露出了一個地道，$N跌進地道中。\n",me);
			me->move(__DIR__"injail2");
			me->delete_temp("SKYCITY/shout");
		}
		else {
			message_vision("$N輕輕地轉動著燭檯，但是一點動靜也沒有。\n",me);
		}
	return 1;
	}
}
