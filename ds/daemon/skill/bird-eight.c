#include <ansi.h>
inherit SKILL;
inherit SSERVER;

string *dodge_msg = ({
                         HIR"\n��M$n�����������X����A�����N�@��A�~��$N�����a��$n�C\n"NOR,
                         "\n$n��M���I�ᴡ�F���ͻH�@�˪����ʨ��t�A��$N�L�q�����_�C\n",
                         "\n$n��M���k���몺��İ_�ӡA��$N�������ɶ��j�áA�]���׹L���ۡC\n",
                         "\n$n���W�����A�����Q�۽�ۼΰ}�����ΡA�}�]��_�ۼΰ}���A��$N�L�q�U��C\n",
                         "\n$n���}�@�ޡA���ĤW�ѡA�@��"+HIC+"�i��}�����j"+NOR+"�}�G�����b$N����C\n",
                         "\n��M$n�}�B�ܻ��A�@��"+HIM+"�i����k�u�j"+NOR+"�A�b$N����դ��C���|��C\n",
                         "\n��M$n��C�F�}�B�A���i���h�A��$N�����N�����Y���C\n",
                         "\n�٨����A$n�������o�X���˪����~�A�ʧ@�񥭱`�n�֤W�ƭ��A��$N�����I����$n�@�ڴH��C\n",
                     });

int exert(object me, object target, string arg)
{

    int temp = me->query_skill("bird-eight"),
               temp2 = me->query_temp("bird/temp");
    if(arg=="off" )
    {
        if( me->query_skill_mapped("dodge")!="bird-eight")
            return notify_fail("�A�èS���ϥΡy�F�l�K�B�Z�z�C\n");
        me->map_skill("dodge");
        me->reset_action();
        me->add_temp("apply/dodge",- temp2);
        me->delete_temp("bird/temp");
        message_vision("\n"CYN"$N�������C�C�ର���`���C��C\n"NOR,me);
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

    // ��2. me->map_skill("dodge", "mirage-steps");
    me->map_skill("dodge", "bird-eight"); //luky ��
    me->reset_action();
    me->add_temp("apply/dodge",temp);
    me->set_temp("bird/temp",temp);

    message_vision("\n"HIR"$N��������M�ର�����A�����ĤH���@�|�@�ʡA�ǳƨϥX�ǻ������y�F�l�K�B�Z�z�C\n"NOR,me);
    me->receive_damage("ap",2);
    me->start_busy(1);
    //��3. call_out("delay",10,me);
    return 1;
}

void delay(object me)
{
    int temp = me->query_temp("bird/temp");
    if(!me) return;

    if(me->query_skill_mapped("dodge")!="bird-eight")
    {
        //�K. remove_call_out("delay");
        return;
    }

    if(me->query("ap")<10)
    {
        me->map_skill("dodge");
        me->reset_action();
        message_vision("\n"HIW"$N������������_�����`�C��F�C\n"NOR,me);
        me->add_temp("apply/dodge",- temp);
        me->delete_temp("bird/temp");
        tell_object(me,"�A����O�����L�k�~��ϥ��F�l�K�B�Z�C\n");
        //�K. remove_call_out("delay");
        return ;
    }
    if ( me->is_fighting() ) me->receive_damage("ap",2); //�S�[�԰��P�_
    //��. call_out("delay",10,me);
me->skill_active( "bird-eight",(: call_other, __FILE__, "delay", me :), 10);
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
    int mysk,mydex,myhp,myap,mydo,mylv;
    object me,target;

    me   = this_player();
    target = offensive_target(me);
    mylv = target->query("level");
    myhp = target->query("hp");
    myap = target->query("ap");
    mysk   = target->query_skill("bird-eight");
    mydo   = target->query_skill("dodge");
    mydex  = target->query("dex");

    if( target->query_temp("use_do") < 1 && !target->is_busy() &&            myap > myhp*2/5 && random(mydex) > mylv && (mysk+mydo)/2 > 60 )
    {
        target->set_temp("use_do",1);
        message_vision(CYN"\n$N"CYN"�_�۪����k��$n"CYN"�������@�ɥ��h�F�즳���`���E\n"NOR,target,me);
        me->start_busy(random(mydex/70+mysk/60));
        target->receive_damage("ap",mydex/2+mysk/10);
        target->delete_temp("use_do");
    }
    return dodge_msg[random(sizeof(dodge_msg))];

}

int practice_skill(object me) { return 1; }

int improve_limite(object ob)
{
    int a;
    a=ob->query_dex()+ob->query_int()+40;
    if(a>100) a=100;
    return a;
}

