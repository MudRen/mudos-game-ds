#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
  set_name(HIY"�a�s��"NOR,({"dragon eye","eye"}) );
  set("long",@LONG
�W���a�s�������A���W����������ܱo�s��A�åB�ݱo��M���A�Y��
�b�·t���]��p�P�ձޡC
LONG);
  set_weight(800); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_level",20);
    set("unit", "��");       
    set("value",5000);          
    set("volume", 1);                       
    set("material", "gold");   
  }
  set("armor_prop/armor",1);
  setup();
  set("armor_prop/hit",10);
  set("armor_prop/dodge",10);  
}
