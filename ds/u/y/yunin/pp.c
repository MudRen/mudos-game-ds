#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit FIST;

void create()
{
        set_name(HIR"���л��"NOR,({"fire bird craw","craw"}) );
        set("long",@long
    �o���M�ǻ��O�H�D�����ͤ���ı��������СA�V�H�Q�������A���h
����A�H�ѹp�N����ƤC�C�|�Q�E����Ӧ����ơC���a�Q�T���_�C�H����
���A�H�H�N���N���T�ɤ���M���Q�蠟���H���w�A�Ƥ�N��N�P�T���H��
�u�A�_�s�T�ʴH���Ӧ����C�H�F�s���h���_�A�H��s���h���͡C��������
�󦿴򤧤��A�H�ҥH�����ܦӤ��s��@�A����T�~�e��ѧ��Ѥ�̤l��l
������A�Ӳ{������A���禳�H�{����¤O���Ŷǻ����_�A�D��H�̶ǻ�
�ӻs�C

�ϥλ���:
1.���O irrigate ap �X �N�ۤv�����l��J���л�������H���ͤ��l�C
1.���O irrigate mp �X �N�ۤv���F�O��J���л�������H���ͭ��l�C
long
        );
       set_weight(1000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","��");
            set("value",23000);
            set("limit_con",20);
            set("limit_str",20);
            set("limit_int",20);
            set("limit_dex",20);
        set("wield_msg",
HIC "$N���_�@��$n�A�u��$N���W����A�@�}�`�����K����$n�V�|���K���X�I�I\n"
NOR);
        }
    set("weapon_prop/armor", 17);
    init_fist(27);
        setup();
}
void init()
{        
        add_action("do_fire","irrigate");
        add_action("do_wind","irrigate");
}
int do_fire(object me,object target,string arg)
{
        object wp;
        int p,m,d,a;
        wp=target->query_temp("weapon");
        p=target->query_skill("dodge")+target->query_dex();
        m=me->query_skill("dodge")+me->query_dex();
        if(arg != "ap" ) return 0;
        if( me->query_skill_mapped("unarmed")!="unarmed")
                        return notify_fail("�ϥΦ��ۦ������k�ɵL�k�ϥΪ��л�����S��C\n");
        if( !wp )
        {       
                a=10+random(100);
                me->receive_damage("ap", a );
                message_vision(HIY"$N���x�@�X�A�u��@�B�A�@�ѿK�������K���V$n�I�I\n"NOR,me,target);
                if(random(p) > random(a)+30 )
                {
                  message_vision(CYN "$N�a���@�{�A�����}�F���ު�ŧ���C\n" NOR,target);
                  me->add_busy(2);
                }
                else

                {
                   d= a*2/3+random(me->query("ap"))*3/5;
                   if(d > 200) d=200;
                   target->receive_damage("hp", d );
                   message_vision(HIR "$N���ɳQ�P�K�񨭡A�����@�Ϥ����ǥX�}�}�֦׿N�J������I\n" NOR,target);
                   me->add_busy(3);
                   target->add_busy(3);
                }
                return 1;
        }

        if( 30+random(p) < random(m))
        {
                wp->unequip();
                if(p->query_str()<20 || random(p->query_str())<random(p->quert_str()/3)) wp->move(environment(target));
                message_vision(HIC "�u���@�D�����N�V"+wp->query("name")+"�I�I$N�⤤�n�ɤ@�}�u�S�A�榣�P�}�F"+wp->query("name")+"�I�I\n" NOR ,target);
                me->receive_damage("ap", 20 );
                me->add_busy(1);
        }
        else
        {
                message_vision(CYN "$N�⤤�L���@�Y�A���}�F���ު������I�I\n" NOR,target);
                me->add_busy(1);
                target->add_busy(2);
        }

        return 1;
}
int do_wind(object me,object target,string arg)
{

        if(arg != "mp" ) return 0;
        
        return 1;
}

