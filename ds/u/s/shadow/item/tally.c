#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"���"NOR, ({"tiger tally","tally"}) );
	set_weight(80);
	                       
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�@�i���骺����ťO�A�j�j����ΦL�b�W���I");
		set("unit", "�i");
		set("value", 1);		
	}
	setup();
}

void init()
{
	add_action("do_use", "use");
}

int do_use(string arg) 
{
	object me = this_player(), ob = this_object();
	if( !this_object() ) return 0;
	if( !this_object()->id(arg) ) return 0;
	
	me->set("env/msg_home", HIG"��.. �ڪ����H..�p�b���̡I�Q���^�ӤF...\n"NOR);
	me->set("env/msg_clone", HIG"$N�@���u�A�H�����Q�K�K�M�Y�赦���N$n"HIG"�e�W�ӡC\n"NOR);
	me->set("env/msg_min", HIG"�b�ɾԶ��K�G�A�Թ��n�ѤѾ_�a�I�Q�K�K�M�L�ֵ�$N�H������������b�ӡI\n"NOR);
	me->set("env/msg_mout", HIG"$N��ܤ@�n�G�u�H�ڨӡI�v�Q�K�K�M�y�ɵ����b���H$N�ľW�ӥh�I\n"NOR);
	
	write(HIG"�A�I�Ƥ@�i�N�x�O�A�͸Ͷ��ϱN�A�ιγ��I\n"NOR); 
	
	destruct(ob); 
	return 1;
} 


