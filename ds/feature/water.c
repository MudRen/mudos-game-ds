// water.c

#include <dbase.h>
#include <name.h>

void init()
{
	add_action("do_drink", "drink");
}

int do_drink(string arg)
{
	string type,msg;
	int hp,mp,ap,k=0;
	object ob;
	if( !this_object()->id(arg) ) return 0;
	if(!arg)
	{
		notify_fail("�A�Q�ܤ���??\n");
		return 0;
	}
	
	if(!this_object()->query("no_get")) //���O��b�a�W��
	{
		ob=present(arg,this_player());
		if(ob != this_object()) return 0;
	}
	
	if( this_player()->is_busy() )
		return notify_fail("�A�W�@�Ӱʧ@�٨S�������C\n");
	if( !query("water_remaining") )
		return notify_fail( name() + "�w�g�S����i�H�ܤF�C\n");
	hp=query("heal_hp");
	mp=query("heal_mp");
	ap=query("heal_ap");
//	if(!hp && !mp && !ap)
//		return notify_fail( "���������Ʀ^�_�����C(�ݳ]�w \"heal_hp\"��\"heal_mp\"��\"heal_mp\")\n");
	if( hp || mp || ap )
	{
		if( hp && this_player()->query("hp") < this_player()->query("max_hp") ) k++;
		if( ap && this_player()->query("ap") < this_player()->query("max_ap") ) k++;
		if( mp && this_player()->query("mp") < this_player()->query("max_mp") ) k++;
		if(k==0) return notify_fail("�A�w�g�ܤӦh�F�M�A�]�ܤ��U���󶼮ƤF�C\n");
		if( query("eat_func") )	 // �L�����
		{
			message_vision("$N�ܤF�X�f" + name() + "�̪����C\n", this_player());
			if(this_player()->query("level") > query("eat_func"))
				write("�Aı�o���ܲM�D�C\n");
			else
			{
		  		if(hp)
				{
					this_player()->receive_heal("hp", hp);
				}
				if(mp)
				{
		 			this_player()->receive_heal("mp", mp);
				}
			  	if(ap)
				{
					this_player()->receive_heal("ap", ap);
				}
			  	write("�Aı�o�@�ѤO�q�y�J�F�A������C\n");
			}
			return 1;
		}
		if(hp)
		{
			this_player()->receive_heal("hp", hp);
		}
		if(mp)
		{
			this_player()->receive_heal("mp", mp);
		}
		if(ap)
		{
			this_player()->receive_heal("ap", ap);
		}
	}

	if( this_player()->is_fighting() ) this_player()->add_block(1);

	set("value", 0);
	add("water_remaining", -1);
	
	if( !query("water_remaining") )
	{
		if(!msg=query("finish_drink_msg")) msg="$N�@�f���ѤU��$n�ܭӺ���C\n";
		message_vision(msg, this_player(),this_object());
		// This allows customization of drinking effect.
		query("water/function");
		this_object()->finish_eat();
		if(this_object()) destruct(this_object());
	} else 
	{
		if(!msg=query("drink_msg")) msg="$N���_$n�ܤF�X�f�C\n";
		message_vision(msg, this_player(),this_object());
		// This allows customization of drinking effect.
		query("water/function");
	}
	return 1;
}

int is_water() { return 1; }
