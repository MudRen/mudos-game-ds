#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"龍脊峰-東北邊"NOR);
 set("long",@LONG
你費盡了千辛萬苦終於爬上了龍脊峰, 只見這裡的土壤
竟然是紅色的! 而龍脊峰是附近最崎嶇的山, 山上並沒有明
顯的道路供你行走, 看來只能用爬(climb)的了!
LONG
    );
set("no_clean_up",0);
set("outdoors","land");
 setup();
}

void init()
{
        add_action("do_climb","climb");
}
int do_climb(string arg)
{
        object me,where1,where2;
        string a;
        me = this_player();
        where1= load_object(__DIR__"ten31.c");
        if( me->is_busy() )
                return notify_fail("你還在忙！\n");
        if( me->is_fighting() )
                return notify_fail("你還在戰鬥中，沒有空去做這種事！\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("指令格式： climb <方向> .\n");
        if( a!="west" )
                return notify_fail("這個方向你爬不過去\n");
     if (a = "west")
    {
        message_vision(HIW"$N從山壁上沿著西邊戰戰兢兢的爬去....。\n"NOR,me);
        me->move(where1);
    }
        return 1;
}
