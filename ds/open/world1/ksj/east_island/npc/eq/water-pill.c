#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
  set_name("����Y", ({ "water pill","pill" }));
  set("long",
      "�γ����B���l�B�B�}�V�X���Y���A�Y�F�i�H�ͬz����B��_��O�C\n"
      );
  set_weight(500);
  if(clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
  }
  set("value", 200);
  set("heal",([
      "ap": 50,
      "mp": 50,
     ]));
  setup();
}
