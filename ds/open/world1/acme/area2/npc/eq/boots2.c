#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name("�¾c" ,({ "straw boots","boots" }) );
        set("long","�o�O�@���h�ճ¾c�C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(600);
        set("unit", "��");
        set("value",200);
        set("armor_prop/armor", 1);
        }
        setup();
}
