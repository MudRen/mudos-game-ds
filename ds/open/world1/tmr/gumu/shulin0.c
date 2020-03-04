// shulin0.c 樹林
// Java Oct.10 1998
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "小樹林");
        set("long", @LONG
走在小樹林當中，你只聞錚錚琴聲，一股淡淡白煙，帶著極甜
的花香，自密林深處傳出。一群乳白色的蜜蜂在你身旁飛來飛去。
只見一塊石碑(stele)立在當眼兒處。往東是一塊空地。其它方向
盡是茂密的樹林。
LONG    );
        set("outdoors", "forest");
        set("item_desc", ([
                "stele" : 
HIW"

                        終南古墓，
                        外人止步。\n\n"NOR,

        ]));
        set("exits", ([
                "west"    : __DIR__"shulin5",
                "east"    : __DIR__"shulin6",
                "north"   : __DIR__"shulin4",
                "southup" : __DIR__"shulin1",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

