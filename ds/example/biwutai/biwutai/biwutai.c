// �s��(adx) by snow 2000-05-15

#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "��Z�x");
	set ("long", @LONG
�o���N�O��Z�����j��Z�x�A�@�V�Ӱ�����Z�x�W�Q�۵V���⪺�a��
��Z�x���䪺�L���[�W�\��ۨ�ƤQ�K�Z�L���@���˹��C��Z�x�Z���O�@
�ӶQ���u�A�u���Ův�M�p���촸���Z�L�v�v�i�H���b�����C
LONG);
	set("info_sends",1);
	set("no_die",1);
	set("exits", ([
		"north"   : __DIR__"caipan",
		"down"   : __DIR__"kantai2",
	]));
	setup();
}

void init()
{
	add_action ("do_fight","fight");
	add_action ("do_fight","kill");
	add_action ("do_fight","hit");
	add_action ("do_work","quit");
	add_action ("do_work","halt");
}

int do_fight(string arg)
{
	object me=this_player();
	object *inv=all_inventory(environment(me));
	object ob;
	object who;
	int i;

	if(!arg) { 
		write("�A�n�P�֤�Z�H\n");
		return 1;
	}
	ob=present(arg, environment(me));
	if(!ob) {
		write("�o�̨S���o�ӤH�I\n");
		return 1;
	}
	if(ob==me) {
		write("�A�n�M�ۤv��Z�H�H�H\n");
		return 1;
	}
	if(!interactive(ob)) {
		write("�L�{�b�L�k�M�A��Z�I\n");
		return 1;
	}
	if(!userp(me) || !userp(ob)) {
		write("�L�{�b�L�k�M�A��Z�I\n");
		return 1;
	}

	for(i=0; i<sizeof(inv); i++) {
		who=inv[i];
		if(who->is_fighting()) {
			write("�x�W"+who->query("name")+"�����b��Z�A�еy�J�I\n");
			return 1;
		}
	}

	message("channel:chat",HIW"�i��Z���j"+
		me->query("family/family_name")+"��"+me->query("name")+"�P"+
		ob->query("family/family_name")+"��"+ob->query("name")+
		"�b��Z�x�W���q���C�I\n\n"NOR,users());

	me->set("biwu_fighter",1);
	ob->set("biwu_fighter",1);

	me->kill_ob(ob);
	ob->kill_ob(me);
	return 1;
}

void info_sends(string str)
{
	tell_room(__DIR__"kantai1", str);
	tell_room(__DIR__"kantai2", str);
	tell_room(__DIR__"kantai3", str);
}

int no_die(object me)
{
	object ob = me->query_temp("last_opponent");
	object obj, where;
	string id=ob->query("id");
	string id1=me->query("id");

	me->delete_temp("last_opponent");
	ob->delete_temp("last_opponent");
	me->delete_temp("last_damage_from");
	ob->delete_temp("last_damage_from");
	me->remove_all_killer();
	ob->remove_all_killer();
	me->reincarnate();
	ob->reincarnate();
	message("channel:chat",HIW"�i��Z���j"+
		ob->query("family/family_name")+"��"+ob->query("name")+"�b��Z�x����"+
		me->query("family/family_name")+"��"+me->query("name")+"�I\n\n"NOR,users());

	message_vision(CYN"$N�����a�L�b�a�W�I\n"NOR,me);
	message_vision(CYN"\n$N�C�C�q�a�W���N�_�ӡA�Q���~�ߵۨ��U��Z�x�C\n"NOR,me);
	me->move(__DIR__"kantai1");
	message_vision(CYN"$N�Q���~�ߵۺC�C���F�L�ӡC\n"NOR,me);
	message_vision(CYN"�X�W���~�w�I���L�ֵ�$N���U��Z�x�C\n"NOR,ob);
	ob->move(__DIR__"kantai3");
	message_vision(CYN"$N�Q�L�W���~�L�ֵۨ��F�L�ӡC\n"NOR,ob);

	me->delete("biwu_fighter");
	ob->delete("biwu_fighter");

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	obj=present("gongping zi", where);
	if(obj->query("fangshi")!="�ӤH��") {
		if(obj->query("start/juesai"))
			obj->jieshu_biwu(id, id1);
			obj->keep_biwu(id);
	}
	return 1;
}

int do_work()
{
	write("�o�̤���ϥγo�ӫ��O�I\n");
	return 1;
}

int valid_leave(object me, string dir)
{
	if ( !wizardp(me) && dir=="north" ) {
		return notify_fail("�A���O�Ův�����Q���u�C\n");
	}

	if ( !wizardp(me) && dir=="down" ) {
		if( me->query("biwu_fighter") )
			return notify_fail("�A���W�n��Z�F�A���n��B�ö]�C\n");
	}

	me->delete_temp("last_opponent");
	me->delete_temp("last_damage_from");
	me->remove_all_killer();

	return ::valid_leave(me, dir);
}

