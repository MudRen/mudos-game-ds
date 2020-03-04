#include <ansi.h>
inherit SKILL;
inherit SSERVER;

string *dodge_msg = ({
                         HIR"\n��M$n�����������X����A�����N�@��A�~��$N�����a��$n�C\n"NOR,
                         "\n$n��M���I�ᴡ�F���ͻH�@�˪����ʨ��t�A��$N�L�q�����_�C\n",
                         "\n$n��M���k���몺��İ_�ӡA��$N�X�⪺�ɶ��j�áA�]���׹L���ۡC\n",
                         "\n$n���W�����A�����Q�۽�ۼΰ}�����ΡA�}�]��_�ۼΰ}���A��$N�L�q�U��C\n",
                         "\n$n���}�@�ޡA���ĤW�ѡA�@��"+HIC+"�i��}�����j"+NOR+"�}�G�����b$N����C\n",
                         "\n��M$n�}�B�ܻ��A�@��"+HIM+"�i����k�u�j"+NOR+"�A�b$N����դ��C���|��C\n",
                         "\n��M$n��C�F�}�B�A���i���h�A��$N�����N�����Y���C\n",
                         "\n�٨����A$n�������o�X���˪����~�A�ʧ@�񥭱`�n�֤W�ƭ��A��$N�����I����$n�@�ڴH��C\n",
                     });

void sp_1(object me, object target)
{
    int sk = me->query_skill("bird-eight"), lv = me->query("level"), consume_ap = 50, BusyTime, tint=target->query_int(), myint=me->query_int();
    if( lv > 25 )
        consume_ap = (4*sk) / lv;
    if( consume_ap > 50 )
        consume_ap = 50;
    BusyTime = sk/33;
    if( !me->is_busy() && !target->is_busy() && (tint) <  (1+random(3))*(myint) && !me->query_temp("bird/sp_hint") )
    {
        message_vision(HIC"$N���ʧ@���M�w�C�A�M�ӥL�����v�o�ۤƸU�d�A�@�p���εL�誺���F�A�O$n�L�k�����C\n"NOR,me,target);
        target -> start_busy(BusyTime);
        me -> receive_damage("ap",consume_ap);
        me -> add_temp("bird/sp_hint", 1);
    }
}

void sp_2(object me, object target)
{
    object *s_target, target_1;
    int x;
    s_target = all_inventory(environment(me));
    if( !me->query_temp("bird/sp_hint") && me->query("quest/bird-eight") && random(150) < (me->query("level")) )
    {
        for(x=0;x<sizeof(s_target);x++)
        {
            if(!s_target[x]->is_fighting(me))
                continue;
            target_1 = s_target[x];
            message_vision(HIC"$N�����l�̵��F�l�K�B���ߪk�����ɰ_�A��Ө��l���y�@��V��e�h�A$n����������������O�H�����W�F�C\n"NOR,me,target);
            if( target->query_temp("weapon") )
            {
                COMBAT_D->do_attack(target,target_1,4);
                COMBAT_D->report_status(target_1);
            }
            else
            {
                COMBAT_D->do_attack(target,target_1,target->query_temp("weapon"),4);
                COMBAT_D->report_status(target_1);
            }
            me -> add_temp("bird/sp_hint", 1);
            me -> receive_damage("ap", 8);
            break;
        }
    }
}

void sp_3(object me, object target)
{
    object weapon = me->query_temp("weapon");
    int x,y,mydex=me->query_dex(),tdex=target->query_dex();
    y = me->query_tec()/4;
    y = 1+random(y);
    if( y > 3)
        y = 3;

    if( weapon->query("skill_type") == "throwing" && mydex > tdex && !me->query_temp("bird/sp_hint") )
    {
        message_vision(HIW"$N���l�Ƭ��H���h���A���$n�ױ׭��_�A���F�@�Ӱ��ת����I�A$N�`�l�@�f��A���L�@�I�A�a�W�F�b�šA���ۨ��l�{�p�b�Ť��Ʀ�@��R�V$n�I\n"NOR, me, target);
        me -> add_temp("bird/sp_hint", 1);
        for(x=0;x<y;x++)
        {
            COMBAT_D->do_attack(me,target,weapon);
            COMBAT_D->report_status(target);
        }
    }
}


