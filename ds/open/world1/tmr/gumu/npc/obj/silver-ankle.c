#include <ansi.h>
#include <armor.h>
inherit ANKLE;
void create()
{
  set_name("�Ȩ���",({"silver ankle","ankle"}));
  set("long", "�o�O�@���y���嶮���Ȩ���A�W�Y�j�۱a���X���S�q���Ӭ�÷�l�C\n");
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume", 3);
    set("value", 3000);
    set("material","silver");
  }
  set("limit_lv",25);
  set("armor_prop/armor", 2);
  setup();
}

