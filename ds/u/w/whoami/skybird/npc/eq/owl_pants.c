#include <armor.h>
#include <ansi.h>

inherit PANTS;

void create()
{
        set_name(YEL"���Ъ���"NOR, ({ "owl pants", "pants" }));
        set_weight(3000);
        set("long","�@���α����Ф�s´�Ӧ����Ǥl�E");
        set("unit", "��");
        set("value", 1500);
        set("armor_prop/armor", 8);
        set("armor_prop/con", 1);
        setup();
}

