inherit NPC;

void create()
{
        set_name("礦工", ({ "mine worker","worker" }) );
        set("race","human");
        set("gender", "男性");
        set("level",12);
        set("age",30);
        set("evil",-10);
        set("long",@LONG
在礦坑工作的工人，身體強健力大如牛，個個都不是好相與
的角色。
LONG
);
        setup(); 
carry_object("/open/world1/tmr/wujian/npc/obj/iron-hoe.c")->wield();
}
