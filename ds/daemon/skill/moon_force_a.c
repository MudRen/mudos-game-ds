//Update by Linjack 99/10/19
/* �e���� �G �ݤ�ߪk(moon_force) �� Cominging �� 1999/5/29 ��ҳ� */
// QC: Luky [10.21.1999] �}���ڴ���.
// Update by tmr 2000/1/16
// Visit By Cominging 2000/1/16

#include <ansi.h>
inherit SKILL;
inherit SSERVER;

void delay(object me);
void arc(object me,object target);

int exert(object me,object target, string arg)
{
    int heal,reheal,sk,lv;
    int p,max;
    object weapon;

    if( arg=="off" )
    {
        if( me->query_skill_mapped("force")!="moon_force" )
            return notify_fail("�A�èS���b�B�\\�C\n");
        me->delete_temp("is_busy/moon_force");
        message_vision(HIY"$N���_���Ⲵ�C�C�C�}�A�����S�y�^�g�ߤ��F�C\n"NOR,me);
        me->map_skill("force");
        return 1;
    }

    if( me->query_skill_mapped("force")=="moon_force" )
        return notify_fail("�A�{�b�٦b�׷Ҵݤ�ߪk���C\n");

    if(!arg)
    {
        if( me->is_fighting() )
            return notify_fail("�A�{�b�����ۥ��[, �S�Žm�\\�C\n");
        if( me->query("hp") < 20 || me->query("ap") < 20 )
            return notify_fail("�A�ثe�����p���ΡA�L�k�׷Ҥߪk�C\n");
if(!me->skill_active( "moon_force",(: call_other, __FILE__, "delay", me :), 3))
            return notify_fail("�A�����B�\\���ʧ@�٨S�����C\n");

        if( me->query_skill("moon_force") < 85 )
            return notify_fail("�A���ݤ�ߪk�ڥ��٤��Φۤv�׷�, �h��Ѯv�ǧa.\n");
        message_vision(HIC"$N�H�a�L�}���U�A��B���e�A�E�Ȥ��Ӿi���C\n"NOR,me);

        me->map_skill("force","moon_force");
        me->receive_damage("ap", 5);
        me->receive_damage("hp", 2);
        me->set_temp("is_busy/moon_force","�A���b���i�����A�Ȯɤ��ಾ�ʡC");
        me->start_busy(2);
me->skill_active( "moon_force",(: call_other, __FILE__, "delay", me:), 2);
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
        me->start_busy(2);
        message_vision(HIR"$N�@�ɶ��R�U�ߨӡA�B���I�F���W�U�ˤf�Ǫ��j�ޡC\n"NOR,me);
        return 1;
    }



    // �ޥίe������@�o�� 5 -- �u����v
    // By Tmr
    // Edition By Cominging

    if( arg=="powerin" )
    {
        max = (me->query_con() / 4) + 10;
        sk = me->query_skill("moon_force") / 10;
        if( me->query_skill("moon_force") < 50 )
            return notify_fail("�A���ݤ�ߪk�٤������m�C\n");
        if( me->query("ap") < 150 )
            return notify_fail("�A�����O�����A�L�k�N���O�e���u�W�C\n");
        if( me->query_str() < 20 )
            return notify_fail("�A���M�O�����H�ӻE�\\�O�C");
        if( me->query_temp("class_wind/power") >= max )
            return notify_fail("�A�����u�w�g�L�k�A�Ө���j�����O�F�C\n");

        message_vision(HIW"$N���u�L�LŸ�ʡA��M���E�F�@�ѥ\\�O�b���u�W�I�I\n" NOR,me);

        if( me->is_fighting() )
        {
            if( me->query_temp("class_wind/power") + sk > max ) {
                me->add_temp("class_wind/power", max - me->query_temp("class_wind/power") );
                me->receive_damage("ap",(max - me->query_temp("class_wind/power"))*10);
            }
            else {
                me->add_temp("class_wind/power", sk );
                me->receive_damage("ap",sk*10);
            }
            me->start_busy(2);
        }
        else
        {
            if( me->query_temp("class_wind/power") + sk > max ) {
                me->add_temp("class_wind/power", max - me->query_temp("class_wind/power") );
                me->receive_damage("ap",(max - me->query_temp("class_wind/power"))*10);
            }
            else {
                me->add_temp("class_wind/power", sk );
                me->receive_damage("ap",sk*10);
            }
            me->start_busy(1);
        }
        return 1;
    }

    if( arg=="moon-arc" )
    {
        if( !me->is_fighting() )
            return notify_fail("�A�èS���b�԰����C\n");
        if( !target ) target = offensive_target(me);
        if( !target ) return notify_fail("�A�n��֨ϥΡu����v�H\n");
        p=me->query_temp("class_wind/power");
        weapon=target->query_temp("weapon");

        if(!weapon)
            return notify_fail("�Ĥ�èS�����Z���A�u����v�L�k�o���ĥΡC\n");
        if( p < 3 )
            return notify_fail("�Aı�o���u�ĳn�L�O�A�L�k���X�u����v�C\n");
        if(me->query("hp") < 50)
            return notify_fail("�A�����骬�p���n�C\n");

        message_vision("\n$N����@�X�@���A�H�ŵ깺���X�@���u����v�C\n"
                       HIY "��������ͩR�@��A�H�ֱ��L�۪��e�t��V$n���Z��������I�I\n" NOR,me,target);

        me->add_temp("class_wind/power",-3);
        me->receive_damage("hp",30);
        me->start_busy(2);
me->skill_active( "moon_force",(: call_other, __FILE__, "arc", me,target:), 2+random(1) );
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
    }
    else message_vision(CYN "�u��v�a�@�n�T�A����@���W$N�⤤���Z���ϦӳQ�_�H�F�I�I\n" NOR,target);
    return;
}

void delay(object me)
{
    int sk_level,lv,i;

    sk_level = me->query_skill("moon_force");
    lv = me->query("level");
    i = me->query_int();

    if( !me ) return;

    if( me->query_skill_mapped("force")!="moon_force" )return;

    if( me->query("ap") < 13 || me->query("hp") < 13 )
    {
        message_vision(HIR"$N�߯��p�@�D�����L�A£�M����F�B�\\�C\n"NOR,me);
        me->delete_temp("is_busy/moon_force");
        me->map_skill("force");
        return;
    }
    else
        if ( sk_level < 50 )
        {
            me->receive_damage("ap",8);
            me->receive_damage("hp",5);
        }
        else
            if ( sk_level > 49 )
            {
                me->receive_damage("ap",12);
                me->receive_damage("hp",7);
            }
    me->improve_skill("force",1+random(5+lv/2)+(i/3) );
    me->improve_skill("moon_force",1+random(5+lv/2)+(i/3) );
me->skill_active( "moon_force",(: call_other, __FILE__, "delay", me :), 3);
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
