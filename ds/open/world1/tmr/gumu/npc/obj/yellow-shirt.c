#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("���m", ({ "yellow shirt", "shirt" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�@����⵷�Y����m�A´�u�륩�A���O�X�ۤk�l����C\n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 5);
        }
        setup();
}

