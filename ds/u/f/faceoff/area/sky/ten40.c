#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"邪桫神廟"NOR);
 set("long",@LONG
你一進來這裡, 就感到渾身不對勁, 一和神殿外出世的
氣氛比較, 這裡簡直是陰森的不能在陰森了, 只有神龕前面
兩隻青森的長明燈燭光亮著, 隱約反射著神龕上的凹陷....
LONG
    );
 set("exits",([   "out":__DIR__"ten39",
    ]));
 set("objects", ([    __DIR__"npc/star_old_man" : 1,
]));

set("item_desc",([
        "凹陷" : HIG"你往凹陷一看, 發現有一個腿型物體隱隱反射燭光....\n"NOR,
      "腿型物體" : HIG"你再靠近一看, 這根本就是一個護腿嘛! 把它撿(take)起來也不會有人發現吧....\n"NOR,
]));
set("no_clean_up",0);
set("light",1);
 setup();
}

void init()
{
        add_action("do_take","take");
}
int do_take(string arg)
{
        object me, p;
       string a;
        object room = environment(this_player());
        me = this_player();
            if( me->is_busy() )
                return notify_fail("你還在忙！\n");
        if( me->is_fighting() )
                return notify_fail("你還在戰鬥中，沒有空去做這種事！\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("指令格式： take <物品> .\n");
   if( a!="腿型物體" )
                return notify_fail("你眼睛瞎了嗎? 這裡沒有這種東西!\n");
        if(room->query("take_leg") == 0)
        {
                message_vision(HIC"$N一個飛撲, 將護腿從凹陷中拿了出來....。\n"NOR  ,me);
                p=new("/u/f/faceoff/area/sky/eq/baal_leg.c");
                p->move(this_player());
                room->set("take_leg",1);
                room->set("long", @LONG
你一進來這裡, 就感到渾身不對勁, 一和神殿外出世的
氣氛比較, 這裡簡直是陰森的不能在陰森了, 只有神龕前面
兩隻青森的長明燈燭光亮著.
LONG
                );
                delete("item_desc");
        }
        else
        {
                tell_object(me,HIR"這裡空無一物！\n"NOR);
        }
        return 1;
}
