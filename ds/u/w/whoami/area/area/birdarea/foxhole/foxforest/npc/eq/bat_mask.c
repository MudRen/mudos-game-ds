#include <armor.h>
#include <ansi.h>
inherit MASK;

void create()
{
        set_name(HIW+BLK"���έ��n"NOR,({ "bat mask","mask" }) );
        set("long","�o�ӭ���~�ι��ӱi�}���l�������A�৹���O�@�y���E\n");
        set_weight(780);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material","fur");
        set("unit","�i");
        set("value",780);
        set("limit_lv",25);
        set("limit_int",15);
        }
        set("armor_prop/armor",5);
        set("armor_prop/str",2);
        set("armor_prop/con",1);
        setup();
}

