// QC: Luky 1999.10.16 14:39
//update -By tmr-  2000/3/4

#include <ansi.h>

inherit SKILL;

void delay(object me,int cost);

int exert(object me, object target, string arg)
{
        int sk,power,hpower,bagi_power;
        string sp;
        sk=me->query_skill("horse-steps");
                bagi_power=me->query_temp("exert_mark/bagi-power"); //��� query �B��,�é���ק�
               
                switch(arg)
                {
        //�I�Y�l
                case "down-power":
                if(sk<30) 
                        return notify_fail("�A���ϰ���¦�����A�L�k���E�I�Y�l�C\n");
                if(me->query("ap") < 15 )
                        return notify_fail("�A�����l�������E�I�Y�l�C\n");
                if(bagi_power >= sk ) 
                        return notify_fail("�A�餺���K����l�w�K�M�����F�C\n");
                        power=5;
                        me->receive_damage("ap",5);
                sp=HIW"$N���B�@���A�N�����l�D�����U�I�a���G����U����C\n" NOR;
     me->start_busy(2);
                break;
        //�Q�r�l
                case "ten-power":
                if(sk<60) 
                        return notify_fail("�A���ϰ���¦�����A�L�k���E�Q�r�l�C\n");
                if(me->query("ap") < 30 )
                        return notify_fail("�A�����l�������E�Q�r�l�C\n");
                if(bagi_power >= sk ) 
                        return notify_fail("�A�餺���K����l�w�K�M�����F�C\n");
                          power=15;
                        me->receive_damage("ap",10);
            sp=HIW"$N�N�����l�D�V�W�B�U�B���B�k�|�Ӥ�V�e�Q�r�B�@�C\n" NOR;
           me->start_busy(2);
                break;
        //�񵷫l
                case "twine-power":
                if(sk<95) 
                        return notify_fail("�A���ϰ���¦�����A�L�k���E�񵷫l�C\n");
                if(me->query("ap") < 50 )
                          return notify_fail("�A�����l�������E�񵷫l�C\n");
                if(bagi_power >= sk ) 
                        return notify_fail("�A�餺���K����l�w�K�M�����F�C\n");
                        power=30;
                        me->receive_damage("ap",15);
                sp=HIW"$N�N��������l����B����b�餺�`�������C\n" NOR;
           me->start_busy(2);
                break;
        case "power":
                if(bagi_power < 10) sp="�Aı�o�餺�ſ������A�@�I�l�D�]�S���C";
                else if(bagi_power < 20) sp="�A�����餺���K���l�D���b�Q�ܦʨӤ��ơC";
                else if(bagi_power < 30) sp="�A�����餺���K���l�D���b�G�ʨӤ��ơC";
                else if(bagi_power < 40) sp="�A�����餺���K���l�D���b�T�ʨӤ��ơC";
                else if(bagi_power < 50) sp="�A�����餺���K���l�D���b�|�ʨӤ��ơC";
                else if(bagi_power < 60) sp="�A�����餺���K���l�D���b���ʨӤ��ơC";
                else if(bagi_power < 70) sp="�A�����餺���K���l�D���b���ʨӤ��ơC";
                else if(bagi_power < 80) sp="�A�����餺���K���l�D���b�C�ʨӤ��ơC";
                else if(bagi_power < 90) sp="�A�����餺���K���l�D���b�K�ʨӤ��ơC";
                else if(bagi_power < 98) sp="�A�����餺���K���l�D���b�E�ʨӤ��ơC";
                else sp="�Aı�o�餺��l�R�K�b�ˡA���H����C";
                write(sp+"\n");
                return 1;
                default:
                        return notify_fail("�ثe��down-power,ten-power,twine-power,power ���\\��\n");
                }
                hpower=power;
                message_vision(sp,me);
                me->add_temp("exert_mark/bagi-power",hpower);
                return 1;
}

int valid_learn(object me) { return 1; }
int practice_skill(object me) { return 1; }

