#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIC"���v�x�u"NOR, ({ "boots" }) );
        set_weight(3600);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","�@�����v��ۧ@�Ԫ��u�l, �۷�p��!.\n");
                set("unit", "��");
                set("material","fur");
	set("value",145);
                set("weapon_prop/dex",-1);
	set("weapon_prop/con",1);
                set("armor_prop/armor", 8);
        }
        setup();
}
