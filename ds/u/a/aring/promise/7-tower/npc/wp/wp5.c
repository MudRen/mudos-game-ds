#include <ansi.h>
#include <weapon.h>
inherit AXE;


void create()
{
  set_name(HIY"�¶�"HIC"�C����"NOR , ({ "sun seven axe","axe" }) );
  set_weight(15000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "���򲱶Ǥw�[�����������������M�p�ҫ�������A����}�a�O��ΡA�A�X�O�j���H�ϥΡC\n"NOR);
    
    set("material", "gold");
    set("value",20000);
    set("weapon_prop/str",3);
    set("weapon_prop/dex",-2);
    set("weapon_prop/int",-2);
    set("weapon_prop/con", 3); 
    set("limit_lv",40);
    set("limit_con",75);
    set("limit_str",75);  
  }
    set("wield_msg",HIY"$N���_�¶��C�����A�}�a�O�j��L�����Q�����h�I�I\n"NOR);
    set("unwield_msg", YEL"$N��U�F�����A�K��檺�˦a�ӧ��I�I\n"NOR);
  init_axe(75);
  setup();

}

