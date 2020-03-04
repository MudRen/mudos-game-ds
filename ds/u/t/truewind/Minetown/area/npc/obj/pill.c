#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
  set_name(HIR"療傷小膠囊"NOR,({"heal pill","pill"}));
  set("long", "這是一顆製作程序簡單的紅色藥丸子。\n");
  set_weight(90);
  if( clonep() )
   set_default_object(__FILE__);
  else
  {
    set("unit", "顆");
    set("eat_msg","$N吞下一顆小小的膠囊。");
    set("eff_msg",HIG "膠囊的粉末在你體內起了療傷的作用...。" NOR );
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


