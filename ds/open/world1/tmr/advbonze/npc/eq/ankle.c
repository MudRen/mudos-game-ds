#include <ansi.h>
#include <armor.h>
inherit ANKLE;
void create()
{
  set_name(HIW"�p�Ӧ���"NOR,({"rulaifo ankle","ankle"}));
  set("long", @LONG  
�o�O�@��˹��b�p�Ӧ򹳤W������A�C�@�ɦ�]�W���J��ۺ�o���ϮסC
LONG);
  set_weight(2000);
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
  setup();
}

