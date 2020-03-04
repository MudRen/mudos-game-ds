// �Ϯ��]�q��	In room121.c
#include <path.h>
#define Base_Copy_Value	5

inherit ITEM;

object bookroom;

void create()
{
	set_name("�Ϯ��]�v�L��",({"library photostat","photostat"}) );
	set("long",@LONG
�o�x�v�L���ݰ_�ӫD�`������(�v�L�O�j���]���K�y)�A�p�G�ݭn
�v�L��ơA�䥦�N�S���F�C

	copy [���������ȱi�����x�W��] [����]
LONG
	);
	set_weight(15000);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("value",75000);
		set("unit","�x");   //luky
	}
	set("no_get",1);
	set("no_sac",1);

	setup();
}

void init() 
{
	add_action("do_copy","copy");
}

int do_copy(string arg)
{
	object me,ob,ob2;
	int i,no,value;
	string papername,filename;

	me = this_player();

	if(!arg)
		return notify_fail("copy [���������ȱi�����x�W��] [����]\n");
	if(sscanf(arg,"%d",no))
		return notify_fail("copy [���������ȱi�����x�W��] [����]\n");
	if(!sscanf(arg,"%s %d",papername,no))
	{
		papername = arg;
		no = 1;
	}
	if( no > 10 )
		return notify_fail("��p...���v�L���@���u������Q���H��������...\n");

	value = Base_Copy_Value * no;

	if(ob=present(papername,me))
	{
		if(!ob->can_copy())
		{
			write(ob->query("name")+"�ä���b�o�̫�����I\n");
			return 1;
		}

		if( me->can_afford(value)!=1 )
		{
			write("�A�a����������I\n");
			return 1;
		}

		me->receive_money(-value);
		message_vision("$N�N"+F_VENDOR->price_string(value,me->money_type())+"��J$n�̡C\n",me,this_object());

		if(sscanf(base_name(ob),"%s_c",filename)==1)
			filename = base_name(ob);
		else
			filename = base_name(ob)+"_c";

		for(i=0;i<no;i++)
		{

			ob2 = new(filename);
			if( ob2->can_move(me) )
			{
				if(ob2->move(me))
					message_vision("$N��$n�����F�@��" + ob2->query("name") + "�C\n", this_object(), me);
				else if(ob2->move(environment(me)))
					message_vision("$N��$n�����F�@��" + ob2->query("name") + "�A���L�]��$n������ӱ����ܦa���W�C\n", this_object(), me);
				else
				{
					destruct(ob2);
					message_vision("������...$N�~�M�Q$n���a�F�C\n", this_object(), me);
				}
			}
			else if(ob2->move(environment(me)))
				message_vision("$N��$n�����F�@��" + ob2->query("name") + "�A���L�]��$n������ӱ����ܦa���W�C\n", this_object(), me);
			else
			{
				destruct(ob2);
				message_vision("������...$N�~�M�Q$n���a�F�C\n", this_object(), me);
			}
		}	
	}
	else
		write("�A�èS�� "+ papername +" ��!!\n");
	return 1;

}