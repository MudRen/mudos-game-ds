#include <weapon.h>

#include <ansi.h>

inherit FIST;

void create()
{
    set_name(HIY"ģ���"NOR, ({"sun fist","fist"}));
    set_weight(5000);
    if(clonep())
    set_default_object(__FILE__);
    else {
         set("unit", "��");
         set("long", "�@����l,��������,�����]�����C\n");
         set("value", 150);
         set("wield_msg","$N��$n�M�b��W�C\n");
         set("unwield_msg","$N��$n���U�ӡC\n");
         set("weapon_prop/str", 3);
         set("weapon_prop/con", 2);
         set("weapon_prop/dex", 5);
         set("weapon+prop/int", 5); 
    }

    init_fist(70);
    setup();
}








