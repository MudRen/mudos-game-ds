#include <armor.h>
inherit ARMOR;

void create()
{
        set_name("��l��", ({ "chain mail","mail" }) );
        set_weight(5400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long",
			"�Τ@�h�h�K�ֳs���Ӧ����@�M�˥ҡA�W���٦��ǥW�}�A��ܹL���Ǽ����A\n"
			"�o�ظ˨�b�j���������A�i��O���Ÿ˳ơA���L��W�h�t�׷|�]�����q��\n"
			"��֤F�ǡC\n");
                set("unit", "�M");
                set("material", "peel");
		set("value", 8400);
                set("armor_prop/armor", 13);
                set("armor_prop/dex",-2);
        }
        set("wear_msg","$N��W�@��$n�A�t�צn����C�F�@�ǡC");
        set("unequip_msg","$N���U�@�M$n�A���G���P�F�\�h�C");
        setup();
}