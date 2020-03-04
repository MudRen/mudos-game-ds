// bullet.c

#include <dbase.h>
#include <name.h>

void init()
{
	add_action("do_reload", "reload");
}

int do_reload(string arg)
{
	string type,msg;
	object weapon,ob;
	if( !this_object() ) return 0;

	if(!arg)
	{
		notify_fail("�A�Q�˶񤰻�??\n");
		return 0;
	}
	if( !this_object()->id(arg) ) return 0;
	if(!this_object()->query("no_get")) //���O��b�a�W��
	{
		ob=present(arg,this_player());
		if(ob != this_object()) return 0;
	}

	if(!weapon = this_player()->query_temp("weapon"))
		return notify_fail("�A�èS���ϥκj�����Z���C\n");
	if( this_player()->is_busy() )
		return notify_fail("�A�W�@�Ӱʧ@�٨S�������C\n");
	if(weapon->query_temp("loaded")==weapon->query("max_load"))
		return notify_fail("�o�ӪZ�����˼u�q�w�g�O�����F�C\n");
	if(weapon->query("bullet_type")!=query("type"))
		return notify_fail("�o�ӪZ���L�k�ϥγo�ؼu�ġC\n");

	weapon->set_temp("loaded",weapon->query_temp("loaded")+query("amount"));
	if(weapon->query_temp("loaded") > weapon->query("max_load"))
		weapon->set_temp("loaded",weapon->query("max_load"));

	weapon->set_temp("bullet",query("bullet"));	//���[�ݩʩ�j�W
	
	if( this_player()->is_fighting() ) this_player()->start_busy(2);
		else this_player()->start_busy(1);
	
	if(stringp(msg=query("load_msg")))
		message_vision(msg+"\n", this_player(),this_object());
	else message_vision("$N���X$n, ���m���ˤJ"+weapon->name()+"���C\n", this_player(),this_object());
	tell_object(this_player(),weapon->name()+"�ثe���s�u�q��"+weapon->query_temp("loaded")+"�o�C\n");

	destruct(this_object());
	return 1;
}

