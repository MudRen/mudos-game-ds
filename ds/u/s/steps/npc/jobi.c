#include <ansi.h>
inherit NPC;
void create()
{
set_name(HIG"祖比"NOR, ({ "jobi","boy" }) );
set("race", "人類");
set("age", 13);
set("long", "他是一個和幻步好相似的男孩子.
和娜坦妮一樣,是幻步的好助手.
正在一面玩電腦,一面幫幻步編排工作.
是個十分稱職的好幫手呢!\n");
setup();
}

