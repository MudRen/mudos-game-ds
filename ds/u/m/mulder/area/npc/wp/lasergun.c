#include <weapon.h>
#include <ansi.h>
inherit GUN;

void create()
{
set_name(HIG"�E���j"NOR,({"laser gun","gun"}));
set("long","�o�O�@�⥼�ӱ`�Ϊ��j�C\n");
set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("value",800);
		set("rigidity",500);	//�s�W: �w��
		set("material","iron");
//
// ����i�H�O 	limit_lv 	limit_str 
//		limit_dex 	limit_con 
//		limit_int 	limit_skill
//
		set("limit_int",6);
		set("limit_str",7);
        }

	set("wield_msg","$N�q�j�U�̮��X�@��$n�C\n");
	set("unwield_msg", "$N�N�⤤��$n��^�j�U�C\n");

//  weapon_prop/dex
//  weapon_prop/str
//  weapon_prop/int
//  weapon_prop/con
//  weapon_prop/hit	�R���v
//  weapon_prop/parry	�۬[�v
//
	set("bullet_type","laser");	//�i�Τl�u����
	set("max_load",10);		//�̤j�˶�q
	init_gun(10); 	// �׷i�ˮ`�O=set("weapon_prop/damage", 14);
	setup();
}
