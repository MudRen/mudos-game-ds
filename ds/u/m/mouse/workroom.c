#include <login.h>
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",HIR"鼠窩"NOR);
    set("long",@LONG
陰暗的小巷角落一間被人所遺忘的小房間，房間的大門早已不知去
向，屋內破爛不堪，連張完整的椅子也找不到，只有一隻老鼠大搖大擺
的在房間內到處亂跑，累的時候就跑到剛偷來的乳酪前邊啃著，聽著門
外的水溝所發出的嘩嘩水聲，一付很滿足的樣子。
LONG);
    set("exits",([
        "wiz":"/d/wiz/hall1",
        "west"   : __DIR__"workroom2",
     ]));
    set("light", 1);
    setup();
}
