#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
        set_name(HIC"��ԥ�"NOR, ({ "soul armor","armor" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
				set("long","�@��ѻ�Ҿ��E�Ӧ����Z�ҡA�S���T�w������A�ܤƵL�`�C");
                set("unit", "��");
                set("value",10000);
        }
		set("armor_prop/armor", 25);
        set("armor_prop/con", 1);
        set("armor_prop/str", 1);
        set("armor_prop/dex", -2);
        setup();
}

