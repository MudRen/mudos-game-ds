#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIW"���I����"NOR ,({ "dkfum" }) );
        set("long","�o�O���I���W��U�Ӫ��֡C\n"NOR);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(100);
        set("no_sac",1);
        set("material", "peel");
        set("unit", "�i" );
                set("value",10);
        }
        set("armor_prop/armor", 1000);
        set("armor_prop/id",({"Dkfum"}));
        set("armor_prop/name",({"���I"}));
        set("armor_prop/short",({"���I(Dkfum)"}));
set("armor_prop/long",({"�ݰ_�ӴN�ܤ����ǤH�C\n"}));
        setup();
} 

