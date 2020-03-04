#include <ansi.h>
inherit SSERVER;

int zombie_heal(object ob);
int zombie_kill(object ob);
void zombie_bite();

mapping *s_action = ({   // �H���ʧ@
        ([
          "action": "$N���e�@�B�A�������k�s�X����$n$l",
        "damage":                20,
        "attact_type":  "bio",  
        "damage_type":  "���",
        ]),
        ([
          "action": "$N�k�����M�@�̡A�E�O���V$n$l",
        "damage":                25,
        "attact_type":  "bio",  
        "damage_type":  "����",
        ]),
        ([
        "action": "$N�~�a�����V��$n��$l�n�`�P�ɳs��",
        "damage":                25,
        "attact_type":  "bio",  
        "damage_type":  "���",
        ]),
        ([
          "action": "$N���u�@�_�A�k����X�A�����~�a�Ѱ�����X���V$n$l",
        "damage":                40,
        "attact_type":  "bio",  
        "damage_type":  "���",
        ]),

        ([
          "action": "$N�n�n�̮̱i�L�K��$n��$l�r�h�A��$n��y����",
        "damage":                40,
        "attact_type":  "bio",  
        "damage_type":  "�r��",
        ]),

        ([
   "action": "$N���زu��A���M�V$n��$l��F�X�U�I",
        "damage":                25,
        "attact_type":  "bio",  
        "damage_type":  "���",
        ]),
});

int zombie_heal(object ob)  // �ɦ�
{
        if( ob->is_busy() )     return 1;
         if( ob->query("hp") > ob->query("max_hp")/2 ) return 1;
        message_vision( CYN"\n$N"+CYN+"�R�q�@�n�A���M���}�}����ǤJ...\n" NOR,ob);
        ob->receive_heal("hp",ob->query("max_hp")/15 );
        ob->start_busy(1);
        return 1;
}

int zombie_kill(object ob)  // �L�ͤ��S��
{               object target = offensive_target(ob);  // �ĤH
        if(ob->is_busy() ) return 1;
        switch(random(4) ) {
        case 0:
                message_vision(HIY "\n""        $N���M�����s�X�A�s�����X��U...\n" NOR,ob);
                ob->attack();
                ob->attack();
        break;
        case 1:
    message_vision(HIY "\n""         $N���M�@�}�r��A�O�A�u�o���U���Ψ���...\n" NOR,ob);
                target->start_busy(1);
        break;
        case 2:
                message_vision(HIG "\n      $N�l�F�@�f����A�r�O���X�@��...\n" NOR,ob);
                ob->start_busy(1);
                target->start_busy(1);                           target->receive_damage("hp",180+random(ob->query_str()));   
                COMBAT_D->report_status(target);        
        break;
        }
        return 1;
}

void zombie_bite()
{
        object me,target;
        me=this_player();
        target = offensive_target(me);  // �ĤH
        if(!me || !target) return;
        if(me->is_busy()) return;
        message_vision(HIR"\n$N�@�n�j�q�A�����u�|��v���뤤$n" NOR,me,target);
        target->receive_damage("hp",50+random(me->query_str()),target);
        COMBAT_D->report_status(target);

}










