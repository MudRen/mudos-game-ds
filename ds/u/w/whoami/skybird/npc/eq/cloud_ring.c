#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(HIG"������"NOR, ({ "cloud ring","ring" }) );
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","�o�O���Q�q�L�����Y�@�j�᦬�Ӫ��Ǯa���_..\n");
                set("unit", "�u");
	set("value",10000);
	set_weight(600);
              set("material","jade");
                set("armor_prop/armor", 3);
	 set("armor_prop/int",2);
	 set("armor_prop/con",1);
        }
        setup();
}
