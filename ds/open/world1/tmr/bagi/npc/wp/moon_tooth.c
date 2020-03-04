#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
	set_name("���",({"moon tooth","tooth"}));
	set("long",@LONG
�o�O�@�ڪ����C�T�{�{�o�G���y�U�~���C�A�ݨ�����W���ɦa�{
ģ�۲H�H�޲����C���A���G���_�a�������񪺤���C����W���o�X��
���H��ϤH�����@��a���A�G���������C

LONG
);
	set_weight(8600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("material","gem");
		set("no_sac",1);
        }
        set("value",2380);
        set("volume",1);
        
    	set("monster_weapon_prop/bio",1);
    	set("monster_weapon_prop/sou",-1);
	set("monster_weapon_prop/dodge",7);
    	set("monster_weapon_prop/hit",12);
    	set("monster_weapon_prop/damage",43);
    	
    	set("weapon_prop/bio",1);
    	set("weapon_prop/sou",-1);
	set("weapon_prop/dodge",7);
    	set("weapon_prop/hit",12);
	set("backstab_bonus",49);
	
	set("wield_msg",HIC"$N�N$n��򴤦�A�������o�X���H�H��C\n"NOR);
	set("unwield_msg", "$N�N�⤤��$n��U�A��H���H��]���������F�C\n");
	
	init_dagger(43);
        setup();
	
}

void attack(object me,object victim)
{
        ::attack();
	if(!me) return;
	if(!victim) return;
	if(me->is_busy()) return;
         if( userp(me) && random(10) != 1 ) return;
       if(random(20) !=1 ) return;
	if(!victim->query_temp("heat"))
	{
message_vision(HIC"  $N"+HIC"�⤤�������M�g�X�@�ѴH��A$n"+HIC "�Q�H��g���ʧ@��o���ǿ�w�C\n"NOR,me,victim);
		victim->add_busy(1+random(2));
           victim->apply_condition("coldmoon_poison",3);
	}
	return;
}


