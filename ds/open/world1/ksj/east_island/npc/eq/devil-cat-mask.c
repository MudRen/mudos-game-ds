#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
   set_name(HIG"���߭�"NOR,({"devil cat mask","mask"}) );
  set("long",@LONG
�ߧ����y�ֻs��������A�㦳�j�j�����O�C
LONG);
  set_weight(700); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_con",30);
    set("limit_lv",40);
    set("unit", "�i");       
    set("value",50000);          
    set("volume", 2);                       
    set("material", "leather");   
  }
  set("armor_prop/armor",3);
  set("armor_prop/int",3);
// save eq ���A�X�[merits -tmr 2007/04/10
//   set("armor_prop/wit",1);
//    set("armor_prop/bar",-1);

  setup();
}

int query_autoload() { return 1; }
