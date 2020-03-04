
#include <path.h>
inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
這裡是一條走廊，有遮陽遮雨的屋頂，在你的東邊是一座倉庫，而
在你的西邊是通往煉丹房及教壇的走道，南邊就是花園了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room36",
	    "west" : __DIR__"room35",
	    "south": __DIR__"room33",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
load_object("/u/p/pudon/war2/tfighter");  
load_object(CLASS"fighter/soul");
	replace_program(ROOM);
}
