#include <armor.h>
inherit BOOTS;
void create()
{
	set_name("�L�����u", ({ "boots" }) );

	set_weight(300);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long",
			"�@�ؤh�L�M�Ϊ��c�l�A���L���\�A�ä�����K��ʡA��\n"
			"�L���m�O�]�]���W�[�F���֡C\n");
		set("unit", "��");
		set("value" , 1020);
		set("armor_prop/armor", 6);
		set("armor_prop/shield", 3);
		set("armor_prop/dex",-1);
	}
	set("wear_msg","$N��W�@��$n�A���G��ʦ��Ǫ��w�C�C");
	set("unequip_msg","$N��U�F�@��$n�A��ʤS��_�F�I");
	setup();
}
