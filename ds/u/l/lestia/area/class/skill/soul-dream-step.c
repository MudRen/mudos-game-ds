// 2000/26/8 by lestia
// �F�۱�-�F�פۨB
#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
  "$n�H�N�ưʡA�������N$N�������{�L�C\n",
  "$n���Τ@�̡A�@�ۡu"+HIY"�F�N�H��"+NOR"�v�A���δ¥t�@��P�h�C\n",
  "$N���n����$n���ɡA���M�u��$n�H���֪����k�V��h�h�C\n",
  "$N����F��զ��G�H��$n�G�J�@�Ӧ����C$n�@�r���A���h�϶i�A\n"
  "$n���Τ@�{�A�����V�k�ץh�C$N���ݰl���A�u��$n�w�g�V���D�}�C\n",
  "$n�N�H����A�}�B���t�A�N$N�������{�}�C\n",
  "$n��$N�������Ӷլ����A�F��B������A���Τ@�̡A¶�L$N�C\n",
  "$n�}�B���ۡA���v�������k�A�{�L$N�C\n",
});     

int exert(object me, object target, string arg)
{
        string msg;
        int add_dodge;

        if ( arg=="off" )
        {
                if( me->query_skill_mapped("dodge")!="soul-dream-step")
                        return notify_fail("�A�èS���ϥ��F�פۨB�C\n");
                if( me->query_temp("apply/dodge") >= me->query_temp("class_soul/soul-dream-step") )
                        me->add_temp("apply/dodge", -me->query_temp("class_soul/soul-dream-step"));
                else me->set_temp("apply/dodge", 0);
                me->delete_temp("class_soul/soul-dream-step");
                me->map_skill("dodge");
                me->reset_action();
                message_vision("\n"HIW"$N�N�F���X���A����B���F�פۨB�C\n"NOR,me);
    write( HIR"�����ϥΧޯ�:�y�F�פۨB�z�C\n"NOR );
                return 1;
        }

        if ( me->query_skill("dodge") < 5 )
                return notify_fail("�A�����\\��¦�����L�k�ϥ��F�פۨB�C\n");

        add_dodge = ((me->query_skill("dodge") * me->query_skill("soul-dream-step")) / (me->query_skill("dodge")+me->query_skill("soul-dream-step") - 4))/1.01 + random((me->query_skill("dodge")+me->query_skill("soul-dream-step"))/3);

        if ( me->query_skill_mapped("dodge")=="soul-dream-step" )
                return notify_fail("�A���b�ϥ��F�פۨB�C\n");

        if ( me->query("ap") < 10 )
                return notify_fail("�A������ثe���p�ٵL�k�ϥ��F�פۨB�C\n");

        if( !me->skill_active( "soul-dream-step", (: call_other, __FILE__, "delay", me :), 10) )
                return notify_fail("�A���F�פۨB�F���X���ʧ@�٨S�����C\n");

        me->map_skill("dodge","soul-dream-step");
        me->reset_action();

        message_vision("\n"HIY"���بI��A�N�餺���F��B������C\n"NOR,me);
        me->receive_damage("ap", 1);
        me->start_busy(1);
        if( !me->query_temp("class_soul/soul-dream-step") )
        {
                me->add_temp("apply/dodge", add_dodge);
                me->set_temp("class_soul/soul-dream-step", add_dodge);
        }
        else
        {
                if( me->query_temp("apply/dodge") >= me->query_temp("class_soul/soul-dream-step") )
                me->add_temp("apply/dodge", add_dodge - me->query_temp("class_soul/soul-dream-step") );
                else me->set_temp("apply/dodge", 0);
                me->add_temp("apply/dodge", add_dodge);
                me->set_temp("class_soul/soul-dream-step", add_dodge);
        }
        return 1;
}

void delay(object me)
{
        int main, dodge, a;
        main = me->query_skill("soul-dream-step") - 30;
        dodge = me->query_skill("dodge") - 30;
        a = main + dodge;


        if( !me ) return;

        if( me->query_skill_mapped("dodge") != "soul-dream-step" )
        {
                if( me->query_temp("apply/dodge") >= me->query_temp("class_soul/soul-dream-step") )
                        me->add_temp("apply/dodge", -me->query_temp("class_soul/soul-dream-step"));
                else me->set_temp("apply/dodge", 0);
                me->delete_temp("class_soul/soul-dream-step");
                return;
        }

        if ( me->query("ap") < 10 )
        {
                me->map_skill("dodge");
                me->reset_action();
                message_vision("\n"HIW"$N�餺���F�𴲥h�A�S�^�_��F�@�몺�t�סC\n"NOR,me);
                tell_object(me,"�A�������w�áA�w�L�k�A�ϥ��F�פۨB�C\n");
                if( me->query_temp("apply/dodge") >= me->query_temp("class_soul/soul-dream-step") )
                        me->add_temp("apply/dodge", -me->query_temp("class_soul/soul-dream-step"));
                else me->set_temp("apply/dodge", 0);
                me->delete_temp("class_soul/soul-dream-step");
                return ;
        }

        if ( a > 1 ) a=1;
        if ( a < 0 ) a=0;
        if ( me->is_fighting() ) me->receive_damage("ap", 2-a);
        me->skill_active( "soul-dream-step",(: call_other, __FILE__, "delay", me :), 10);
}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        return 1;
}

int improve_limite(object ob)
{
        if( ob->query("class1")=="�F�۱�" ) return 100;
        else return 115;
}

