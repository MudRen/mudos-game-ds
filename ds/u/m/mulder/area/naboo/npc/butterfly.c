#include <ansi.h>
inherit NPC;
void create()
{
        set_name("蝴蝶", ({ "butterfly"}) );
        set("race", "野獸");
        set("age", 1);
      set("long", "一隻美麗的蝴蝶正在採花蜜。\n");
        set("level",2);
        set_temp("apply/armor",10);
      set_temp("fly",1);
      set("chat_msg", ({   
        "蝴蝶在你身邊不停飛來飛去\n", 
}) ); 

        setup();
}

