#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
  set_name(GRN"�K�["HIC"�쭱"NOR,({"orochi mask","mask"}) );
  set("long",@LONG
���ۤK�[�j�D�X������ֻs��������A�X�n���A���o�X�j�j�����O
�C
LONG);
  set_weight(700); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_con",30);
    set("unit", "�i");       
    set("value",7000);          
    set("volume", 2);                       
    set("material", "leather");   
  }
  set("limit_lv",35);
  set("armor_prop/armor",10);
  set("armor_prop/shield",10);
  set("armor_prop/int",3);
  set("armor_prop/con",1);
  set("armor_prop/sou",1);
  set("armor_prop/bio",-1);
  setup();
}