int exert(object me, object target, string arg)
{
    string msg;

    int dodge_apply  = me->query_skill("bird-eight"),
                       temp = me->query_temp("bird/temp");

    if(arg=="off" )
    {
        if( me->query_skill_mapped("dodge")!="bird-eight")
            return notify_fail("�A�èS���ϥΡy�F�l�K�B�Z�z�C\n");
        me->map_skill("dodge");
        me->reset_action();
        me->add_temp("apply/dodge",- temp);
        me->delete_temp("bird/dodge_apply");
        message_vision("\n"CYN"$N�������C�C�ର���`���C��A�ӭ쥻���ժ��}�B�]�v���ͽw�C\n"NOR,me);
        write("�ޯ�y�F�l�K�B�Z�z�w�����C\n");
        return 1;
    }

    if(me->query_skill("dodge")<20)
        return notify_fail("�H�A�����\\��¦�L�k�ϥΡy�F�l�K�B�Z�z�C\n");

    //��1. if(me->query_skill_mapped("dodge")=="mirage-steps")
    if(me->query_skill_mapped("dodge")=="bird-eight")  //luky��
        return notify_fail("�A�w�g�b�ϥΡy�F�l�K�B�Z�z�C\n");

    if(me->query("ap")<50 || me->query("hp")<50)
        return notify_fail("�A�����骬�L�k�ϥΡy�F�l�K�B�Z�z�C\n");

if(!me->skill_active( "bird-eight",(: call_other, __FILE__, "delay", me :), 10))
        return notify_fail("�A���F�l�K�B�Z���۰ʧ@�٨S�����C\n");

    if(me->query_skill("sky-throwing")>60)
        dodge_apply += me->query_dex()/4;

    if(me->query("class2") == "skyowl_med")
        dodge_apply = dodge_apply/2;

    if(me->query("class2") == "skyowl_military")
        dodge_apply = dodge_apply*85/100;

    if(!me->query("class2") && me->query("class1") == "skyowl")
        dodge_apply = dodge_apply*4/10;

    dodge_apply = dodge_apply - me->query_skill("sky-dagger")/5;
    if( dodge_apply < 0 )
        dodge_apply = 0;

    // ��2. me->map_skill("dodge", "mirage-steps");
    me->map_skill("dodge", "bird-eight"); //luky ��
    me->reset_action();
    me->add_temp("apply/dodge",dodge_apply);
    me->set_temp("bird/temp",dodge_apply);

    message_vision("\n"HIR"$N��������M�ର�����A�����ĤH���@�|�@�ʡA�ǳƨϥX�ǻ������y�F�l�K�B�Z�z�C\n"NOR,me);
    me->receive_damage("ap",15);
    me->start_busy(1);
    //��3. call_out("delay",10,me);
    return 1;
}

void delay(object me)
{
    int temp = me->query_temp("bird/temp");
    if(!me)
        return;

    if(me->query_skill_mapped("dodge")!="bird-eight")
    {
        //�K. remove_call_out("delay");
        return;
    }

    if(me->query("ap")<50)
    {
        me->map_skill("dodge");
        me->reset_action();
        message_vision("\n"HIW"$N������������_�����`�C��A�ӭ쥻���ժ��}�B�]�v���ͽw�C\n"NOR,me);
        me->add_temp("apply/dodge",- temp);
        me->delete_temp("bird/temp");
        tell_object(me,"�A����O�����L�k�~��ϥΡy�F�l�K�B�Z�z�C\n");
        //�K. remove_call_out("delay");
        return ;
    }
    //    if ( me->is_fighting() ) me->receive_damage("ap",2); //�S�[�԰��P�_
    //��. call_out("delay",10,me);
me->skill_active( "bird-eight",(: call_other, __FILE__, "delay", me :), 10);
}

int valid_learn(object me)
{
    return 1;
}

string query_dodge_msg(string limb, object me, object target)
{
    int sk = me->query_skill("bird-eight");

    if( sk > 95 && me->query("class2") == "skyowl_step" )
        sp_3(me, target);
    if( sk > 80 && me->query("class2") == "skyowl_step" )
        sp_2(me, target);
    if( sk > 60 && me->query("class2") == "skyowl_step" )
        sp_1(me, target);

    me->receive_damage("ap",2);
    me->delete_temp("bird/sp_hint");
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
    return 1;
}

int improve_limite(object me)
{
    int a;
    a=me->query_dex()+me->query_int();
    if(a>100)
        a=100;
    return a;
}


