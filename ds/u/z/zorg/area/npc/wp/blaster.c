#include <weapon.h>
#include <ansi.h>
inherit GUN;

void create()
{
set_name(HIG"�p�g�B�j"NOR,({"blaster rifle","rifle"}));
set("long","�o�ONaboo�u�ê��M�κj�C\n");
set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("value",2000);
		set("rigidity",800);	//�s�W: �w��
		set("material","iron");
//
// ����i�H�O 	limit_lv 	limit_str 
//		limit_dex 	limit_con 
//		limit_int 	limit_skill
//
		set("limit_str",10);
        }

	set("wield_msg","$N�q�I�᮳�X�@��$n�C\n");
	set("unwield_msg", "$N�N��W��$n��^�I��C\n");

//  weapon_prop/dex
//  weapon_prop/str
//  weapon_prop/int
//  weapon_prop/con
//  weapon_prop/hit	�R���v
//  weapon_prop/parry	�۬[�v
//
	set("bullet_type","blaster rifle");	//�i�Τl�u����
	set("max_load",20);		//�̤j�˶�q
	init_gun(15); 	// �׷i�ˮ`�O=set("weapon_prop/damage", 14);
	setup();
}
