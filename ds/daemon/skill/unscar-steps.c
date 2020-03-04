//�����v ���\ �񳷵L�� (unscar-steps)

#include <ansi.h>
inherit SKILL;
inherit SSERVER;


string *dodge_msg = ({
        "$n�@��"GRN"�u�׿P�k�L�h�v"NOR"�A����p�B�P��L�몽�ƥX�V�l�C\n",
        "$n�@��"MAG"�u�ὺ�����ߡv"NOR"�A���M�@�s�y�A������ŦӦ�A�y�ɰ{�L�F$N����F��աC\n",
        "$n�@��"HIY"�u�����ָ��S�v"NOR"�A�����ʡA�⤣��A�@�಴���K¶��F$N������C\n",
        "$n�@��"GRN"�u�C���˪᯻�v"NOR"�A�@�ਭ���A�|���K���ưʵ۵L�ƭ�$n�����v�A�O$N�⨬�L���C\n",
        "$n�@��"HIW"�u�����I���R�v"NOR"�A���S�@�ءA�����Ƭ��@�D�ռv�A�իզa�q$N�Y���Ƹ��C\n",
        "$n�@��"MAG"�u���F�üv�ܡv"NOR"�A���ΰ����q$N�����e�ƹL�A���v�@�ϡA�t�x�����C\n"
});

int exert(object me, object target, string arg)
{

    if(arg=="off" )
    {
        if( me->query_skill_mapped("dodge")!="unscar-steps")
            return notify_fail("�A�èS���ϥΡi�񳷵L���j�C\n");
        me->map_skill("dodge");
        me->reset_action();
        message_vision("\n"HIW"$N�C�C�����U�F�}�B�C\n"NOR,me);
        write("�ޯ�i�񳷵L���j�w�����C\n");
        return 1;
    }

    if(me->query_skill("dodge")<20) return notify_fail("�A�����\\��¦�����L�k�ϥΡi�񳷵L���j�C\n");
    if(me->query_skill_mapped("dodge")=="unscar-steps")
        return notify_fail("�A�w�g�b�ϥΡi�񳷵L���j�C\n");
    if(me->query("ap")<10 || me->query("hp")<10) return notify_fail("�A�ثe�����骬�p�L�k�ϥΡi�񳷵L���j�C\n");

if(!me->skill_active( "unscar-steps",(: call_other, __FILE__, "delay", me :), 10))
        return notify_fail("�A���񳷵L�����۰ʧ@�٨S�����C\n");

    me->map_skill("dodge", "unscar-steps");
    me->reset_action();

    message_vision(HIW "$N���S�@�ءA�����Ƭ��@�D�ռv�A�}�l�I�i�i�񳷵L���j�C\n"NOR,me);
    me->receive_damage("ap",2);
    me->start_busy(1);
    return 1;
}

void delay(object me)
{
    if(!me) return;

    if(me->query_skill_mapped("dodge")!="unscar-steps")
    {
        //remove_call_out("delay");
        return;
    }

    if(me->query("ap")<2)
    {
        me->map_skill("dodge");
        me->reset_action();
        message_vision("\n"HIW"$N�C�C�����U�F�}�B�C\n"NOR,me);
        tell_object(me,"�A����O�����L�k�~��ϥΡi�񳷵L���j�C\n");
        //remove_call_out("delay");
        return ;
    }
    if(me->is_fighting()) me->receive_damage("ap",2);
me->skill_active( "unscar-steps",(: call_other, __FILE__, "delay", me :), 10);
}

int valid_learn(object me) {    return 1;       }

void perform_dodge_attack(object me)
{
    int sk, i;
    object *targets;

    if(!me) return;
    targets = me->query_enemy();
    sk = me->query_skill("unscar-steps");
    if( sk >= 50 
        && me->query("ap") > 50 
         &&  (sk/10) - 4 > random(100) ) {       // �̰� 10% ���o�ʾ��v
                me->receive_damage("ap", 25);
                message_vision(HIC"\n���]�\\�b�b�������ɦܷ����A�H$N"HIC"�����ߪ����@�V�����A�����M�W���U�h���F�@�ӵL���`��C\n"NOR, me);
                for(i=0;i<sizeof(targets);i++) {
                        if( !environment(me) ) continue;
                        if( !targets[i] || !environment(targets[i]) ) continue;
                        if(environment(me) != environment(targets[i]) ) continue;
                        if( targets[i]->is_busy()) continue;
                        message_vision(CYN"$n"CYN"ı�o���䪺�Ŷ��K�p�P�򳴤@��A�L�O�i�o�C\n"NOR,me, targets[i]);
                        targets[i]->start_busy(1);
                }
        }
}

string query_dodge_msg(string limb)
{
    perform_dodge_attack( offensive_target(this_player()));
    return dodge_msg[random(sizeof(dodge_msg))];
}


int practice_skill(object me) { return 1; }

int improve_limite(object ob)
{
    return 70 + ob->query_dex();
}
