#include <ansi.h>
#include <armor.h>
inherit NECK;
void create()
{
  set_name(HIW"�p�Ӧ������"NOR,({"rulaifo necklace","necklace"}));
  set("long", @LONG  
�o�O�@��˹��b�p�Ӧ򹳤W��������A�u���C�ɦ�]�W���J��ۺ�o���ϮסC
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
  set("limit_lv",25);
  set("armor_prop/armor", 8);
  set("armor_prop/shield", 10); 
  set("armor_prop/int",1); 
  set("armor_prop/dex",1); 
  setup();
}

