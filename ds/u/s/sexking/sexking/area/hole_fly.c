#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIY"光芒磁場中");
        set("long", @LONG
你被捲入這一恐怖的光芒中，不知接下來到底會發生什麼事
的你，越來越緊張，你漸漸的昏了過去....
LONG
        );
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall",1);
        set("no_kill",1);
        setup();
}
