#include <ansi.h>
inherit NPC;
void create()
{
        set_name("蜜蜂", ({ "bee"}) );
        set("race", "野獸");
        set("age", 1);
      set("long", "一隻辛勤的小蜜蜂，正在採花蜜\n");
        set("level",2);
        set_temp("apply/hit",10);
      set_temp("fly",1);
      set("chat_msg", ({   
        "蜜蜂在你身邊不停飛來飛去\n", 
}) ); 

        setup();
}

