#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(MAG"�Ѫ���"NOR,({ "tengu fur","fur" }));
        set_weight(1300);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","�ǻ��������H�y�Ѫ��z���W���֡A���G�i�H�諸�ˤl�E\n");
                set("unit","�i");
                set("value",700);
                set("material","fur");
        }
                set("armor_prop/shield",10);
                set("armor_prop/armor", 15);
                set("armor_prop/con",2+random(2));

        setup();
}

