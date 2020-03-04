#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"龍脊峰-西南邊"NOR);
 set("long",@LONG
這裡就是龍脊峰的西南邊了, 你可以看到山旁有一座若
隱若現的建築物, 不過很明顯的絕對沒有路通向那裡, 有的
指示一片紅土, 除了一條懸在空中的鋼索以外, 就什麼都沒
有了, 看來這裡也只能用爬(climb)的....
LONG
    );

set("no_clean_up",0);set("item_desc",([
        "建築物":HIG"從它的燕角, 飛簷來看, 大概是一座神殿之類的...\n"NOR,
       "鋼索":HIG"這條鋼索讓你想不到世上還有比它更破舊的東西, 使得你一點都不會想去踏上去(take on)...\n"NOR,
    ]));
set("outdoors","land");
 setup();
}

void init()
{
        add_action("do_climb","climb");
     add_action("do_take","take");
}
int do_climb(string arg)
{
        object me,where1,where;
        string a;
        me = this_player();
        where1=load_object(__DIR__"ten28.c");
      where = load_object(__DIR__"ten33.c");
        if( me->is_busy() )
                return notify_fail("你還在忙！\n");
        if( me->is_fighting() )
                return notify_fail("你還在戰鬥中，沒有空去做這種事！\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
            
    return notify_fail("指令格式： climb <方向> .\n");
        if( a!="east" )
                return notify_fail("這個方向你爬不過去\n");
     if (a = "east")
    {
        message_vision(HIW"$N從山壁上沿著東邊戰戰兢兢的爬去....。\n"NOR,me);
        me->move(where1);
    }
        return 1;
}

int do_take(string arg)
{
        object me,where1,where;
        string a;
        int x;
        me = this_player();
        x = me->query_skill("dodge") / 2+ me->query("dex") / 2 +random(20);
        where1=load_object(__DIR__"ten33.c");
      where = load_object(__DIR__"ten29.c");
        if( me->is_busy() )
                return notify_fail("你還在忙！\n");
        if( me->is_fighting() )
                return notify_fail("你還在戰鬥中，沒有空去做這種事！\n");
        if( !arg || sscanf(arg, "on %s", a )!=1 )
                return notify_fail("指令格式： take on <物品> .\n");
        if( a!="鋼索" )
                return notify_fail("這個方向你爬不過去\n");
        message_vision(HIW"$N深吸一口氣, 勇敢的飛身往鋼索跳去。\n"NOR,me);
    if (x < 33)
    {
        tell_object(me,HIR"你一個失足, 瞬間有如重石般往下墜去!!\n"NOR);    
        me->move(where);
    }
    else
    {
        tell_object(me,HIW"你帥氣的一個轉身, 恰好落在鋼索的中間部份, 但也嚇出了一身冷汗!\n"NOR);    
        me->move(where1);
    }
        return 1;
}
