#include <armor.h>
inherit CLOTH;
void create()
{
        set_name( "�D��", ({ "snake cloth","cloth","snake" }) );
	set("long","�o�O�@��q�D���W���U�Ӫ��֡A�i�Ѭ�ۡA�ݰ_�Ӧ��G�ܨI���C\n");
        set_weight(2900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
		set("value", 100);
		set("volume",3);
	set("material","fur");
                set("armor_prop/armor", 2);
        }
        setup();
}
