//���Z�л��\�G�P���g�ܨB   by Acme 1999.12.11
//cp���ª��Qluky say cow....flee..ack
//so sorry

#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
 "\n$n��L���ơA���S���R�A�q�e�׹L���ۡC\n"NOR,
 "\n$n�@��"HIW"�y"HIC"�H�歸��"HIW"�z"NOR"�A��@���D�A�������׹L�F$N�������C\n",
 "\n$n�k�}����a�W�Фg�A�@��"HIW"�y"HIC"�Ъd�B��"HIW"�z"NOR"�u�����ŭ��ǡA�X���׹L���ۡC\n",
 "\n$n�ڶ}�j�B�A��¶��$N�ϥX"HIW"�y"HIC"�K���N�P"HIW"�z"NOR"�A$N�n���Y������A�L�q�ۤ�C\n",
 "\n$n��w�����A���εL�w�A�զp���s�A�C���|��A�����������׹L$N�������C\n",
 "\n$n�@��"HIW"�i"HIG"�y�ûR��"HIW"�j"NOR"�A�u��$n�}�B�p���A���Ʀ��ƤQ�Ӥۼv�A$N�L�q�U��A�b�Y�����C\n",
});

int exert(object me, object target, string arg)
{
        string msg;

        if(arg=="off" )
        {
                if( me->query_skill_mapped("dodge")!="mirage-steps")
                        return notify_fail("�A�èS���ϥΡi�P���g�ܨB�j�C\n");
                me->map_skill("dodge");
                me->reset_action();
                message_vision("\n"HIW"$N�C�C�����U�F�}�B�C\n"NOR,me);
                write("�ޯ�i�P���g�ܨB�j�w�����C\n");
                return 1;
        }

        if(me->query_skill("dodge")<20) return notify_fail("�A�����\\��¦�����L�k�ϥΡi�P���g�ܨB�j�C\n");
        if(me->query_skill_mapped("dodge")=="mirage-steps")
                return notify_fail("�A�w�g�b�ϥΡi�P���g�ܨB�j�C\n");
        if(me->query("ap")<10 || me->query("hp")<10) return notify_fail("�A�ثe�����骬�p�L�k�ϥΡi�P���g�ܨB�j�C\n");

        if(!me->skill_active( "mirage-steps",(: call_other, __FILE__, "delay", me :), 10))
          return notify_fail("�A���P���g�ܨB���۰ʧ@�٨S�����C\n");

        me->map_skill("dodge", "mirage-steps");
        me->reset_action();
        
        message_vision("\n"HIW"$N���v�g���A�}�l�I�i�i�P���g�ܨB�j�A�O�H���N���w�C\n"NOR,me);
        me->receive_damage("ap",2);
        me->start_busy(1);
        return 1;
}

void delay(object me)
{
        if(!me) return;
        
        if(me->query_skill_mapped("dodge")!="mirage-steps")
        {
                 //remove_call_out("delay");
                 return;
        }   
        
        if(me->query("ap")<2)
        {
                me->map_skill("dodge");
                me->reset_action();
                message_vision("\n"HIW"$N�C�C�����U�F�}�B�C\n"NOR,me);
                tell_object(me,"�A����O�����L�k�~��ϥΡi�P���g�ܨB�j�C\n");
                //remove_call_out("delay");
                return ;
        }
      if(me->is_fighting()) me->receive_damage("ap",2);
      me->skill_active( "mirage-steps",(: call_other, __FILE__, "delay", me :), 10);
}

int valid_learn(object me) {    return 1;       }
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me) { return 1; }
int improve_limite(object ob) 
{
        int a;
        a=ob->query_dex();
        a=a+ob->query_int();
        a=a+40;
        if(a>90) a=90;
        return a;
}
