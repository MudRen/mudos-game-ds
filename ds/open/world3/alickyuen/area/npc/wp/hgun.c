#include <weapon.h>
inherit GUN;
void create()
{
set_name("�x�߹p",({"hand gun","gun"}));
set("long","�o�O�@��p�����g���Z��, �@���i�H�˶�5�o�l�u�C\n");
 set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
          set("value",100);
		set("rigidity",500);	//�s�W: �w��
		set("material","iron");
        }

	set("wield_msg","$N�q�f�U�̮��X�@��$n, �ñN$n���O�I�˸m�Ѷ}�C\n");
	set("unwield_msg", "$N�N�⤤��$n�O�I�˸m����, �é�J�f�U���C\n");
	set("bullet_type","small");	//�i�Τl�u����
	set("max_load",5);		//�̤j�˶�q
	init_gun(10); 	// �׷i�ˮ`�O=set("weapon_prop/damage", 14);
	setup();
}
