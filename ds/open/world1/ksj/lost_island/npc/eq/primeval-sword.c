#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
  set_name(YEL"�ӥj����"NOR,({"primeval sword","sword"}));
  set("long",@LONG
�~�N�[�����j�C�A��������O�ݫC�ɤ@���A�C������j���A���M
�������æ��C�b���M�U�Q�ӵo�X�H���A���O��N�������C
LONG
);
  set_weight(6000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_dex",30);
    set("limit_str",40);
    set("limit_skill",60);
    set("unit", "��");        
    set("value",30000);
    set("volume",4);
    set("material","steel");       
  }
// 2003.3.30 �s�W lv���� by ksj
  set("limit_level",45);        
  set("weapon_prop/str",random(3));
  set("weapon_prop/con",random(4));
  set("weapon_prop/int",random(3));
  set("weapon_prop/dex",random(3));
  set("weapon_prop/bio",random(2));
  set("weapon_prop/wit",random(2));
  set("weapon_prop/tec",random(2));
  set("weapon_prop/bar",-1+random(2));
  set("weapon_prop/sou",-2+random(2));     
  set("weapon_prop/hit",0+random(10));       
  init_sword(45+random(5));
  setup();
  set("wield_msg",HIY"$N���X$n�A�y�ɼC���|�g�A�ӱo�|�P�{�p�ձޡC\n"NOR);
  set("unwield_msg","$N�N�⤤��$n�p�ߦa�θh���]�q���_�C\n");
}
