#include <armor.h>
#include <ansi.h>
inherit SHIELD;
void create()
{
        set_name(HIY"��������"NOR,({ "joh ji shield","shield" }) );
        set("long","�o�O�@��x�L�ҨϥΪ��޵P�A�޵P�~�[��ۤ@�Y�r��A�Q���n�ݡC\n");
        set_weight(7000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",5);
        set("material","steel");
                set("unit", "��" );
                set("value",1000);
                set("armor_prop/armor", 8);
                set("armor_prop/shield",2);
        }
        setup();
}

