#include <weapon.h>

#include <ansi.h>

inherit SWORD;

void create()
{
    set_name(HIW"��"HIG"��"HIW"�C"NOR, ({"wind sword","sword"}));
    set_weight(5000);
    if(clonep())
    set_default_object(__FILE__);
    else {
         set("unit", "��");
         set("long", "���o�X�}�}�D�����C,�����L��C\n");
         set("value", 200);
         set("wield_msg","$N�ۭ�������F�४��,�����ӤW,�e�X�@��$n�C\n");
         set("unwield_msg","$N����@�P,$n�H�����h�F�C\n");
         set("weapon_prop/con", -3);
         set("weapon_prop/dex", 4);
    }
    init_sword(64);
    setup();
}









