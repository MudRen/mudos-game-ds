#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;
void create()
{
	set_name(HIC"���s��"NOR, ({ "dragontail blade","blade" }) );
	set_weight(35000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���M���Y�d��A�Φp�T��ɥN�������ҨϪ��C�s����M,\n"
                            "���j���M���W��F�@���s�A���L�u���s���Ӥw�A�����D�Oԣ\n"
			    "�W���_�M�H\n");
		set("value", 35000);
		set("material", "steel");
		set("limit_skill",40);
		set("limit_str",55);
		set("limit_con",40);
		set("replica_ob",__DIR__"greatblade.c");
        }
    set("weapon_prop/bar",2);
    set("weapon_prop/tec",-2);
    set("weapon_prop/hit",-20);
    set("weapon_prop/dodge",-20);
    set("weapon_prop/dex",-4);
    init_blade(99,TWO_HANDED);
    setup();
}
void attack(object me,object target)
{
	int damage,def;

	if(me->query_skill("blade") > 50 && random(100)<10 && me->query_str() > 40 )
	{
	message_vision(HIC"$N�⤤�����s�_�M���M�H���@�h�A�n�ɤ@���s����g���ӥX�I\n" NOR,me,target);
	damage = me->query_skill("blade")+(me->query_str()/2)+random(me->query_str()/2);
	def = target->query_skill("parry")+target->query_skill("dodge")+target->query_dex()+target->query_con();
	def = def/3;
	if(damage-def>0 && random(10)>5)
	{
	message_vision(RED "$N�Ӥ��ΰ{�סA�w�Q�@�D�g�P�s��夤�I\n"NOR,target);
	target->receive_damage("hp",damage-def);
	}
	else
	{
	message_vision(YEL "$N���{�k���A�n���e�����}�F�s�𪺧����C\n"NOR,target);
	}

	}
	return;
}
