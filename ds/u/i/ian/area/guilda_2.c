#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"天鳩石室"NOR);
 set("long",@LONG
這間石室裡有無數個架子, 架子裡的每一格都有一種藥材, 看來這裡
是天梟儲存藥材的地方了, 每個架子上都有藥的名稱, 你可以在這裡找到
自己要的藥材, 等等, 在房間的角落有個人坐在那, 似乎是在看守這些藥
材, 以免被外人拿走的, 看來你是要掏腰包買藥材了...
LONG
    );
 set("exits",([ "north":__DIR__"guilda",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
