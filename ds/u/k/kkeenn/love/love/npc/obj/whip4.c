#include <weapon.h>
inherit WHIP;
void create()
{
  set_name("�t�@" , ({ "fast whip","whip" }) );
  set_weight(1550);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�@���A�����ɯ�[�t���@�l�C\n");
    set("material", "silver");
	set("value", 3000);
    set("weapon_prop/dex",2);
  }
  init_whip(20);
  setup();
}

