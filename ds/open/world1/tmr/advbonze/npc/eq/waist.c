#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
  set_name("��ù�~���a",({"A-luo-han waist","waist"}));
  set("long", @LONG
�o�O�@���W�Y�α��r�g���F����g�媺���a�C
LONG);
  set_weight(800);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",2);
    set("value",5000);
    set("material","fur");
  }
  set("limit_lv",25);
  set("armor_prop/armor",10);
  set("armor_prop/shield",10);
  setup();
}

