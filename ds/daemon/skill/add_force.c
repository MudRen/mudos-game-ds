#include <ansi.h>
#define SKILL_NAME "內功轉換術"
inherit SKILL;
inherit SSERVER;   
int exert()  { 
    object target,me=this_player();
    int f;     f=me->query("max_ap");   
    if(!me) return 0; 
    if(me->query_temp("used_double")==1) return notify_fail("你正在使用。\n");
    if(me->query_skill("force") > 99) 
     {
    message_vision(HIC"\n$N釋放出大量氣勁！再瞬間作收！一股巨能竄通奇筋八脈！內力急為大增！\n"NOR,me); 
    f=f+50+me->query_skill("add_force");   // 基本值 50
    me->add_temp("used_double",1);
    call_out("stop_add",300,me);  // 5分鐘
    }  
    else { return notify_fail("你的『內功\心法』未到 120 ，故不能使用此技。\n"); }
    return 1;
}
void stop_add()
{   
     object me=this_player();
     int f; 
     f=me->query("max_ap");  
     me->delete_temp("used_double",1); 
     f=f-50-me->query_skill("add_force");   // 減回     message_vision(HIW"+me->query_name(1)+"的身體突然放出一股能量，漸漸散去••\n"NOR,me);
     return;
}
int help (object me)
{
        write(@HELP
指令格式 : exert add_force
 
能讓內力大增的技倆，隨技能等級的不同而不同。
 
HELP
);
        return 1;
}        

