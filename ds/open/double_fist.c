#include <weapon.h>
#include <combat.h>
#include <ansi.h>
inherit FIST;
void create()
{
	set_name(HIG"�ƶ����s��"NOR, ({ "double fist","fist" }) );
	set_weight(14820);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG

�o�O�@�ư�w�����M�A�W���^�۫ܺ���������s���J��A������
���ˤF�@�Ӥp��ޡA�i�H���Ѹ˳ƪ̨ǳ\�����@�O�C
[�i�x�s�˳�]
LONG
);
		set("value", 4170);
		//set("no_sell",1);
		set("no_sac",1);
		set("material", "iron");
	}
    set("weapon_prop/bar",1);
    set("weapon_prop/hit",4);
    set("weapon_prop/parry",12);
    set("weapon_prop/armor",5);
    set("weapon_prop/shield",2);
    init_fist(20);
    setup();
}

void attack(object me,object victim)
{
	if(!me) return;
	if(!victim) return;
	if(me->is_busy()) return;
	if(random(3)) return; // 1/3 �����v�s��
	COMBAT_D->do_attack(me, victim, this_object(), TYPE_REGULAR);
	return;
}

int query_autoload() { return 1; }