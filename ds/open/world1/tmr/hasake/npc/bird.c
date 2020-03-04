// 天鈴鳥
inherit NPC;
void create()
{
        set_name("天鈴鳥", ({ "tian-lin bird", "bird" }) );
	set("race", "beast");
	set("age", 1);
	set("level",5);
        set("long", "一只美麗的天鈴鳥，鳥兒的歌聲像是天上的銀鈴。
這鳥兒只在晚上唱歌，白天睡覺。有人說，這是天上的星星掉下來之後變的。\n");
        set("attitude", "friendly");
	set("limbs", ({ "嘴", "翅膀", "爪子" }) );
	set("verbs", ({ "bite", "claw" }) );
	set_temp("apply/attack", 5);
	set_temp("apply/defense", 5);
	set_temp("apply/damage", 5);
	setup();
}
