#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
        set_name(CYN"�C�s�����Q����"NOR, ({ "super pill","pill" }));
        set("long",
	"�o�������ڻD�O���ʮa�m�����N�����, �H�Ϊ�T�ʺ��ħ�,\n"
	"�[�W��\�\�`�p���m���N�h, �Ҥd�票���M�N�ĦX�C�C�|�Q�E�Ѥ�\n"
	"��y�X�@��----�C�s�����Q����, ���ĵL��, �������ĤѤU���u\n"
	"���Q��, �Q���u��, �G�@�뤦�{�j�������Ѧ���."
	);
        set("weight",50);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
        set("unit", "��");
        set("value", 5);
        set("heal_hp",1);      
        set("heal_mp",1);
	set("heal_ap",1);
        set("heal_body",20);
	set("heal_hand",20);
	set("heal_head",20);
	set("heal_foot",20);
	set("eat_msg","$N�Y�U�@����j�p�C�Y�����j�ĤY�C");
        set("eff_msg",HIW"�A���Mı�o�餺�q��κZ�A�ӥB�����R���F�O�q�C" NOR );
	}
        setup();
}
void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	string type,msg;
	object ob,me,env;
	me = this_player();
	ob = this_object();
	if( !ob ) return 0;
        if( !ob->id(arg) ) return 0;
        if( !env = environment(ob)) return 0;
        if( env != me && !ob->query("no_get")) return 0;
	if( me->is_busy() )
		return notify_fail("�A�W�@�Ӱʧ@�٨S�������C\n");
	if( ob->query("do_eat") )
                return notify_fail("�A�w�A�U�F�C\n");
	if( query("heal_hp"))
		me->receive_heal("hp", me->query("max_hp") - me->query("hp"));
	if( query("heal_mp"))
		me->receive_heal("mp", me->query("max_mp") - me->query("mp"));
	if( query("heal_ap"))
		me->receive_heal("ap", me->query("max_ap") - me->query("ap"));
	if( query("heal_head"))
		me->receive_curing("head", query("heal_head"));
	if( query("heal_body"))
		me->receive_curing("body", query("heal_body"));
	if( query("heal_hand"))
	{
		me->receive_curing("left_arm", query("heal_hand"));
		me->receive_curing("right_arm", query("heal_hand"));
	}

	if( query("heal_foot"))
	{
		me->receive_curing("left_leg", query("heal_foot"));
		me->receive_curing("right_leg", query("heal_foot"));
	}
	if( me->is_fighting() ) me->start_busy(2);
	message_vision("$N���_$n, �@�f��]�F�U�h�C\n",me,ob);
	if(stringp(msg=query("eff_msg"))) tell_object(me,msg+"\n");
	if(!ob->query("super_used") && !me->query_temp("super_used") )
	{
		tell_object(me,HIR"�A���Mı�o�����O�q�R�յL��I\n" NOR);
        	me->add_temp("apply/str",3);
		me->add_temp("apply/con",2);
		me->add_temp("super_used",1);
		ob->set("super_used",1);
        	ob->set("do_eat",1);
        	ob->set("no_drop",1);
        	ob->set("no_sac",1);
        	ob->set("no_give",1);
		ob->set("no_sell",1);
        	call_out("delay",250,me);     //���[�ݩʺ����ɶ�
	}
	else 
	{
		query("pill/function");
		if( !ob->finish_eat() )
			destruct(ob);
	}
        return 1;
}

void delay(object me)
{
        if(!me) return;
                tell_object(me,"�Aı�o�C�s�����Q�������ĤO�w�L, �A���O�q���G���z�F�U�ӡC\n" );
		me->add_temp("apply/str",-3);
	me->add_temp("apply/con",-2);
	me->delete_temp("super_used");
        destruct(this_object());
}

int is_pill() {	return 1; }

int query_autoload() { return 1; }
