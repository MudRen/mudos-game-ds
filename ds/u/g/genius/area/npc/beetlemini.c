#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "迷你盔甲蟲" , ({ "mini armor beetle","mini","beetle" }) );
        set("level",15);
        set("gender","雄性");
        set("age",2);
        set("race","野獸");
        set("attitude", "aggressive");
        set("evil",12);
 set("long",@LONG
這是一種可怕的蟲型怪物，身上披著一層硬可比擬金屬的殼。
因為生長還未完成，體型很小，但是牠的模樣也夠可怕了。
LONG);
        set("limbs", ({ "頭部", "胸部", "觸角", "前腳", "後腳"}) );
        set("verbs", ({ "bite", "claw" }) );
        set("con",30); 
        setup();
}
