#include <weapon.h>
inherit GUN;
void create()
{
set_name("�x�߹p",({"hand gun","gun"}));
set("long","�o�O�@��p�����g���Z��, �@���i�H�˶�5�o�l�u�C\n");
set_weight(4600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("value",600);
		set("rigidity",500);	//�s�W: �w��
		set("material","iron");
 set("limit_lv",15);
                                set("limit_con",5);
                set("limit_int",15);
                set("limit_str",15);
//
// ����i�H�O 	limit_lv 	limit_str 
//		limit_dex 	limit_con 
//		limit_int 	limit_skill
        }

	set("wield_msg","$N�q�f�U�̮��X�@��$n, �ñN$n���O�I�˸m�Ѷ}�C\n");
	set("unwield_msg", "$N�N�⤤��$n�O�I�˸m����, �é�J�f�U���C\n");
	set("bullet_type","small");	//�i�Τl�u����
	set("max_load",5);		//�̤j�˶�q
	init_gun(10); 	// �׷i�ˮ`�O=set("weapon_prop/damage", 14);
	setup();
}
