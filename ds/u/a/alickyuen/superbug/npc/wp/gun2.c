#include <weapon.h>
inherit GUN;
void create()
{
set_name("����",({"hand gun","gun"}));
set("long","�o�O�@��p�����g���Z��, �@���i�H�˶�5�o�l�u�C\n");
set_weight(4600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("value",600);
		set("rigidity",500);	//�s�W: �w��
		set("material","iron");
        }

	set("wield_msg","$N�q�f�U�̮��X�@��$n, �ñN$n���O�I�˸m�Ѷ}�C\n");
	set("unwield_msg", "$N�N�⤤��$n�O�I�˸m����, �é�J�f�U���C\n");
	set("bullet_type","hand");	//�i�Τl�u����
	set("max_load",30);		//�̤j�˶�q
	init_gun(5); 	// �׷i�ˮ`�O=set("weapon_prop/damage", 14);
	setup();
}
