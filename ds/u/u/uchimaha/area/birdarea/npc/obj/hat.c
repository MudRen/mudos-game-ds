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
                set("unit", "��" );
                set("value",20000);
                set("armor_prop/armor",  12);
                set("armor_prop/con", 2);
                set("armor_prop/str", 3);
                set("limit_level",15);
                set("material","fur");
        }
        setup();
}
