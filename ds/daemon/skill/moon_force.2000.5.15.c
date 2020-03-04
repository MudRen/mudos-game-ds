//Update by Linjack 99/10/19
/* �e���� �G �ݤ�ߪk(moon_force) �� Cominging �� 1999/5/29 ��ҳ� */
// QC: Luky [10.21.1999] �}���ڴ���.
// Update by tmr 2000/1/16
// Visit By Cominging 2000/1/16
// Update By Tmr 2000/5/7 ( �s�W rewield )

#include <ansi.h>
inherit SKILL;
inherit SSERVER;

void delay(object me);
void arc(object me,object target);
void rewield(object target,object wp);

int exert(object me,object target, string arg)
{
    int heal,reheal,sk,lv;
    int p,max;
    object weapon;

    if( !arg || arg == "?" )
    {
        write(@SKILL_HELP

      �ݤ�ߪk�ϥΤ�k:       exert moon_force <�Ѽ�>
      �Ѽ�:
              recover         ����AP�Ӧ^��HP
              moon-arc        �N���u�W�����O�Ƭ��뫬��l�_���ĤH�Z��

              SKILL_HELP);
        return 1;
    }

    if( arg=="recover" )
    {
        if( me->query("ap") < 20 )
            return notify_fail("�A�ثe�����p���ΡA�L�k�ϥδݤ�ߪk�C\n");
        if( me->query_skill("moon_force") < 10 )
            return notify_fail("�A���ݤ�ߪk��¦�����I\n");
        heal= (int)me->query("max_hp");
        if( me->query("hp") >= heal )
            return notify_fail("�A�ثe���ͩR���p�w�g�O�����F�C\n");
        if(heal>4000) heal = 4000 + ((heal-4000)/8);
        sk = (int)me->query_skill("moon_force");
        lv = (int)me->query("level");
        if ( sk > 50 ) sk = 50 + ((sk-50)/2);
        reheal = (heal / 20) + ((sk/5)*3) + random(9) + (lv/2);
        me->receive_heal("hp",reheal);
        me->receive_damage("ap",27 + reheal/7 + random(4));
        me->improve_skill("moon_force",me->query("int")/8 + random(3));
        me->improve_skill("force",me->query("int")/7 + random(3));
        me->start_busy(2);
        message_vision(HIR"$N�@�ɶ��R�U�ߨӡA�B���I�F���W�U�ˤf�Ǫ��j�ޡC\n"NOR,me);
        return 1;
    }

    if( arg=="moon-arc" )
    {
        if( !me->is_fighting() )
            return notify_fail("�A�èS���b�԰����C\n");
        if( me->query_skill("moon_force") < 50 )
            return notify_fail("�A���ޯण���A�L�k�ϥΡu����v�C\n");
        if( !target ) target = offensive_target(me);
        if( !target ) return notify_fail("�A�n��֨ϥΡu����v�H\n");
        weapon=target->query_temp("weapon");
        if(!weapon)
            return notify_fail("�Ĥ�èS�����Z���A�u����v�L�k�o���ĥΡC\n");
        if( me->query("hp") < 100 || me->query("ap") < 100)
            return notify_fail("�A�����骬�p���n�C\n");

        message_vision("\n$N����@�X�@���A�H�ŵ깺���X�@���u����v�C\n"
                       HIY "��������ͩR�@��A�H�ֱ��L�۪��e�t��V$n���Z��������I�I\n" NOR,me,target);

        me->receive_damage("hp",30);
        me->receive_damage("ap",50);
        me->improve_skill("moon_force",me->query("int")/6 + random(4) );
        me->improve_skill("force",me->query("int")/5 + random(4) );
        me->start_busy(2);
call_out((: arc,me,target:),1+random(2));
        return 1;
    }

    else return notify_fail("�ݤ�ߪk�S���o�إ\\��I\n");

}

void arc(object me,object target)
{
    object wp;
    string type;
    int t,m;
    if(!me || !target ) return;

    wp=target->query_temp("weapon");
    if( !wp )
    {
        message_vision("�u����v�����F�ư�A�Ʀ��@�}���Ϯ����F�C",me);
        return;
    }
    type = wp->query("skill_type");
    t=target->query_skill(type)+target->query_str()+(wp->query_temp("durable")/25);
    m=me->query_skill("dodge")+me->query_str()+(me->query_skill("moon_force")/3);
    if( random(t) < random(m) && wp->unequip() )
    {
        message_vision(HIC "�u��v�a�@�n�T�A���뼲�o$N�渨�F�⤤���Z���I�I\n" NOR ,target);
        target->start_busy(1);

call_out((: rewield,target,wp:),120 );
    }
    else message_vision(CYN "�u��v�a�@�n�T�A����@���W$N�⤤���Z���ϦӳQ�_�H�F�I�I\n" NOR,target);
    return;
}

void rewield(object target,object wp)
{
    if( !wp || !target || userp(target) ) return;
    if(environment(wp) != target ) return;
    if( wp->wield() )
        message_vision("������$N���ĤO����A$N�˳ư_$n�C\n",target,wp);
    return;
}

int valid_learn(object me)
{
    return 1;
}

int practice_skill(object me)
{
    return 1;
}

void skill_improved(object me) // �`�N, �@��skill��W�[���ݩ��`�M�H 5 ���W��
{
    int b,c;
    b = me->query_skill("moon_force",1);
    c = me->query("skill/moon_force"); //luky

    if( b % 20==19 && b > c)
    {
        if(random(2))
        {
            tell_object(me, HIR "�A���ʧ@�ѩ�⮩�ݤ�ߪk���D�ӧ�[���դF�C\n" NOR);
            me->add("addition/dex", 1);
        }
        else
        {
            tell_object(me, HIR "�A�����ѩ�⮩�ݤ�ߪk���D�ӼW�j�F�C\n" NOR);
            me->add("addition/con", 1);
        }
        me->set("skill/moon_force",b);
    }
    me->save();
}

int improve_limite(object ob)
{
    int a;
    a=(ob->query("level")*3)+(ob->query_int()/2);
    if( a > 90 && ob->query("level") < 26 ) a=100;
    else if( a>100) a =120;
    return a;
}