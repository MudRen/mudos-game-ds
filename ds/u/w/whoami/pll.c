#include <ansi.h> 

inherit F_CLEAN_UP; 

int main(string arg) 
{ 
    object me=this_player();
    int me_force;
    me_force=me->query("max_force"); 
    if(me->query_temp("used_double")==1) return notify_fail("�A���b�ϥΡC\n");
    if(me->query->skill("force") > 120) return notify_fail("�A���y���\\�ߪk�z���� 120 �A�G����ϥΦ��ޡC\n"); 
    {
    message_vision(HIC"\n$N����X�j�q��l�I�A�����@���I�@�ѥ���«�q�_���K�ߡI���O�欰�j�W�I\n"NOR,me); 
    me->me_force*2; 
    me->add_temp("used_double",1);
    call_out("stop_add",300,me);  // 5����
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
     message_vision(HIW"+me->query_name(1)+"�������M��X�@�ѯ�q�A�������h�E�E\n"NOR,me);
     return;
}
int help (object me)
{
        write(@HELP
���O�榡 : double
 
�������O�j�W���ޭǡC
 
HELP
);
        return 1;
}        

