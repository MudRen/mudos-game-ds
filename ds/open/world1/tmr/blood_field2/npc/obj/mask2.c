#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
    set_name("�]�׿򰩭���",({"nightbane mask","mask"}) );
  set("long",@LONG
�o�O�@�i�q���s�]�ר��U���򰩭��ҡA�]�׬O�@�����j�����s�A�������o�۶¦⪺
���`�𮧡C�ӳo�i����]�O�Q�Ѷ¦�@���]��A���G�����W���O�q�C
LONG);
  set_weight(1200); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "�i");       
    set("value",12000);
    set("volume", 2);                       
    set("material", "leather");   
  }
  set("armor_prop/armor",10);
  set("armor_prop/shield",10);
  set("armor_prop/con", 4);
  setup();
}
