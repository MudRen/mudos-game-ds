#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name("���K�Z" ,({ "steel armor","steel","armor" }) );
        set("long","�o�O�ί¿��ҷҦ����Z�ҡC\n");
	set_weight(12000);
        if ( clonep() )
	set_default_object(__FILE__);
        else {
              set("material", "armor");
	set_weight(3000);
	set("value", 4000);
	set("limit_str",15);
	set("unit", "��" );
        set("material","steel");
	set("armor_prop/dodge", -2);
        set("armor_prop/armor", 20);
        set("armor_prop/shield", 5);
        }
        setup();
set("wear_msg", HIG"$N��$n��b���W�A�P��o�Z�ҤQ���I���E\n"NOR);

}	
