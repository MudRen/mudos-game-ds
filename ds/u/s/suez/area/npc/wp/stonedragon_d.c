#include <weapon.h>
#include <ansi.h>
inherit DAGGER;
void create()
{
set_name("���s��",({"stone-dragon teeth","teeth","dagger"}));

set_weight(2500);
          if( clonep() )
                      set_default_object(__FILE__);
          else {
set("long","�o�O�q�ǻ��������s���W���o�������A�ӳo���O�g�ѦW�K��\n"
              "�ߥ��y�Ӧ��A�������Y�몺�C��o���o�X�ï]�몺���A�C\n");
set("unit", "��");
set("value", 3000);
set("material","rock");

set("limit_str",15);
set("limit_dex",10);

set("wield_msg", "$N�N$n�ѶH���T�����X�A�X�M�����A�M�b�A���y�W�C\n");
set("unwield_msg","$N�p���l�l���N$n��^�H���T���C\n");

set("weapon_prop/parry",15);
set("weapon_prop/hit",10);
init_dagger(25);
setup();
}
}                      
