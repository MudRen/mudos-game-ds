
#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "大盔甲蟲" , ({ "huge armor beetle","huge","beetle" }) );
        set("level",36);
        set("gender","雄性");
        set("age",8);
        set("race","野獸");
        set("attitude","killer");
        set("evil",12);
 set("long",@LONG
這是一種可怕的蟲型怪物，身上披著一層硬可比擬金屬的殼。
你面前的這一隻顯然是族群裡面體型較大的，立起來足足有一
般人的半身高，這也意味了牠的殺戮意識也是較強的。
LONG);
        set("limbs", ({ "頭部", "胸部", "觸角", "前腳", "後腳"}) );
        set("verbs", ({ "bite", "claw" }) );
        set("con",80); 
        setup();
}
