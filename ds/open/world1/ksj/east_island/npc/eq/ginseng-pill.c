#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
  set_name(HIY"���x��"NOR, ({ "ginseng pill","pill" }));
  set("long",
      "�H�d�~�H�x���s���Ĥ��A�i�H�ɥR���A�^�_�믫�C\n"
     );
  set_weight(600);
  if(clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
  }
  set("value", 5000);
  set("heal",([
      "hp": 2000,
      "ap": 1500,
      "mp": 1500,
     ]));
  setup();
}
