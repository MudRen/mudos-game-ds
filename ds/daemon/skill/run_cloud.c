/********�l���y�B(Run_cloud)       Update By Kkeenn*******/
#include <ansi.h>
inherit SKILL;
void delay(object me,int cost);
string *dodge_msg = ({
                         "$n�C�n���D�G�i���v��[�@�褤�j�A�̨��{�}�F$N���ۦ��C\n",
                         "$n���n�ۥX�G�i�����n���x�����j�A���L�F$N�������C\n",
                         "$n�H�R�����X�i�p��᭫��g��j�A���}�F$N�������d��C\n",
                         "$n�}�U�@�ʤ@�ۡi�z�h���X��R���j�A�{�}�F$N����աC\n",
                         "$n�@�өި��@�ۡi�򶳭����R���šj�A�������L�F$N���¯١C\n",
                         "$n�B�_�����\\�O�H�@�ۡi�դ���p��»���j�A�w�ͥͪ��N$N����������C\n",
                         "$n����P�ϥX�@�ۡi����s�H�B���]�j�A�[�}�F$N����աC\n",
                         "$n�@�n�b���i���Y�঳�X�h���j�A�׸��D�X�F$N�����e��C\n",
                     });
string *adv_dodge_msg = ({
                             "$n�C�n���D�G�i���v��[�@�褤�j�A�̨��{�}�F$N���ۦ��C\n",
                             "$n���n�ۥX�G�i�����n���x�����j�A���L�F$N�������C\n",
                             "$n�H�R�����X�i�p��᭫��g��j�A���}�F$N�������d��C\n",
                             "$n�}�U�@�ʤ@�ۡi�z�h���X��R���j�A�{�}�F$N����աC\n",
                             "$n�@�өި��@�ۡi�򶳭����R���šj�A�������L�F$N���¯١C\n",
                             "$n�B�_�����\\�O�H�@�ۡi�դ���p��»���j�A�w�ͥͪ��N$N����������C\n",
                             "$n����P�ϥX�@�ۡi����s�H�B���]�j�A�[�}�F$N����աC\n",
                             "$n�@�n�b���i���Y�঳�X�h���j�A�׸��D�X�F$N�����e��C\n",
                             "$n�C�n���D�G�i�s��D�S����O�j�A�̨��{�}�F$N���ۦ��C\n",
                             "$n���n�ۥX�G�i���_�M�����孷�j�A���L�F$N�������C\n",
                             "$n�H�R�����X�i���ؿ@�جK�N�b�j�A���}�F$N�������d��C\n",
                             "$n�}�U�@�ʤ@�ۡi�������A�ӪܻT�j�A�{�}�F$N����աC\n",
                             "$n�@�өި��@�ۡi�H�]�Ȩӯ���s�j�A�������L�F$N���¯١C\n",
                             "$n�B�_�����\\�O�H�@�ۡi���l���m������j�A�w�ͥͪ��N$N����������C\n",
                             "$n����P�ϥX�@�ۡi�M�`�@�˵��e��j�A�[�}�F$N����աC\n",
                             "$n�@�n�b���i�~������K���P�j�A�׸��D�X�F$N�����e��C\n",
                         });
int exert(object me, object target, string arg)
{

    if(arg=="off" )
    {
        if( me->query_skill_mapped("dodge")!="run_cloud")
            return notify_fail("�A�èS���ϥΰl���y�B�C\n");
        me->map_skill("dodge");
        me->reset_action();
        message_vision("\n"HIW"$N���}�B�C�U�ӤF�C\n"NOR,me);
        write("�ޯ�[�l���y�B]�w�����C\n");
        return 1;
    }

    if(me->query_skill("dodge")<40) return notify_fail("�A���a�D�{�ׯ�O�٤����ϥΰl���y�B�C\n");
    if(me->query_skill_mapped("dodge")=="run_cloud")
        return notify_fail("�A���b�ϥΰl���y�B�C\n");
    if(me->query("ap")<40 || me->query("hp")<40) return notify_fail("�A�����骬�p�L�k�ϥΰl���y�B�C\n");
if(!me->skill_active( "ruun_cloud",(: call_other, __FILE__, "delay", me ,5:), 5))
        return notify_fail("�A���_�l���y�B���ʧ@�٨S�����C\n");

    me->map_skill("dodge", "run_cloud");
    me->reset_action();
    message_vision("\n"HIG"$N�I�i�l���y�B, �n���b�@�b���ۥX�\\�h�������C\n"NOR,me);
    me->add("ap", -20);
    me->start_busy(2);
    //me->start_call_out( (: call_other, __FILE__, "delay", me ,2:), 10);
    return 1;
}

void delay(object me,int cost)
{
    if(!me) return;
    if(me->query_skill_mapped("dodge")!="run_cloud")
    {
        return;
    }
    if(me->query("ap")<cost+15)
    {
        me->map_skill("dodge");
        me->reset_action();
        message_vision("\n"HIW"$N��M�C�F�U�ӡC\n"NOR,me);
        tell_object(me,"�A����O�����ϥΰl���y�B�F�C\n");
        return ;
    }
    if( me->is_fighting() ) me->receive_damage("ap", cost);
    //me->start_call_out( (: call_other, __FILE__, "delay", me ,cost:), 10);
me->skill_active( "run_cloud",(: call_other, __FILE__, "delay", me ,cost:), 5);
}

int valid_learn(object me) {    return 1;       }

string query_dodge_msg(string limb)
{
    if( this_player()->query("class2") == "������" )
        return adv_dodge_msg[random(sizeof(adv_dodge_msg))];
    else return dodge_msg[random(sizeof(dodge_msg))];

}
int practice_skill(object me) { return 1; }
int improve_limite(object ob)
{
    int a;
    a=ob->query_dex();
    a=60+a;
    return a;
}

