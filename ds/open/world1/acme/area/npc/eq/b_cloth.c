#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("�P��" ,({ "buddha's cloth","cloth" }) );
        set("long","�o�O�M�|���ɬ�۪���A�C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(1200);
        set("material", "cloth");
        set("unit", "��" );
        set("value",1200);
        }
        set("armor_prop/armor", 6);
        set("armor_prop/dodge", 6);
        setup();
}
