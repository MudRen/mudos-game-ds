#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIY"�������u"NOR,({ "joh ji boots","boots" }) );
        set("long","�o�O�@��x�L�Ҭ�۪����u�A�O�Ѱʪ����֩ҽs´�Ӧ��A�ܭ@��C\n");
        set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",2);
        set("material","skin");
        set("unit", "��" );
        set("value",1250);
                set("armor_prop/armor", 7);
                set("armor_prop/shield",3);
        }
        setup();
}

