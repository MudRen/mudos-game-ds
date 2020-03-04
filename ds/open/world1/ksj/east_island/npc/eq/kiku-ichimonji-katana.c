#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{
  set_name(HIY"��"HIW"�@��r"NOR, ({ "kiku-ichimonji katana","katana" }) );
  set("long",@long
�M���J��Q�����᪺�᯾�A�O�W�K���ű�y���W�M�A�M���Ѯ��A��
���u���M���������b�����i�b���A�M�W�������j���M��C
long);      
  set_weight(2750);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("material", "blacksteel");
    set("value",30000);
    set("volume",4);
  }
  set("rigidity",1200);
  set("limit_skill",60);
  set("limit_lv",40);
  set("weapon_prop/sou",-1);
  set("weapon_prop/wit",-1);
  set("weapon_prop/bar",1);
  set("weapon_prop/tec",1);
  set("weapon_prop/hit",10);
  set("replica_ob",__DIR__"ya-katana");
  init_blade(64);
  set("wield_msg","$N�ޥX�y����$n�A�˴H���M���O�H�椧�ߩġC\n");
  set("unwield_msg","$N�N�⤤��$n��^�M�T�A�o�X--��--�@�n�M�T�C\n");
  setup();
}
