#include <weapon.h>

#include <ansi.h>

inherit AXE;

void create()
{
    set_name(MAG"���H��"NOR, ({"big axe","axe"}));
    set_weight(5000);
    if(clonep())
    set_default_object(__FILE__);
    else {
         set("unit", "��");
         set("long", "�@�⥨�������Y,�¤O�j,���ˤO�i��]���p�C\n");
         set("value", 150);
         set("wield_msg","$N��$n�򴤦b��W�C\n");
         set("unwield_msg","$N��$n��U�ӡC\n");
         set("weapon_prop/str", 3);
         set("weapon_prop/con", 1);
         set("weapon_prop/dex", 2);
         set("weapon_prop/int", 2); 
    }
    init_axe(65);
    setup();
}









