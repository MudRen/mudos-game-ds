#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
  set_name("����Y", ({ "genki pill","pill" }));
  set("long",
      "�h�~�e�F��q�W�������Ķ��}���Ī���s�����ĤY�A�ĮĶW�j�C\n"
     );
  set_weight(600);
  if(clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
  }
  set("value", 3000);
  set("heal",([
      "hp": 1500,
      "ap": 700,
      "mp": 200,
     ]));
  setup();
}
