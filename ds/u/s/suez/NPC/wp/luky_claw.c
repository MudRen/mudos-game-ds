#include <ansi.h>
#include <weapon.h>
inherit SSERVER;
inherit F_UNIQUE;
inherit FIST;
void npc_auto_equip(object target);
void create()
{
        set_name(HIR"���л��"NOR,({"fire bird claw","claw"}) );
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
        set("wield_msg",
HIC "$N���_�@��$n"HIC"�A�u��$N"HIC"���W����A�@�}�`�����K����$n"HIC"�V�|���K���X�I�I\n"
NOR);
        }
            set("value",23000);
            set("limit_con",20);
            set("limit_str",20);
            set("limit_int",20);
            set("limit_dex",20);
    set("weapon_prop/armor", 17);
    init_fist(27);
        setup();
}
void init()
{        
        add_action("do_irrigate","irrigate");
}

int do_irrigate(string arg)
{
        object wp,me,target;
        int p,m,d,a;
        me=this_player();
        
        if(environment(this_object())!=me) return 0;  //���n���ˬd. (�_�h��b�a�W�N�i�H��)
        if(me->query_temp("weapon")!=this_object()) return 0; //���n���ˬd (�_�h���θ˳ƴN�i�H��)
        if( me->is_busy() || me->is_block() ) return notify_fail("�A���W�@�Ӱʧ@�٨S�����C\n"); //�����Ӻ|��
        target = offensive_target(me);  // �n�� inherit SSERVER;
	if(!target) return notify_fail("�b�԰����~��o�����л�����O�q�C\n");
        wp=target->query_temp("weapon");
        p=target->query_skill("dodge")+target->query_dex();
        m=me->query_skill("dodge")+me->query_dex();
        if(!arg) return notify_fail("���O: irrigate ap �� irrigate mp�C\n");
        if(arg == "ap" )
        {
        	if(me->query("ap")<100) return notify_fail("�A�S��������ap�i��J���л���C\n"); //�����Ӻ|��.
		if( me->query_skill_mapped("unarmed") )  // �p�G�S��map skill �|�Ǧ^ 0
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
	                   me->add_busy(2);
	                   target->add_busy(2);
	                }
	                return 1;
	        }
	
	        if( 10+random(p+20) < random(m))
	        {
	                wp->unequip();
	                if(!userp(target)) call_out("npc_auto_equip",15,target);
	                if(target->query_str()<20 || random(target->query_str())<random(me->quert_str()/3)) wp->move(environment(target));
	                message_vision(HIC "�u���@�D�����N�V"+wp->query("name")+"�I�I$N�⤤�n�ɤ@�}�u�S�A�榣�P�}�F"+wp->query("name")+"�I�I\n" NOR ,target);
	                me->receive_damage("ap", 20 );
	                me->add_busy(2);
	                target->add_busy(2);
	        }
	        else
	        {
	                message_vision(CYN "$N�⤤�L���@�Y�A���}�F���ު������I�I\n" NOR,target);
	                me->add_busy(2);
	        }
	  return 1;
	} else if(arg=="mp") {
		if(me->query("mp")<100) return notify_fail("�A�S��������mp�i��J���л���C\n");
		//enter your code for "mp" here
		write("�|������!\n");
		return 1;
	} else return notify_fail("���O: irrigate ap �� irrigate mp�C\n");
        return 1;
}

void npc_auto_equip(object target)
{
	if(target) target->force_me("wield all");
	return;
}