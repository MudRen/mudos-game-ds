#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "小涼亭");
        set("long", @LONG
這是一座小涼亭，涼亭中央的石桌、石椅已殘破不堪，細看之下，地
上還隱然有血跡，四周的亭柱上也有被兵器砍損的刻痕，涼亭後邊是面峭
壁，這峭壁高聳接雲，四面都是陰岩怪石，約在二十來丈處有塊突出的大
石塊，上頭竟有些微的血水滴將下來。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	  "north" : __DIR__"lake-road2",
	]));
         set("item_desc", ([       
        "峭壁" : "一片高聳的岩壁，倒也不難攀爬。\n",
        "大石塊" : "突出於峭壁上，看來倒可容下二、三人。\n",
        ]) );

	set("outdoors","land");
	set("no_clean_up", 0);
        setup();
}

void init()
{
	add_action("do_climb","climb");
}

int do_climb(string arg)
{
 	object me;
	me=this_player();
	if (arg != "峭壁") return 0;
	
        message_vision("只見$N手、足並用，慢慢地爬上了峭壁。\n" ,me);
        me->move(__DIR__"highstone");
          tell_room(environment(me),me->query("name")+"氣喘噓噓地爬了上來。\n",me);
	return 1;
}



