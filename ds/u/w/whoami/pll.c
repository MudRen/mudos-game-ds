#include <ansi.h> 

inherit F_CLEAN_UP; 

int main(string arg) 
{ 
    object me=this_player();
    int me_force;
    me_force=me->query("max_force"); 
    if(me->query_temp("used_double")==1) return notify_fail("你正在使用。\n");
    if(me->query->skill("force") > 120) return notify_fail("你的『內功\心法』未到 120 ，故不能使用此技。\n"); 
    {
    message_vision(HIC"\n$N釋放出大量氣勁！再瞬間作收！一股巨能竄通奇筋八脈！內力急為大增！\n"NOR,me); 
    me->me_force*2; 
    me->add_temp("used_double",1);
    call_out("stop_add",300,me);  // 5分鐘
    }
    return 1;
}
void stop_add()
{   
     object me=this_player();
     int me_force; 
     me_force=me->query("max_force");  
     me->delete_temp("used_double",1); 
     me->me_force/2; 
     message_vision(HIW"+me->query_name(1)+"的身體突然放出一股能量，漸漸散去••\n"NOR,me);
     return;
}
int help (object me)
{
        write(@HELP
指令格式 : double
 
能讓內力大增的技倆。
 
HELP
);
        return 1;
}        

