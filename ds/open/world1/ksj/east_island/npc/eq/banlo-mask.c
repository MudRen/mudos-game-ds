#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
  set_name("��Y����"NOR,({"banlo mask","mask"}) );
  set("long",@LONG
���Y�y��������A���c�����y�i�H���~�ĤH�C
LONG);
  set_weight(900); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "�i");       
    set("value",500);          
    set("volume", 1);                       
    set("material", "gold");   
  }
  set("armor_prop/armor",2);
  set("armor_prop/con",1);
  set("armor_prop/hit",3);
  setup();
}
