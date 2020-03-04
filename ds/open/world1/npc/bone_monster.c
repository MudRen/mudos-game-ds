#include <ansi.h>

inherit NPC;

void create()
{
        set_name("骸骨精", ({ "bone monster","monster" }) );
        set("race","monster");
        set("attitude","aggressive");
        set("level",31);
        set("age",120);
        set("evil",5);
        set("long",@LONG
全身上下都是骨頭組成的骸骨精，身上披著一件陰森森的甲
冑，沒有眼球的眼洞裡透出陣陣寒光。
LONG
);
        setup(); 
        carry_object(__DIR__"../eq/ghost_plate")->wear();
        carry_object(__DIR__"../eq/bone_helmet")->wear();
}

