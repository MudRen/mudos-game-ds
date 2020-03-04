#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name("��¤��C",({"darkfool sword","sword"}) );
	set("long",@long
�@��ݨӫD�`�K�ª����C�A�צp���¡B�I�R���t�z�@��A�@�L�j�۵M
���;��A�O�H�H�ߡC�o�f���C�۶Ǭ��Ʀʦ~�e�A�@��t�z���I�a�Сu���
�̥ʡv�A��@�������u���§Q�P�y�s�v���u�s���¬}�v���ұo�쪺�u����
���q�ۡv��ű�Ӧ����C�ڻD���C��e����D�H���]�k�O�A�Ӧ���j�O����
���O�A�A���T�Q�ո�....(powerin)
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
}
void attack(object me,object target)
{

int damage,str,dex;

if(this_object()->query_temp("power") )
{
	str = me->query("str");
	dex = me->query("dex");
	damage=(str+dex)*(1+random(10));

	message_vision("                  �B�E���ɾԩ��M�o�X�j�j�����~

                       �q�ѤW�l��Ӥ@�}�B�r

              �V$N���h�I�I�I�y��$N"+damage+"�I���ˮ`�I�I�I�I\n",me
	);
	this_object()->set_temp("power",0);
   return;
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
