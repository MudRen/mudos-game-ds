#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name("�u�å־c", ({ "Saint boots","boots" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�o���־c�O�@��u�éҥ������窫�C\n");
                set("unit", "��");
                set("material", "cloth");
                set("value",1500);
                set("armor_prop/dex",1);
                set("armor_prop/dodge",3);
        }
        setup();
}
