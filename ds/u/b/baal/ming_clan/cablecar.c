#include <ansi.h>
#include <path.h>

inherit ROOM;

void create()
{
 set("short", "明教吊車乘車處");
 set("long", @LONG

(等待CCKK,RICHAN提供資料中)

LONG
        );
        set("outdoors","land");
        set("stroom",1); //這樣就不會清掉這裡的東西.也不會再生 (特殊情況才用)
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "south" : "/open/world1/tmr/bagi/rift",
 ]));
 set("no_clean_up", 0);
        setup();
}

int valid_leave(object me, string dir)
{
        if( dir=="south" && !objectp(present("ming plate",me)) && me->query("club/name")!="明教" )
{
        return notify_fail("你不是明教的幫眾，不能進入這專屬他們的地方。\n");
        return ::valid_leave(me, dir);
}
        if( dir=="south" && me->query_temp("killer") )
{
        return notify_fail("天上傳來一個幽幽的聲音: $N, 因為你剛剛殺了人所以暫時不能進入教內。\n");
        return ::valid_leave(me, dir);
}
        if( dir=="south" && me->query_temp("invader") )
{
        return notify_fail("天上傳來一個幽幽的聲音: $N, 因為你剛剛攻擊無辜玩家, 所以暫時不能進入教內。\n");
        return ::valid_leave(me, dir);
}
}

