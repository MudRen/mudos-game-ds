#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
  set_name(HIR"���ˤp���n"NOR,({"heal pill","pill"}));
  set("long", "�o�O�@���s�@�{��²�檺�����ĤY�l�C\n");
  set_weight(90);
  if( clonep() )
   set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("eat_msg","$N�]�U�@���p�p�����n�C");
    set("eff_msg",HIG "���n�������b�A�餺�_�F���˪��@��...�C" NOR );
  }
        set("value", 300);
        set("heal",([
                "hp": 100,
        ]));
        set("cure",([
                "body": 10,
        ]));
        setup();
}


