#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "小盔甲蟲" , ({ "small armor beetle","small","beetle" }) );
        set("level",25);
        set("gender","雄性");
        set("age",4);
        set("race","野獸");
        set("attitude","killer");
        set("evil",12);
 set("long",@LONG
這是一種可怕的蟲型怪物，身上披著一層硬可比擬金屬的殼。
幸運地你面前這一隻並不算大，牠正揮動著黑色的觸角，似乎
準備隨時發動攻擊。
LONG);
        set("limbs", ({ "頭部", "胸部", "觸角", "前腳", "後腳"}) );
        set("verbs", ({ "bite", "claw" }) );
        set("con",55); 
        setup();
}
