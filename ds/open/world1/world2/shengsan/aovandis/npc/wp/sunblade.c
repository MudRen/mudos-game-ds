#include <weapon.h>
#include <combat.h>
inherit BLADE;

void create()
{
set_name("�P��M",({"sun blade","blade"}));
set("long",@LONG
�@����ⴤ�`���j�M�C�M���W�����Ū��Y���K�A�M�`��
����ô�F�@�������I�զ⪺�v�a�A�A�A�J�Ӥ@�ݤ~���D���O
�@���������C
[�i�x�s�˳�]
LONG
);
	set_weight(11300);   //�]���q
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("material","iron");
		set("no_sac",1);
        }
        set("value",5480);
    	set("weapon_prop/bar",1);
    	set("weapon_prop/sou",-1);
	set("weapon_prop/parry",5);
    	set("weapon_prop/blade",6);
	set("backstab_bonus",36);
	init_blade(22);
	setup();
}

void attack(object me,object victim)
{
        ::attack();
	if(!me) return;
	if(!victim) return;
	if(me->is_busy()) return;
	if(random(9)) return; // 1/9 �����v�s��
	COMBAT_D->do_attack(me, victim, this_object(), TYPE_REGULAR);
	return;
}

int query_autoload() { return 1; }
