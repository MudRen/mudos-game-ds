#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{
  set_name(HIW"�ƫe����"NOR, ({ "bizen-chousen katana","katana" }) );
  set("long",@long
���X���h�M�K�ҦX�O���y�A�M�b�W�L�T�ءA�O�⧧�R�����M�C���M��
�g���\�h���W���C�ȨϥιL�A���g�j�p�ԧСA���[�H�ӧl���C��Φ�
��A�O���񯫤M���W�M�C
long);      
  set_weight(3250);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("material", "blacksteel");
    set("value", 9000);
    set("volume",5);
  }
  set("limit_lv",25);
  set("weapon_prop/str",2);
  set("weapon_prop/dex",2);
  set("replica_ob",__DIR__"ya-katana");
  init_blade(60);
  set("wield_msg","$N�ޥX�I�᪺$n�A�M����������Ţ�n��$N�C\n");
  set("unwield_msg","$N����M�b�A�W���a�N$n���^�I�W���M�T�C\n");
  setup();
}

