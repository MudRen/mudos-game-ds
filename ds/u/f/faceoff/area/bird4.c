#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"天梟東邪堂"NOR);

 set("long",@LONG
這裡到處陰森森的, 原來就是鼎鼎大名的天梟東邪堂, 
也就是專門幫天梟鏟除敵人的一個分堂, 你看到眼前的刑
具真是千奇百怪, 想起以前天梟不知道在這處理了幾個反
對者, 你對於這裡的陰森也有了解釋. 從這裡往西走就可
回到天梟的大院. 你心裡真想往那跑去....
LONG
    );
 set("exits",([ "west":__DIR__"bird2",
    ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}
