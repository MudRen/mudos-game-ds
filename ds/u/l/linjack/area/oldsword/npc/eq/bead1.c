#include <ansi.h>
#include <dbase.h>
#include <name.h>
inherit ITEM;
void create()
{
	set_name("��]", ({ "abacus bead","bead" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o�O�@���Q�����q����], ���L�A�Q���z�o�p�F����|�M��L���}�F�H\n");
		set("unit", "��");
		set("quantity",1);
		set("abacus/damage",10);
		set("abacus/unit","��");
		set("abacus/name","�p��]");
		set("abacus/type","small");
		set("material", "wood");
	}
	setup();
}
void init()
{
	add_action("do_loadit", "loadit");
}
int do_loadit(string arg)
{
	string type,msg;
	object weapon;
	if( !this_object()->id(arg) ) return 0;
	if(!weapon = this_player()->query_temp("weapon"))
		return notify_fail("�A���W�èS����L�C\n");
	if( this_player()->is_busy() )
		return notify_fail("�A�W�@�Ӱʧ@�٨S�������C\n");
	if(weapon->query_temp("loaded")==weapon->query("capacity"))
		return notify_fail("�o�Ӻ�L�S�S���ʺ�]�C\n");
	if(weapon->query("can_load")!=query("abacus/type"))
		return notify_fail("�o�Ӻ�L�������M�o�غ�]���X�C\n");
	if(weapon->query_temp("abacus") && weapon->query_temp("loaded") > 0)
	{
		if(weapon->query_temp("abacus/name") != this_object()->query("abacus/name"))
			return notify_fail("�A����P�ɦb�@�Ӻ�L���˨�غ�].\n");
	}
	weapon->set_temp("loaded",weapon->query_temp("loaded")+query("quantity"));
	if(weapon->query_temp("loaded") > weapon->query("capacity"))
		weapon->set_temp("loaded",weapon->query("capacity"));

	weapon->set_temp("abacus",query("abacus"));	//���[�ݩʩ�j�W
	
	if( this_player()->is_fighting() ) this_player()->start_busy(2);
		else this_player()->start_busy(1);
	
	if(stringp(msg=query("load_msg")))
		message_vision(msg+"\n", this_player(),this_object());
	else message_vision("$N���X$n, ���m���ˤJ"+weapon->name()+"���C\n", this_player(),this_object());
	tell_object(this_player(),"�A�ݨ�o��"+weapon->name()+"�W��"+chinese_number(weapon->query_temp("loaded"))+"����]�C\n");

	destruct(this_object());
	return 1;
}

