#include <path.h>
inherit ROOM;
void create()
{
	set( "short", "廢棄礦坑") ;
	set( "long", @LONG
穿過了瀑布後，你全身濕漉漉地來到了一個山洞中，污濁的空氣
充斥整個空間，令人不禁胸口煩悶，仔細聆聽四周的聲音，似乎有敲
敲打打的聲音由山洞深處傳來。
LONG
);
        set("exits", ([ /* sizeof() == 3 */
                  "out" : ACME_PAST"bonze/b19",
                  "east" : __DIR__"room-48",
                  "south" : __DIR__"room-49",
        ]));
       set("objects",([
                   ALWAYS"torch" : 1,
                 ]) );
        set("light",0);
        set("no_clean_up", 0);
        setup();
}
