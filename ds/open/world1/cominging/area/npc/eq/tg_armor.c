#include <armor.h>
inherit ARMOR;

void create()
{
        set_name("���Z��", ({ "leathery armor","armor" }) );
        set_weight(5400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long",
            "�Τ��֩Ұ������Z�ҡA��A��۳o���Z�ҡA�N�|�D��W���@�P��\n"
			"�{���A���A���Ǥ��ӷQ��U�h�A���L�`��o�ӽçL�o���w�ߥH��\n"
                        "�`�A�Z�ҫ᭱�ٵe�F�Ӥj�j���@�Ӧr�u�B�v�C\n");
		set("volume",3);
		set("material","leather");
                set("unit", "�M");
                set("material", "peel");
		set("value",1800);
                set("armor_prop/armor", 9);
                set("armor_prop/con",1);
        }
        set("wear_msg","$N��W�@��$n�A���G�D�쨺�@�P���������D�C");
        set("unequip_msg","$N���U�@�M$n�A���G���P�F�\\�h�C");
        setup();
}
