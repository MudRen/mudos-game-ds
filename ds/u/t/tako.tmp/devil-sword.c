#include <weapon.h>

#include <ansi.h>

inherit SWORD;

void create()
{
    set_name(HIR"�g��"MAG"�]"HIW"�C"NOR, ({"devil sword","sword"}));
    set_weight(5000);
    if(clonep())
    set_default_object(__FILE__);
    else {
         set("unit", "��");
         set("long", "�t�ѬɲĤT�رڳ̼F�`���@��C�C\n");
         set("value", 3000);
         set("wield_msg", "$N"HIW"�B�ΤF�Ѧa���O�q,�@�ٶ��ť��|��,�@��$n"HIW"�N�b��W�F�C\n");
         set("unwield_msg", "$N"HIW"��ܤ@�n,�⤺�l���h,$n"HIW"�����~�]�H�����u�F�C\n");
         set("weapon_prop/str", 2);
         set("weapon_prop/con", 2);
         set("weapon_prop/dex", 3);
         set("weapon_prop/int", 1);
         set("weapon_prop/dodge", 40);
  }
    init_sword(99);
    setup();
}
