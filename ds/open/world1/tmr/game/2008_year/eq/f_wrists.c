#include <ansi.h>
#include <armor.h>
inherit WRISTS; 
void create()
{
  set_name(HIG"���ӹB��ý�"NOR,({"mouse-happiness wrists","wrists"}));
  set("long", @LONG
�o�O�u���ӹB��v�M�ˤ����䤤�@��˳ơA��W�o�M���ӹB��ˡA
�i�H���@�z����ֳU�����v�C
LONG);
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",1);
    set("value", 100);
  }
    // �W�[���ֳU�����v
    set("armor_prop/happiness", 10);

  setup();
}

