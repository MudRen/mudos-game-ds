#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("��������" ,({ "cloth" }) );
        set("long","�o�O�@��h�Q�諸����C\n");
        set_weight(800);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "cloth");
        set("unit", "��" );
        set("value",200);
        }
         set("armor_prop/armor",2);
        setup();
}
