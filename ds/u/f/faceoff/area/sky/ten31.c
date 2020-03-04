#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"龍脊峰-西北邊"NOR);
 set("long",@LONG
你到了龍脊峰的西北邊, 這裡跟其他地方一樣的崎嶇, 
唯一不一樣的是你的正下方就是東北澤林囉, 一片翠綠的
東北澤林有讓你想跳下去的衝動....
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
        where1= load_object(__DIR__"ten32.c");
        if( me->is_busy() )
                return notify_fail("你還在忙！\n");
        if( me->is_fighting() )
                return notify_fail("你還在戰鬥中，沒有空去做這種事！\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("指令格式： climb <方向> .\n");
        if( a!="south" )
                return notify_fail("這個方向你爬不過去\n");
     if (a = "south")
    {
        message_vision(HIW"$N從山壁上沿著南邊戰戰兢兢的爬去....。\n"NOR,me);
        me->move(where1);
    }
        return 1;
}
