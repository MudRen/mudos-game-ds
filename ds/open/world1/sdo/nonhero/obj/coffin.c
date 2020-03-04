#include <ansi2.h>
inherit ITEM;
	
void create()
{
        set_name("�ä�", ({"coffin"}) );
        set("long",@LONG
�b�A���e����ۤ@�㥨�j���ä�A���L�_�Ǫ��O�̭��n���i�H��F��
(putting xxx)�C����L�W�^��������b���̡H�������n�Ω۳�(summon)
���H
LONG
	);
        set_weight(1000);
        set_max_capacity(4);
        set_max_encumbrance(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
	set("no_get",1);
	set("no_drop",1);
        set("unit", "��");
        set("volume",1000);
        set("value",500);
        }
        setup(); 
}

void init()
{
	add_action("summon_hero","summon");
	add_action("putting_eq","putting");
}

int putting_eq(string str)
{
	object me=this_player();
	object ob;

	if(str=="armor")
	{
	if(!ob=present("rusty armor",me))
		{return notify_fail("�o�˪F��O�����i�h���C\n");}

	if(this_object()->query_temp("armor")==1)
		{
		write("�w�g����L�F�I\n");
		return 1;
		}
		destruct(ob);
		message_vision(
		HIW"$N�ݨ첯���ܦ��@�D�ե������C\n"NOR,me);
		set_temp("armor",1);
		return 1;
	}

	if(str=="pike")
	{
	if(!ob=present("rusty pike",me))
		{return notify_fail("�o�˪F��O�����i�h���C\n");}

	if(this_object()->query_temp("pike")==1)
		{
		write("�w�g����L�F�I\n");
		return 1;
		}
		destruct(ob);
		message_vision(
		HIW"$N�ݨ���j�ܦ��@�D�ե������C\n"NOR,me);
		set_temp("pike",1);
		return 1;
	}

	if(str=="leggings")
	{	
	if(!ob=present("rusty leggings",me))
		{return notify_fail("�o�˪F��O�����i�h���C\n");}

	if(this_object()->query_temp("leggings")==1)
		{
		write("�w�g����L�F�I\n");
		return 1;
		}
		destruct(ob);
		message_vision(
		HIW"$N�ݨ��H���ܦ��@�D�ե������C\n"NOR,me);
		set_temp("leggings",1);
		return 1;
	}

	if(str=="shield")
	{
	if(!ob=present("broken shield",me))
		{return notify_fail("�o�˪F��O�����i�h���C\n");}

	if(this_object()->query_temp("shield")==1)
		{
		write("�w�g����L�F�I\n");
		return 1;
		}
		destruct(ob);
		message_vision(
		HIW"$N�ݨ�޵P�ܦ��@�D�ե������C\n"NOR,me);
		set_temp("shield",1);
		return 1;
	}
}

int summon_hero(string str)
{
	if(this_object()->query_temp("opened") != 0) return 0;
	
	if(str=="hero" || str=="�^��" || str=="�L�W�^��")
	{
	object me,b;
	me=this_player();

	message_vision(
	HIW"\n$N�C�Y��D�G�L�W�^���֥X�ӡI�֥X�ӡI�A�����}�̨ӤF�I\n"NOR,me);

	if(this_object()->query_temp("shield")==1 && this_object()->query_temp("armor")==1 && this_object()->query_temp("pike")==1 && this_object()->query_temp("leggings")==1)
	  {
	  message_vision(
	  HIW"$N�ݨ��@�D�ե��Ѵä줤���g�ӥX�A�åB�������@�ӤH���A��ӬO�L�W�^���^�F�X�{�F�I\n"NOR,me);

	  b=new(__DIR__"npc/none_hero.c" );
	  b->move(environment(this_object()) );
	  delete_temp("pike");
	  delete_temp("shield");
	  delete_temp("armor");
	  delete_temp("leggings");

            //set_temp("opened",1);
	  return 1;
	  }
	else
	  {
	  message_vision(
	  HIW"$N�o�{����Ƴ��S�o��...�C\n"NOR,me);
	  }
	return 1;
	}
}
