#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
  set_name("�H����", ({ "ningyo meat","meat" }));
  set("long",
      "�@���H���סA�ڻ��Y�F�i�H���ͤ����C\n"
     );
  set_weight(800);
  if(clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
  }
  set("value", 2000);
  set("heal",([
      "hp": 1000,
     ]));
  set("cure",([
      "body": 50,
      "right_arm": 50,
      "left_arm": 50,
      "right_leg": 50,
      "left_leg": 50,
      "head": 50,
     ]));
  setup();
}
