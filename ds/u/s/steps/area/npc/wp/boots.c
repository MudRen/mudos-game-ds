#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIC"�ѨϦйu"NOR,({ "angel-feather boots","boots" }) );
        set("long",HIY"�ǻ��O�ѤѨϤ��l���Ф�y�����u�C\n"NOR);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(700);
        set("material", "feather");
        set("unit", "��" );
        set("value",10000);
        set("armor_prop/armor", 4);
        set("limit_dex",40);
        set("armor_prop/dex", 6);
        set("armor_prop/int", 6);
        }
        setup();
}
