#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

void create()
{
set_name("�����",({"tiger finger","finger"}));
set_weight(32500);
     if( clonep() )
               set_default_object(__FILE__);
     else {
            set("long","\n �������������Z��, �A�X�񨭷i���ΡC\n");
            set("unit", "��");
            set("rigidity",90); //�w��
            set("material","steel"); //����
set("hammer",55);
//set("flag", (int)flag | TWO_HANDED );
//set("limit_lv",35);
set("weapon_prop/dex",2);
set("value",5520);
           }
init_hammer(847,TWO_HANDED);
  set("wield_msg", HIC"$N���X$n, �������򴤦�C\n"NOR);
  set("unequip_msg", HIB"$N�q��W���U$n, �����^�f�U�C\n"NOR);
        setup();
}



