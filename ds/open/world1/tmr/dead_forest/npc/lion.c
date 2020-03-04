#include <npc.h>

void create()
{
        set_name( "巨獅" ,  ({ "huge lion" , "lion" }) );
        set_race("beast");
        set("verbs", ({ "bite", "claw","crash"}) );
        set("age", 20 );
        set("long",@LONG
　　這是一隻長的異常巨大的獅子，正對著您張舞著鋒銳的爪子，血盆大口
中露出巨大的尖牙，喉嚨裡不時發出低吼聲，正目不轉瞬的直盯著你瞧。
LONG
        );
        set("attitude", "aggressive");
        set("title","死亡之森");
        set_skill("unarmed" , 100 );
        set_skill("dodge" , 100 );
        set_skill("parry" , 100 );
        set_attr( "cor" , 25 );
        set_attr( "strength" , 50 );
        set_stat_maximum("hp" , 800);
        set_stat_maximum("nina" , 300);
        setup();
        set_level(15);
        do_heal();
        //carry_object(__DIR__"obj/QuestJawei.c");
        carry_object(__DIR__"obj/lion-jerk.c");
}
