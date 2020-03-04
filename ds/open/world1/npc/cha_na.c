#include <ansi.h>

inherit NPC;

void create()
{
        set_name("剎楠", ({ "cha na","na" }) );
        set("race","human");
        set("gender", "男性");
        set("level",33);
        set("age",37);
        set("evil",15);
        set("attitude", "aggressive");
        set("title",HIR"聖炎蛇使"NOR);
        set("long",@LONG
聖炎使者中最邪惡，最殘暴的一人，做事只依自己的喜好，
從不考慮他人，嗜殺成性。眼睛因出生時就瞎了，因此一直
用布包著，或許天生的殘障是導致他性格偏差的原因。
LONG
);
        setup(); 
        carry_object(__DIR__"../eq/ys_helmet")->wear();
        carry_object(__DIR__"../eq/fk_gloves")->wear();
}

