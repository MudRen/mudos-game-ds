inherit NPC;

void create()
{
        set_name("石魔鳥", ({ "stone bird","bird" }) );
        set("race","beast");
        set("unit","隻");
        set("level",35);
        set("age",20);
        set("evil",-10);
        set("long",@LONG
雞首、獅身、長有雙翼、蛇尾的奇異魔獸，據說被牠詛咒過
的人都會化為石像。
LONG
);
        set("limbs", ({ "頭部", "身體", "後腳","前腳"}));
        set("verbs", ({ "crash","hoof","claw","poke" }));
        setup();
        //carry_object(__DIR__"../eq/mb_wing");
}

void die()
{
	carry_object(__DIR__"../eq/mb_wing");
	::die();
}