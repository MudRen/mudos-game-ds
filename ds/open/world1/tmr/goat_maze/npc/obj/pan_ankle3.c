#include <ansi.h>
#include <armor.h>
inherit ANKLE;
void create()
{
  set_name(HIG"����������"NOR,({"pan ankle","ankle"}));
  set("long", @LONG  
�o�O�@�ꪪ���ﮦ������A�ΧA�q�ӨS�����L���Ӫ��Ұ������C
LONG);
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume", 3);
    set("value", 4000);
    set("material","gold");
  }
  set("limit_lv",30);
  set("armor_prop/armor", 5);
  set("armor_prop/dex", 2);
  setup();
}

