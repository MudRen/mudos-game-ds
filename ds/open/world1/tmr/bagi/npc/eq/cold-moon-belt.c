#include <ansi.h>
#include <armor.h>
inherit WAIST; 
void create()
{
  set_name( HIC"�N���~�ֱa" NOR,({"cold moon belt","belt"}));
  set("long", @LONG
�o�O�@���ΧN���~�֩һs�����ֱa�A�W�Y�ٯd�ۻȥզ⪺����C
LONG);
  set_weight(600);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",3);
    set("value", 4000);
    set("material","fur");
  }
  set("limit_lv",10);
  set("armor_prop/armor",10 ); 
  set("armor_prop/shield",10 );
  set("armor_prop/con", 2);
  set("armor_prop/damage", 5);
  setup();
}
