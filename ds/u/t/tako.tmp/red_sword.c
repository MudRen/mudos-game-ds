#include <weapon.h>

#include <ansi.h>

inherit SWORD;

void create()
{
    set_name(HIR"����"HIW"�C"NOR, ({"down-red sword","sword"}));
    set_weight(5000);
    if(clonep())
    set_default_object(__FILE__);
    else {
         set("unit", "��");
         set("long", "�@�Ⲥ�e�H���⪺��C,���S���@�ػ����X�Ӫ��z���P�C\n");
         set("value", 150);
         set("wield_msg","$N���k�}��,���M�����|��,�@��$n�N�b�A������W�C\n");
         set("unwield_msg","$N�ܤ@�n��,�⤺�l���h,$n�����~�]�H�����u�F�C\n");
         set("weapon_prop/str", 3);
         set("weapon_prop/con", 2);
         set("weapon_prop/dex", 5);
         set("weapon+prop/int", 5); 
    }
    init_sword(70);
    setup();
}








