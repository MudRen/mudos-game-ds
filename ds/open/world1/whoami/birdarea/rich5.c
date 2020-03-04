#include <ansi.h>
#include <room.h>
inherit ROOM; 
void create()
{
 set("short","富宅大廳");
 set("long",@LONG
你來到了獵狐村首屈一指的富豪的家裡, 這裡的佈置和陳設
沒有一樣不是貴的嚇人的, 看來住在這的真的不是等閒之輩, 在
你眼前的一位老翁似乎就是這裡的主人了
LONG);

 set("objects",([ __DIR__"npc/richman" : 1, ]));
 set("exits",([ "south":__DIR__"rich4", ]));  
 set("hide_exits", ([ "east" : __DIR__"rich6.c", ]));

 setup();
}        

void init()
{
     object me = this_player();
     if( me->query_skill("perception") > 15 ){
         me->set_temp("can_east",1);
         tell_object(me,HIW"你眼角的餘光一撇，似乎發現了一條通往東邊的隱密小路。\n"NOR); 
         }
}

int valid_leave(object me, string dir)
{
       if( dir=="east" && me->query_skill("perception") < 15 )
                return notify_fail("這個方向沒有出路。\n");
        return ::valid_leave(me, dir);
}

