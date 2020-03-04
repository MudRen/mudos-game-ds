#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
        "\n���O$n�����Ʃ��A�����@�a�A�@��"GRN"�u�ſP��L�v"NOR"�A�|���Y�����׶}�o�@���C\n",
        "\n$n���H�N��A�@��"GRN"�u���᭸�R�v"NOR"�A���a���@���ƶ}�ƤءA�׹L�F�o�@�ۡC\n",
        "\n�i�O$n�����@���A�ϥX"GRN"�u�h�����ơv"NOR"�A$N�o�@�ۼ��F�ӪšC\n",
        "\n�o��$n�����I�a�A�@��"GRN"�u�˶��r���v"NOR"�A���κw�ȷȤ@��A���ǰ{�}�ƤءA���F�}�h�C\n",
        "\n$n���}�@�I�k�}�I�A���Ω��W�@�ޡA�@��"GRN"�u�@�b�Ĥѡv"NOR"�A���������a�׶}�F�o�@�ۡC\n",
                     });

int exert(object me, object target, string arg)
{
    if(arg=="off" )
    {
        if( me->query_skill_mapped("dodge")!="swallow-flying")
            return notify_fail("�A�èS���ϥΡi���P�j���j�C\n");
        me->map_skill("dodge");
        me->reset_action();
        message_vision("$N���κ��C�U�ӤF�C\n"NOR,me);
        write("�ޯ�i���P�j���j�w�����C\n");
        return 1;
    }

    if(me->query_skill("dodge")<10) return notify_fail("�A�����\\��¦����(10��)�L�k�ϥΡi���P�j���j�C\n");
    if(me->query_skill_mapped("dodge")=="swallow-flying")
        return notify_fail("�A�w�g�b�ϥΡi���P�j���j�C\n");
    if(me->query("ap")<10 || me->query("hp")<10) return notify_fail("�A�ثe�����骬�p�L�k�ϥΡi���P�j���j�C\n");

if(!me->skill_active( "swallow-flying",(: call_other, __FILE__, "delay", me :), 10))
        return notify_fail("�A�����P�j�����۰ʧ@�٨S�����C\n");

    me->map_skill("dodge", "swallow-flying");
    me->reset_action();

    message_vision("\n"HIW"$N���v�g���A�}�l�I�i�i���P�j���j�A�O�H���N���w�C\n"NOR,me);
    me->receive_damage("ap",2);
    me->start_busy(1);
    return 1;
}

void delay(object me)
{
    if(!me) return;

    if(me->query_skill_mapped("dodge")!="swallow-flying")
    {
        //remove_call_out("delay");
        return;
    }

    if(me->query("ap")<2)
    {
        me->map_skill("dodge");
        me->reset_action();
        message_vision("$N���κ��C�U�ӤF�C\n"NOR,me);
        tell_object(me,"�A����O�����L�k�~��ϥΡi���P�j���j�C\n");
        return ;
    }
    if(me->is_fighting()) me->receive_damage("ap",2);
        me->skill_active( "swallow-flying",(: call_other, __FILE__, "delay", me :), 10);
}

int valid_learn(object me) {    return 1;       }
string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me) { return 1; }
int improve_limite(object ob)
{
        int lv = ob->query_dex() + ob->query_int();
        return (lv < 90 ) ? 90 : 100;

}

