// create by whoami 2006/12
// QC by tmr 2007/01/05
// skyowl ���\���ݭn���S��

#include <ansi.h>
inherit SKILL;
inherit SSERVER;

string *dodge_msg = ({
                         HIR"��M$n�����������X����A�����N�@��A�~��$N�����a��$n�C\n"NOR,
                         "\n$n��M���I�ᴡ�F���ͻH�@�˪����ʨ��t�A��$N�L�q�����_�C\n",
                         "\n$n��M���k���몺��İ_�ӡA��$N�X�⪺�ɶ��j�áA�]���׹L���ۡC\n",
                         "\n$n���W�����A�����Q�۽�ۼΰ}�����ΡA�}�]��_�ۼΰ}���A��$N�L�q�U��C\n",
                         "\n$n���}�@�ޡA���ĤW�ѡA�@��"+HIC+"�i��}�����j"+NOR+"�}�G�����b$N����C\n",
                         "\n��M$n�}�B�ܻ��A�@��"+HIM+"�i����k�u�j"+NOR+"�A�b$N����դ��C���|��C\n",
                         "\n��M$n��C�F�}�B�A���i���h�A��$N�����N�����Y���C\n",
                         "\n�٨����A$n�������o�X���˪����~�A�ʧ@�񥭱`�n�֤W�ƭ��A��$N�����I����$n�@�ڴH��C\n",
                     });

int exert(object me, object target, string arg)
{
    string msg;

    if(arg=="off" )
    {
        if( me->query_skill_mapped("dodge")!="wing-eight")
            return notify_fail("�A�èS���ϥΡy�F�l�K�B�Z�z�C\n");
        me->map_skill("dodge");
        me->reset_action();
        message_vision( CYN"$N�������C�C�ର���`���C��A�ӭ쥻���ժ��}�B�]�v���ͽw�C\n"NOR,me);
        write("�ޯ�y�F�l�K�B�Z�z�w�����C\n");
        return 1;
    }

    if(me->query_skill("dodge")<20)
        return notify_fail("�H�A�����\\��¦�L�k�ϥΡy�F�l�K�B�Z�z�C\n");
    if(me->query_skill_mapped("dodge")=="wing-eight")
        return notify_fail("�A�w�g�b�ϥΡy�F�l�K�B�Z�z�C\n");
    if(me->query("ap")<50 || me->query("hp")<50)
        return notify_fail("�A�����骬�L�k�ϥΡy�F�l�K�B�Z�z�C\n");
        if(!me->skill_active( "wing-eight",(: call_other, __FILE__, "delay", me :), 10))
        return notify_fail("�A���y�F�l�K�B�Z�z���۰ʧ@�٨S�����C\n");

    message_vision(HIR"$N��������M�ର�����A�����ĤH���@�|�@�ʡA�ϥX�ǻ������y�F�l�K�B�Z�z�C\n"NOR,me);

    me->map_skill("dodge", "wing-eight");
    me->reset_action();
    me->receive_damage("mp",3);
    me->receive_damage("ap",3);
    me->start_busy(1);
        me->skill_active( "wing-eight",(: call_other, __FILE__, "delay", me :), 10);
    return 1;
}

void delay(object me)
{
    if(!me)
        return;

    if(me->query_skill_mapped("dodge")!="wing-eight")
        return;

    if(me->query("ap")<50)  {
        me->map_skill("dodge");
        me->reset_action();
        message_vision( "$N������������_�����`�C��A�ӭ쥻���ժ��}�B�]�v���ͽw�C\n"NOR,me);
        tell_object(me,"�A����O�����L�k�~��ϥΡy�F�l�K�B�Z�z�C\n");
        return ;
    }
        me->skill_active( "wing-eight",(: call_other, __FILE__, "delay", me :), 10);
}

int valid_learn(object me)
{
    return 1;
}

string query_dodge_msg(string limb, object me, object target)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
    return 1;
}

int improve_limite(object me)
{
    int a = me->query_dex() + me->query_int();
    if(a>100)
        a=100;
    return a;
}



