#include <ansi.h>
#include <armor.h>
inherit PANTS; 
void create()
{
  set_name(HIB"�p"HIR"�C"HIC"�a�y"NOR+CYN"��"NOR,({"flow pants","pants"}));
  set("long", @LONG 
�@���e�ۻa�ѻ�p���Ϯת��Ǥl�A�Ϯ״��o�@���x��W�M���l�ޤO�E�ݨӮݮݦp��
�s�@�H���Ӥ��O��²��H���E
LONG);
  set_weight(1100);
  if( clonep() ) set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",3);
    set("value",4500);
    set("material","fur");
  }
  set("armor_prop/armor",30); 
  set("armor_prop/shield",100);
  set("armor_prop/dex",20);
  set("armor_prop/int",20);
  set("armor_prop/str",20);
  set("armor_prop/con",20);  
  setup();
}
int query_autoload()
{
      return 1;
}


