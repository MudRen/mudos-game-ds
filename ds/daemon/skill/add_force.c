#include <ansi.h>
#define SKILL_NAME "���\�ഫ�N"
inherit SKILL;
inherit SSERVER;   
int exert()  { 
    object target,me=this_player();
    int f;     f=me->query("max_ap");   
    if(!me) return 0; 
    if(me->query_temp("used_double")==1) return notify_fail("�A���b�ϥΡC\n");
    if(me->query_skill("force") > 99) 
     {
    message_vision(HIC"\n$N����X�j�q��l�I�A�����@���I�@�ѥ���«�q�_���K�ߡI���O�欰�j�W�I\n"NOR,me); 
    f=f+50+me->query_skill("add_force");   // �򥻭� 50
    me->add_temp("used_double",1);
    call_out("stop_add",300,me);  // 5����
    }  
    else { return notify_fail("�A���y���\\�ߪk�z���� 120 �A�G����ϥΦ��ޡC\n"); }
    return 1;
}
void stop_add()
{   
     object me=this_player();
     int f; 
     f=me->query("max_ap");  
     me->delete_temp("used_double",1); 
     f=f-50-me->query_skill("add_force");   // ��^     message_vision(HIW"+me->query_name(1)+"�������M��X�@�ѯ�q�A�������h�E�E\n"NOR,me);
     return;
}
int help (object me)
{
        write(@HELP
���O�榡 : exert add_force
 
�������O�j�W���ޭǡA�H�ޯ൥�Ū����P�Ӥ��P�C
 
HELP
);
        return 1;
}        

