#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "盔甲蟲幼蟲" , ({ "baby armor beetle","baby","beetle" }) );
        set("level",3);
        set("gender","雄性");
        set("age",0);
        set("race","野獸");
        set("attitude", "aggressive");
        set("evil",12);
 set("long",@LONG
這是一種可怕的蟲型怪物，身上披著一層硬可比擬金屬的殼。
而面前的只是一隻剛剛孵化沒多久的小東西。
LONG);
        set("limbs", ({ "頭部", "胸部", "觸角", "前腳", "後腳"}) );
        set("verbs", ({ "bite", "claw" }) );
        set("con",10); 
        setup();
}
