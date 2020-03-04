// �ⶳ�x�G�L�W��\ (utmost-force)

#include <ansi.h>
inherit SKILL;

void delay(object me);

int exert(object me,object target, string arg)
{
        int sk,lv,i,fsk;

        i = (me->query_int()+me->query_con()) / 4;
        i += me->query_sou()+me->query_tec();
        
        if( arg=="off" )
        {
                if( me->query_skill_mapped("force")!="utmost-force" )
                        return notify_fail("�A�èS���b�B�\\�C\n");
                me->delete_temp("is_busy/moon_force");
                tell_object(me,HIM "�A���ŤF�n�򸹡A����׷ҡu�L�W��\�v�F�C\n" NOR);
                me->map_skill("force");
                return 1;
        }

        if(!arg)
        {
        if( me->is_ghost() )
                return notify_fail("�A�L���鬰�ΡA�L�H�m�\�C\n");
        if( me->is_busy() )
                return notify_fail("�A�{�b���b���ۡA�S�Ű���L�ơC\n");
        if( me->is_fighting() )
                return notify_fail("�A�{�b�����ۥ��[, �S�Žm�\\�C\n");
        if( me->query_skill_mapped("force")=="utmost-force" )
                return notify_fail("�A�w���b�׷ҡu�L�W��\�v���C\n");
        if( me->query("hp") < 10 || me->query("mp") < 10 || me->query("ap") < 10 )
                return notify_fail("�A�ثe�����p���ΡA�L�k�׷Ҥߪk�C\n");
  
        message_vision(HIY"$N�L�����U�A�}�l�׷Ұ_�u�L�W��\�v�C\n"NOR,me);
        me->map_skill("force","utmost-force");
        me->receive_damage("hp", 5);
        me->receive_damage("ap", 6);
        me->receive_damage("mp", 6);
        me->improve_skill("force",random(i/3)+random(2) );
        me->improve_skill("utmost-force",random(i/2)+random(3) );

        me->set_temp("is_busy/utmost-force","�A���b�׷ҡu�L�W��\�v�A�Ȯɤ��ಾ�ʡC\n");
        me->start_busy(2);
        me->skill_active( "utmost-force",(: call_other, __FILE__, "delay", me :), 3);
        return 1;
        }
        else
        {



        }
        return 1;
}

void delay(object me)
{
        int sk,lv,i;
        
        sk = me->query_skill("utmost-force");
        i = me->query_int();

        if( !me ) return;

        if( me->query_skill_mapped("force")!="moon_force" )return;

        if( me->query("ap") < 10 || me->query("hp") < 10 || me->query("hp") < 10 )
        {
                tell_object(me,HIM "�A���ŤF�n�򸹡A����׷ҡu�L�W��\�v�F�C\n" NOR);
                me->delete_temp("is_busy/utmost-force");
                me->map_skill("force");
                return;
        }

        me->receive_damage("hp", 5);
        me->receive_damage("ap", 6);
        me->receive_damage("mp", 6);
        me->improve_skill("force",random(i/3)+random(2) );
        me->improve_skill("utmost-force",random(i/2)+random(3) );
        me->skill_active( "utmost-force",(: call_other, __FILE__, "delay", me :), 3);
}

int valid_learn(object me)
{
        return 1;
}

int practice_skill(object me)
{
        return 1;
}

void skill_improved(object me)
{
        int b;
        b = me->query_skill("utmost-force",1);
        me->add("evil",-(me->query("level")*5) ); //��֨��c��

        if(b % 10 == 0 && random(b) > 40 )
        {
        tell_object(me, HIY "�ѩ�A���~�׷ҡu�L�W��\�v�A�A����责�ɤF�C\n" NOR);
        me->add("addition/con", 1);
        }
        me->save();
}

int improve_limite(object ob)
{
        int a;
    a=ob->query("int");
        if (a > 20) a=20;
        return 80+a;
}





