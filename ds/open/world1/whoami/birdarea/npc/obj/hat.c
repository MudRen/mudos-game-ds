#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
        set_name(MAG"Ա�����n"NOR, ({ "fox mask", "mask"  }) ); 
         set("long","�o�O�α��H���E�����W���֩һs�������n�A���M�o�u�O�e���֡A\n"
                   "���L�٬O�P�즳�L�L�����N�C\n");
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��" ); 
                set("material","fur");
        }
                set("value",16000);
                set("armor_prop/armor",  12);
                set("armor_prop/con", 2);
                set("armor_prop/str", 3); 
                set("armor_prop/bar", 1);
                set("armor_prop/tec", 1);
                set("armor_prop/wit", -2);
                set("limit_level",40);
        setup();
}

