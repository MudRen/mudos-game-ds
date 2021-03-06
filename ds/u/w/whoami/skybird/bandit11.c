#include <ansi.h>
#include <room.h>
inherit ROOM; 
void create()
{
 set("short","會議廳");
 set("long",@LONG
你進來到這就感覺到一股肅殺的氣息, 在你的眼前有一張
大椅子﹐上面鋪著黑色的熊皮. 這把大椅子的兩側各有一把鋪
著虎皮的椅子. 想必這就是討論一切計劃的會議廳了, 那麼在
你眼前的人一定就是這個山寨的寨主了.
LONG);
 set("exits",(["southwest":__DIR__"bandit10", 
    ])); 
 set("objects", ([__DIR__"npc/wen_tzyy_ian" : 1,
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();

}

void init()
{
    object me=this_player(),ob=this_object();  
    ::init();

    if( !me->query_temp("assassinate") ) return;
    tell_object(me,"這裡的人似乎都沒發現你偷偷摸摸的走了過來•\n"); 
    add_action("do_assassinate","assassinate");
    call_out("ass",2);
}

void ass()
{
    object env,wp,me=this_player(),ob=this_object();
    env = environment(me);
    
    if( env != ob ) return;
    tell_object(me,"山賊大頭目聞紫煙現在毫無防備的背對著你，看來這是一個暗殺(assassinate)她的好機會•\n");
    return; 
}

void do_assassinate()
{
    object target,wp,me=this_player(),ob=this_object();
    string arg;  
    if( !me->query_temp("assassinate") ) return; 
//    if (!target=present(arg, environment(me))) return;
    target = find_living("Wen_Tzyy_Ian");
    message_vision("\t\n$N偷偷摸摸朝$n的背後接近……\n",me,target);
    message_vision("\t$N隨地撿起了一把武器，隨即朝$n的要害處攻了過去！！\n",me,target);
    message_vision("\t\t$n被$N攻的措手不及，就這樣死了•\n\n",me,target);
    target->set_temp("temp/death_type",HIR"[死於暗殺]"NOR); 
    target->die(); 
    return 0;
} 

void door_open()
{
    if( this_object()->query("exits/enter") ) return;
    this_object()->add("exits",(["enter":__DIR__"bandit14"]));
    write(WHT"\n聞紫煙一死，她身後的石門隨即開起了……\n"NOR);
    call_out("door_closed",30); 
    return;
}

void door_closed()
{
   this_object()->delete("exits/enter");
   tell_room(this_object(), HIW"石門『碰』的一聲，突然被關上了•\n"NOR);
 
 //  write(HIW"石門『碰』的一聲，突然被關上了•\n"NOR);
   __DIR__"bandit14"->door_closed();
   return;    
}

