#include <ansi.h>
inherit NPC;
void create()
{
set_name("雲廬劍僧", ({"pkman"}) );
set("long","這位十大殺手中的高手，身背巨劍，是極恐怖的人物。\n");
set("level",45);
     set("title",YEL"十大殺手"NOR);
set_skill("unarmed",70);
setup();
}

