#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
 "\n$n�H�j�T�ת����D�A�a�ۻL���׹L$N�������C\n"NOR,
 "\n$n"HIY"���}�B��A��a�@��A�@�ѱj�j���O�q�A�ϱo�a�W�Цǥ|�_�A�ϱo$N�����D�q��U��C\n"NOR,
 "\n$n"HIG"�ĦV�e�h�A�P$N������W�A�B�@�@�ƸѤF$N�������C\n"NOR,
 "\n$n"HIC"����u���_���K�ߡA�w�פU$N�������o�@�L�l�ˡC\n"NOR,
});

int exert(object me, object target, string arg)
{
        string msg;

        if(arg=="off" )
        {
                if( me->query_skill_mapped("dodge")!="uangoo-steps")
                        return notify_fail("�A�èS���ϥΡi���j�B�j�C\n");
                me->map_skill("dodge");
                me->reset_action();
                message_vision("\n"HIR"$N�w�w���C�B�U�ӡC\n"NOR,me);
                write("�i���j�B�j�w�����C\n");
                return 1;
        }

        if(me->query_skill("dodge")<5) return notify_fail("�A�����\\��¦�����L�k�ϥΡi���j�B�j�C\n");
        if(me->query_skill_mapped("dodge")=="uangoo-steps")
                return notify_fail("�A�w�g�b�ϥΡi���j�B�j�C\n");
        if(me->query("ap")<10 || me->query("hp")<50) return notify_fail("�A�ثe�����p�L�k�ϥΡi���j�B�j�C\n");

        if(!me->skill_active( "uangoo-steps",(: call_other, __FILE__, "delay", me :), 10))
          return notify_fail("�A���ʧ@�٨S�����C\n");

        me->map_skill("dodge", "uangoo-steps");
        me->reset_action();
        
        message_vision("\n"HIC"$N���}���I�A�ϥX�i���j�B�j�A���ʤF�Ů𤤪��L�ɤl���ʡC\n"NOR,me);
        me->receive_damage("ap",random(10));
        me->start_busy(1);
        return 1;
}

void delay(object me)
{
        if(!me) return;
        
        if(me->query_skill_mapped("dodge")!="uangoo-steps")
        {
                 //remove_call_out("delay");
                 return;
        }   
        
        if(me->query("ap")<10)
        {
                me->map_skill("dodge");
                me->reset_action();
                message_vision("\n"HIR"$N�w�w���C�B�U�ӡC\n"NOR,me);
                tell_object(me,"�A�ثe�����A�L�k�~��ϥΡi���j�B�j�C\n");
                //remove_call_out("delay");
                return ;
        }
      if(me->is_fighting()) me->receive_damage("ap",2);
      me->skill_active( "uangoo-steps",(: call_other, __FILE__, "delay", me :), 10);
}

int valid_learn(object me) {    return 1;       }
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
void superpower(object me)
{
     int i,damage;
     object target;
     string *limbs;


    if( environment(me) != environment(target) ) return;
     if(!me->is_fighting()) return;

message_vision(HIG"$N�E���j�q�u��A�e�Ω�x�e�A�����X�Q�ө�A�@���u��y�B�ʩ�Ť��C\n"NOR,me);
     for (i=0;i<=4;i++)
     {
       damage=30+random(20);
       limbs = target->query("limbs");
       message_vision(HIR"������V$n��"+limbs[random(sizeof(limbs))]+"�C"NOR,me,target);
           switch( random(33) ) {
           case 0:
               message_vision(HIW"$n���P�@�D�A���}�F����!!�C\n"NOR,me,target);
               break;
           case 1:
               message_vision(HIW"$n���ߧA�������A�ɤF�U��\n"NOR,me,target);
               break;
           case 2:
               message_vision(HIW"$n���P�@�{�A�׶}�F�����C\n"NOR,me,target);
               break;
           case 3:
               message_vision(HIW"$n���P�@���A�{�}�F�����C\n"NOR,me,target);
               break;
           default:
               message_vision(HIR"$n���G����e�ҥ��������H�ʧ����A���n���z�I�I"NOR,me,target);
               target->receive_damage("hp",damage);
             if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                     tell_object(me,HIY"("+damage+")"NOR"\n");
             COMBAT_D->report_status(target);         //���target���A
             if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                     tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp") +")");
            if(wizardp(me) && me->query("env/debug")) 
                     tell_object(me,"  �y��"+damage+"�I�ˮ`!!\n"); 
               me->receive_damage("ap",15+random(6));
               break;
           }
     }
     me->delete_temp("uangoo-steps/ball");
}

int practice_skill(object me) { return 1; }
int valid_learn(object me)    { return 1; }

