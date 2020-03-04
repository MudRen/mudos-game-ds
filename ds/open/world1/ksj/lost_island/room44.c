#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "遺世島－"HIW"千古石林"NOR);
        set("long", @LONG
這裡是靠近山壁地勢較高的部份，這個地方較為空曠，地上只有
一些零星的石塊，在山壁間有一處山洞，不時有強勁的海風從洞中吹
出，發出呼∼嗚∼嗚∼的聲音。
LONG);
        set("exits", ([
            "east" : __DIR__"room41",
            "enter" : __DIR__"room45",
        ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        set("no_auc", 1);
        setup();
}
