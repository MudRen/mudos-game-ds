#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIY"���t�ԥ�"NOR, ({"holy armor", "armor"}) );
        set("long",@LONG
�o�O�@��g�L���t�~§���Z�ҡA��W���i�o�쯫�t���O�q�C
LONG
);
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��" );
                set("armor_prop/armor", 25);
                set("armor_prop/str", 4);
                set("armor_prop/con", 2);
                set("armor_prop/shield", 40);
                set("material","silver");
                set("limit_str", 35);
             }
        setup();
}

