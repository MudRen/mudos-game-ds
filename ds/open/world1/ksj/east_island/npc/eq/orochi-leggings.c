#include <armor.h>
#include <ansi.h>
inherit LEGGING;

void create()
{
  set_name(GRN"�K��"HIG"���H"NOR ,({ "orochi leggings","leggings"}) );
  set("long",@LONG
�K���j�D���������s�����@���H�ҡA�ȥզ⪺���W���o��⪺��
��A�����軴��T�A�٪����ǳ\���j�D���O�C
LONG);
  set_weight(2400);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_con",30);
    set("material", "leather");
    set("unit", "��");
    set("value",9000);
    set("volume",3);
  }
  set("limit_lv",30);
  set("armor_prop/armor",18);
  set("armor_prop/shield",18);
  set("armor_prop/con", 1);
  set("armor_prop/dex", 3);
  set("armor_prop/dodge", 10);
  setup();
}
