//quanyin-steps �ⶳ�x���\ �[���� -by Tmr-
//PM 03:51 1999/12/11

#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
 "\n$n���D�G" HIC+"�y" NOR+"�L�W�⨬�L�A�@���Ĥ@�k"HIC+"�z"NOR+"�A�������a�׹L���ۡC\n"NOR,
 "\n$n���D�G" HIC+"�y" NOR+"�ڬ�����l�A�������O��"HIC+"�z"NOR+"�A���Y�h�����a�{�F�}�h�C\n"NOR,
 "\n$n���D�G" HIC+"�y" NOR+"�O�|�L�q���A��q�H���k"HIC+"�z"NOR+"�A�L�L�@���A�{�F�}�h�C\n"NOR,
 "\n$n���D�G" HIC+"�y" NOR+"��w���X�@�A�ФƦp�O��"HIC+"�z"NOR+"�A�}�@��A���@���a�׶}�F���ۡC\n"NOR,
 "\n$n���D�G" HIC+"�y" NOR+"�Ҥ@�ߦX�x�A��ť����y"HIC+"�z"NOR+"�A�L�@�ਭ�׶}�F��աC\n"NOR,
 "\n$n���D�G" HIC+"�y" NOR+"�ڵ��d�G�ʡA�ξl�D���"HIC+"�z"NOR+"�A���Τ@�̡A�{�F�}�h�C\n"NOR,
 "\n$n���D�G" HIC+"�y" NOR+"�@�������G�A�������O��"HIC+"�z"NOR+"�A���@�B�B�k�@�B�a�{�F�}�h�C\n"NOR,
 "\n$n���D�G" HIC+"�y" NOR+"�O���D���k�A�h�ͤj�w��"HIC+"�z"NOR+"�A����@��A���Υ����a�{�F�}�h�C\n"NOR,
});




int exert(object me, object target, string arg)
{
        string msg;

        if(arg=="off" )
        {
                if( me->query_skill_mapped("dodge")!="quanyin-steps")
                        return notify_fail("�A�èS���ϥΡi�[���áj�C\n");
                me->map_skill("dodge");
                me->reset_action();
                message_vision("\n"HIW"$N�C�C�����U�F�}�B�C\n"NOR,me);
                write("�ޯ�i�[���áj�w�����C\n");
                return 1;
        }

        if(me->query_skill("dodge")<10) return notify_fail("�A�����\\��¦�����L�k�ϥΡi�[���áj�C\n");
        if(me->query_skill_mapped("dodge")=="quanyin-steps")
                return notify_fail("�A�w�g�b�ϥΡi�[���áj�C\n");
        if(me->query("mp")<10 || me->query("hp")<10) return notify_fail("�A�����骬�p�L�k�ϥΡi�[���áj�C\n");
        me->map_skill("dodge", "quanyin-steps");
        me->reset_action();
          message_vision("\n"HIW"$N�ߪŷN�R�A����L�СA�}�l�I�i�i�[���áj�C\n"NOR,me);
        me->receive_damage("mp",3);
        me->receive_damage("ap",3);
        me->start_busy(1);
        me->skill_active( "quanyin-steps",(: call_other, __FILE__, "delay", me :), 10);
        return 1;
}
void delay(object me)
{
        if(!me) return;
              if(me->query_skill_mapped("dodge")!="quanhin-steps")
                {
                 remove_call_out("delay");
                 return;
                }   
       if(me->query("mp")<3 && me->query("ap")<3)
        {
                me->map_skill("dodge");
                me->reset_action();
                message_vision("\n"HIW"$N�C�C�����U�F�}�B�C\n"NOR,me);
                tell_object(me,"�A����O�����L�k�~��ϥΡi�[���áj�C\n");
                remove_call_out("delay");
                return ;
        }
        me->receive_damage("mp",3);
        me->receive_damage("ap",3);
        me->skill_active( "quanyin-steps",(: call_other, __FILE__, "delay", me :), 10);
}

int valid_learn(object me) {    return 1;       }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me) { return 1; }



