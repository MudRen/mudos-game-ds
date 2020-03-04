#include <ansi.h>

inherit SKILL;

void delay(object me,int cost);

int exert(object me, object target, string arg)
{
        int sk,power,hpower;
        string sp;
        sk=me->query_skill("horse-steps");
        if(arg=="off" )
        {
                if(!me->query_temp("is_busy/horse-steps")) return notify_fail("�A�èS���b�ϰ��a....\n");
                message_vision(HIB "$N�`�I�@�f��A���_���ӵ����F�ϰ��C\n"NOR,me);
                me->delete_temp("is_busy/horse-steps");
                return 1;
        }

if (!arg)
{
        if(me->is_ghost() ) return notify_fail("�A�O���C�A���Ӫ��}...:P\n");
        if(me->is_fighting() ) return notify_fail("�A���b���[���A�S���Ųϰ��a..\n");
        if(me->is_busy() ) return notify_fail("�A�����ۡA�S���Ű���L�ơC\n");
        
        if(me->query("hp")<10 || me->query("ap")<10 )
                return notify_fail("�A�{�b�����骬�A���١C\n");

        if( sizeof(me->query_temp("is_busy")) ) return notify_fail("�A�{�b���b���C\n");

        // �`�N�o��!! 
        //
        if(!me->skill_active( "hosre-steps",(: call_other, __FILE__, "delay", me ,5:), 3))
        return notify_fail("�A�����ϰ����ʧ@�٨S�����C\n");
        message_vision(HIW"$N�ߨ������B��⳻�V�B�G�إ����B���[�����A�ϰ_�F�K�����B�C\n"NOR,me);
        me->receive_damage("ap", 5);
        me->receive_damage("hp", 5);
        me->set_temp("is_busy/horse-steps","�A���b�m�ϰ����ಾ�ʡC");
        me->start_busy(3);
        }
else
{
        switch(arg)
        {
//�I�Y�l
        case "down-power":
        if(sk<30) 
                return notify_fail("�A���ϰ���¦�����A�L�k���E�I�Y�l�C\n");
        if(me->query("ap") < 50 )
                return notify_fail("�A�����l�������E�I�Y�l�C\n");
        if(me->query("bagi-power") >= sk*5 ) 
                return notify_fail("�A�餺���K����l�w�K�M�����F�C\n");
                power=5;
                me->receive_damage("ap",50);
        sp=HIW"$N���B�@���A�N�����l�D�����U�I�a���G����U����C\n" NOR;
        break;
//�Q�r�l
        case "ten-power":
        if(sk<60) 
                return notify_fail("�A���ϰ���¦�����A�L�k���E�Q�r�l�C\n");
        if(me->query("ap") < 100 )
                return notify_fail("�A�����l�������E�Q�r�l�C\n");
        if(me->query("bagi-power") >= sk*7 ) 
                return notify_fail("�A�餺���K����l�w�K�M�����F�C\n");
                  power=12;
                me->receive_damage("ap",100);
        sp=HIW"$N�N�����l�D�V�W�B�U�B���U�|�Ӥ�V�e�Q�r�B�@�C\n" NOR;
        break;
//�񵷫l
        case "twine-power":
        if(sk<95) 
                return notify_fail("�A���ϰ���¦�����A�L�k���E�񵷫l�C\n");
        if(me->query("ap") < 200 )
                return notify_fail("�A�����l�������E���l�C\n");
        if(me->query("bagi-power") >= sk*10 ) 
                return notify_fail("�A�餺���K����l�w�K�M�����F�C\n");
                power=25;
                me->receive_damage("ap",200);
        sp=HIW"$N�N��������l����B����b�餺�`�������C\n" NOR;
        break;
case "power":
        if(me->query("bagi-power") < 10) sp="�Aı�o�餺�ſ������A�@�I�l�D�]�S���C";
        else if(me->query("bagi-power") < 150) sp="�A�����餺���K���l�D���b�Q�ܦʨӤ��ơC";
        else if(me->query("bagi-power") < 250) sp="�A�����餺���K���l�D���b�G�ʨӤ��ơC";
        else if(me->query("bagi-power") < 350) sp="�A�����餺���K���l�D���b�T�ʨӤ��ơC";
        else if(me->query("bagi-power") < 450) sp="�A�����餺���K���l�D���b�|�ʨӤ��ơC";
        else if(me->query("bagi-power") < 550) sp="�A�����餺���K���l�D���b���ʨӤ��ơC";
        else if(me->query("bagi-power") < 650) sp="�A�����餺���K���l�D���b���ʨӤ��ơC";
        else if(me->query("bagi-power") < 750) sp="�A�����餺���K���l�D���b�C�ʨӤ��ơC";
        else if(me->query("bagi-power") < 850) sp="�A�����餺���K���l�D���b�K�ʨӤ��ơC";
        else if(me->query("bagi-power") < 950) sp="�A�����餺���K���l�D���b�E�ʨӤ��ơC";
        else                                   sp="�Aı�o�餺��l�R�K�b�ˡA���H����C";
        return notify_fail( sp+"\n" );
        default:
                return notify_fail("�S���o�ثl�D�C\n");
        }
        me->start_busy(2);
        hpower=power*10;
        message_vision(sp,me);
        me->add("bagi-power",hpower);
        return 1;
}
        return 1;
}

void delay(object me,int cost)
{
        if(!me) return;
        if(!me->query_temp("is_busy/horse-steps") )     return;
        if(me->query("ap") <= cost || me->query("hp") <= cost || me->is_fighting())
        {
                message_vision(HIB "$N�`�I�@�f��A���_���ӵ����F�ϰ��C\n"NOR,me);
                me->delete_temp("is_busy/horse-steps");
                return ;
        }
        me->receive_damage("ap",cost);
        me->receive_damage("hp",cost);
        me->improve_skill("horse-steps",1 + random(1+me->query_int()/4) + random(1+me->query_con()/4) );  
        // �`�N�o��!! 
        // 
        me->skill_active( "hosre-steps",(: call_other, __FILE__, "delay", me ,cost:), 3);
}

int valid_learn(object me) { return 1; }
int practice_skill(object me) { return 1; }


