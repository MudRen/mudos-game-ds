#include <weapon.h>

#include <ansi.h>

inherit SWORD;

void create()
{
    set_name(HIC"�F�O"HIW"�C"NOR, ({"power sword","sword"}));
    set_weight(5000);
    if(clonep())
    set_default_object(__FILE__);
    else {
         set("unit", "��");
         set("long", "�@�Ⲥ�e�H�Ŧ⪺��C,���S���@�ػ����X�Ӫ��z���P�C\n");
         set("value", 150);
         set("wield_msg", "$N���k�}��,���M�ť��|��,�@��$n�N�b����W�F�C\n");
         set("unwield_msg", "$N��ܤ@�n,�⤺�l���h,$n�����~�]�H�����u�F�C\n");
         set("weapon_prop/str", 2);
         set("weapon_prop/con", 2);
         set("weapon_prop/dex", 3);
         set("weapon_prop/int", 1); 
         set("weapon_prop/dodge", 40);
    }
    init_sword(99);
    setup();
}








