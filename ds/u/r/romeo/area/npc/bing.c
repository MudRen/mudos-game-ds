#include <ansi.h>
inherit NPC;
void create()
{
set_name("兵", ({"bing"}) );
set("long","在你前面這位武者來自地獄，二十年前為了追求最強之道，就
將靈魂交給了阿修羅，成了鬼使者，他的代號就叫：兵。\n");
set("attitude", "aggressive");
set("level",40);
set_skill("dodge",90);
set_skill("blade",100);
     set("title",HIC"阿修羅"NOR);
set_skill("unarmed",90);
setup();
carry_object("/u/k/king/area/npc/wp/blade2")->wield();
}

