// 奧凡迪斯郊區
// LV 1~50
#include <path.h>
inherit ROOM;

void create()
{
	set("short", "樹林");
	set("long", @LONG
高大的樹林將這裡擠得沒有什麼空間可以讓你自由移動，你僅能從樹
木與樹木之間的縫隙鑽進去。人們已經有很長的時間在這裡走動過了。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out045",
	    "east" : LUKY_NOW"area_1/room61",
            ]));
	set("item_desc",([	
	"縫隙" : "你發現這個隙縫似乎可以鑽(drill)進去。\n",
	])	);
	set("outdoors","forest");	// 樹林
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
}

void init()
{
	add_action("do_drill","drill");
	return;
}

int do_drill(string arg)
{
	object me;
	me = this_player();
	if(arg!="隙縫") return notify_fail("你要鑽到哪裡ㄚ?\n");
	if(me->is_busy()) return notify_fail("你上一個動作還沒完成。\n");
	message_vision("$N小心翼翼的鑽進林間的隙縫中。\n",me);
	me->move(__DIR__"out053");
	message_vision("$N從樹林旁的小洞鑽了出來。\n",me);
	return 1;
}