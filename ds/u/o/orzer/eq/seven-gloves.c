#include <ansi.h>
#include <armor.h>
inherit HANDS; 
void create()
{
  set_name(HIC"�C"HIG"��"HIY"�@�M"NOR,({"seven-light gloves","gloves"}));
  set("long", @LONG 
�@���^�ۤC�m�_�۪���M�A�Q�����X�n�]�D�`���O�x�E���m�O
�B�����O���Q�����j�j�E
LONG);
  set_weight(1600);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",3);
    set("value",3000);
    set("material","fur");
  }
  set("limit_lv",25);
  set("armor_prop/damage",100);
  set("armor_prop/armor",100);
  set("armor_prop/shield",100); 
  set("armor_prop/dex",20); 
  set("armor_prop/str",20);
  set("armor_prop/con",20);
  set("armor_prop/int",20);
  set("armor_prop/bar",3);
  set("armor_prop/bio",3);
  set("armor_prop/tec",3);  set("armor_prop/wit",3);
  setup();
}

int query_autoload() { return 1; }

