#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
  set_name(MAG"������"NOR,({"ghost necklace","necklace"}) );
  set("long",@LONG
ĭ�t�������O���_�ɡA���o�t�I��������~�C
LONG);
  set_weight(700); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("value",4000);          
    set("volume", 2);                       
    set("material", "stone");
  }
  set("armor_prop/armor",1);       
  set("armor_prop/dex",1);
  setup();
}
