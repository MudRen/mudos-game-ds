#include <ansi.h>
inherit NPC;
void create()
{
set_name(RED "吸血"NOR"農夫", ({"bloodsucker-farmer"}) );
set("age",30);
set("long","一個因為戰亂而死的農夫，因為掛唸家人屍體遲遲沒有腐化，
只能靠人血維持現在的模樣。\n");
set("attitude", "aggressive");
set("level",20);
setup();
}

