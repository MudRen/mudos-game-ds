#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
        set_name(MAG"Ա�����n"NOR, ({ "fox mask", "mask"  }) );
        set("long","�o�O�α��H���E�����W���֩һs�������n, ���M�o�u�O
�e����, ���L�٬O�P�즳�L�L�����N�C\n");
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�i" );
                set("armor_prop/armor",  10);
                set("armor_prop/int", 3);
                set("limit_level",10);
                set("material","fur");
        }
        setup();
}
