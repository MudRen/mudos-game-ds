#include <ansi.h>
inherit ITEM;

void create()
{
          set_name(HIM"天妖骨"NOR,({"skyevil key","red","key"}));
          set_weight(60);
          set("unit", "隻");
          set("long","這隻"HIM"天妖骨"NOR"是從天妖身上取下的，他像一隻鑰匙..\n");
          set("door","skyevilkey");         
          set("value", 10000);
          set("usage","開啟某一扇門");  
}
