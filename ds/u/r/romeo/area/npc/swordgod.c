#include <ansi.h>
inherit NPC;
void create()
{
set_name("釋斷離", ({"sword-god","god"}) );
set("long","這位是赫赫有名的人物，號稱江湖上沒人它殺不到的，或許
你可以請他幫你殺人，但是價格可不便宜喔。\n");
set("level",45);
     set("title",BLU"秋末悲歌"NOR);
setup();
}

