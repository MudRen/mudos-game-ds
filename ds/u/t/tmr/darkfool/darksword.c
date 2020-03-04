#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit SSERVER;

void create()
{
	set_name("��¤��C",({"darkfool sword","sword"}) );
	set("long",@long
�@��ݨӫD�`�K�ª����C�A�צp���¡B�I�R���t�z�@��A�@�L�j�۵M
���;��A�O�H�H�ߡC�o�f���C�۶Ǭ��Ʀʦ~�e�A�@��t�z���I�a�Сu���
�̥ʡv�A��@�������u���§Q�P�y�s�v���u�s���¬}�v���ұo�쪺�u����
���q�ۡv��ű�Ӧ����C�ڻD���C��e����D�H���]�k�O�A�Ӧ���j�O����
���O�A�A���T�Q�ո�(powerin)�άO(stone)
long
	);
	set_weight(200);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
	set("unit","��");
	set("wield_msg","$N�u��v�@�n�A�q�y����X�@�⺣�ª��C���b��W�C \n");
	set("value",500);
	set("material","iron");
	set("limit/str",30);
	set("weapon_prop/hit",30);
	set("weapon_prop/parry",30);
	set("weapon_prop/int",10);
	}
	init_sword(20);
	setup();	
}

void init()
{
	add_action("do_powerin","powerin");
	add_action("do_stone","stone");

}

void attack(object me,object target)
{
	int i;
	int kee;
	int skee;
	skee=this_object()->query_temp("swordkee");

	i=random(10);
	kee=random(2)+1;

	if(this_object()->query_temp("power") )
	{
	message_vision(HIW"\n\n$N�⤤����¤��C���o�s�u���S�A�n�ɼC��|�g�A����"+target->query("name")+"�R���n�`�I�I\n\n "NOR,me);
	if (i==0)
		message_vision(HIY"$N��d�v�@�v���ڡA���Ƹ��L�C�𪺰l���A�ݨӨõL����jê�C\n"NOR,target);
	else
	{
		message_vision(HIR"�u��$N��۾׬[����A���ͥͦa���F�C��|�D���A�r�M�R�F�@�j�f�A��A�ݨӨ��ˤ����C\n"NOR,target);	
		target->set("wound/body",2);
	}
	this_object()->set_temp("power",0);
	}

// ��԰��L�{���A�s�C��.....
	if(random(2) ) //�üƨM�w�A1/3 �����v���s�C��..
	{
		if (me->query("mp") > 50)
		{
		tell_object(me,HIM"�Aı�o����@�}�F�O�A�u��¤��C�v���G�l���F�A�@���]�k�O...\n"NOR);
		tell_object(me,HIC "�l�����]�k�O->"+kee+"  �C��->"+ skee+"\n"NOR);        //�[�o��u�O���F��K�d��...
		this_object()->set_temp("swordkee",skee+kee);
		me->add("mp",-kee);
		if(skee>30) 
 			tell_object(me,HIR"�A�Pı�⤤���u��¤��C�v�E�P�a�ݰʡA���G���w�l���A�ҵ����]�k�O.......\n"NOR);
		}
	}

	if(this_object()->query_temp("kee_ok") )
	{
		tell_object(me,HIG"��¤��ۡv���զ��\...\n" NOR);
		this_object()->delete_temp("kee_ok");
		this_object()->add_temp("swordkee",-30);
	}
}

int do_powerin(string arg)
{
	object me,obj;
	me=this_player();
	obj=this_object();

 	if(arg) return 0;
	if(me->query("mp") <200) return notify_fail("�A���]�k�O�����A����[���C\n");
	if(me->is_busy() ) return notify_fail("�A�{�b�S���šI\n");
	if(me->query_temp("powering") ) return notify_fail("�A�w�b�[���k�O�F�C\n");
	me->set_temp("powering",1);
	me->start_busy(5);
	message_vision(HIW"\n\n       $N�򴤵ۼC�`�A���a��D�G�u�s���j�j...�н絹�گ������O�q����v\n"NOR,me);
	message_vision(HIG"\n�u��$N������o�X�@�}�}��⪺���t���~�A�����a�]�����¤��C�C\n"NOR,me);
	call_out("powerin_msg",5,me,obj);			
	return 1;
}

int powerin_msg(object me,object obj)
{
	int i;
	if(!me) return 0;
	i=random(10);
	me->add("mp",-100);	
	message_vision(HIG "\n�u����¶����¤��C����⯫�t���~�����a�Q�C�ҧl���F....\n" NOR ,me);
	
	if(i<2)
	{	
		tell_object(me,BLU"�Aı�o�A����`���]�k�O�Ѧp�ۨH�j���@�h�L��.....\n"NOR);
	}	
	else
	{
		tell_object(me,BLU"���L�A���W�a�[������A��¤��C���G����oģ���B�W�U�C\n"NOR);
	}

	obj->set_temp("power",1);
	me->delete_temp("powering");
	return 1;
}

int do_stone()
{
	if(!this_player()->is_fighting() ) return notify_fail("�u��¤��ۡv����԰����~��ϥΡC\n");
	if(this_object()->query_temp("swordkee") >30 )
	{
		message_vision(HIB"�u��$N�⤤�Ҵ����u��¤��C�v�o�X�@�D�{���C\n"NOR,this_player() );
		this_object()->set_temp("kee_ok",1);
	}
	else
		return notify_fail("��¤��C���x�s���]�k�O�����A����ϥΡu��¤��ۡv�C\n");
	return 1;
}