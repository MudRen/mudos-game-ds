#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
  set_name(HIR"�岴"WHT"�s��"NOR ,({ "blood-eye-dragon armor","armor" }) );
  set("long",@LONG
    �o�O�W�j�c�s�Ц岴�f���s���W���֥ҡA�۷����ӫp���C
�W�j�ɥN�c�s���A���M�j�N�H�N�岴�f���s�I�æb�d�h�����A��
�]���j�N�ʥF�W�Q�Z���A�õL�k��z�c�s�֥ҳy���P�R�ˮ`�A�ɭP
�c�s�h�񥼦��C�Ӵc�s���֥Ҹg���Ƥd�~���ɥ��ܱo��[��w���R
�A��������K���ݧ󬰰�w�C
LONG
);
  set_weight(5000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",5);
    set("unit", "��");
    set("value",20000);
  }
  set("limit_lv",40);
  set("armor_prop/armor",40);
  set("armor_prop/con",2);
  set("armor_prop/str",1);
  set("armor_prop/dex",-2);
  set("armor_prop/dodge",-5);
  setup();
}
//int query_autoload() { return 1; }

