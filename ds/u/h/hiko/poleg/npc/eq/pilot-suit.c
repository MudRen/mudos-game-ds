#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("����A", ({ "pilot suit","suit" }) );
        set_weight(5000);
        set("material","cloth");
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","�@�󵹤���̬諸�M�Φ�A�A�W�����G���۪��y��r.\n");
                set("unit", "��");
        set("value",100);
                set("material", "cloth");
                set("armor_prop/armor", 10);
        }
        setup();
}


