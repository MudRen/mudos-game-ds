// master.c

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("測試用師父", ({ "test-master", "test", "master" }) );
        set("nickname", "TEST_MASTER");
        set("gender", "男性" );
        set("age", 44);
        set("str", 27);
        set("cor", 30);
        set("cps", 27);
        set("int", 24);

        set("max_force", 1500);
        set("force", 1500);
        set("force_factor", 3);

        set("long","一個測試用的師父級人物");
        create_family("【傲梅】", 3, "掌門人");
        set("combat_exp", 1000000);
        set("score", 200000);
        set("chat_chance_combat", 60);
        set_skill("unarmed", 40);
        set_skill("parry", 120);
        set_skill("dodge", 80);
        set_skill("sword", 150);
        set_skill("force", 40);
        set_skill("literate", 60);

        setup();
}

void attempt_apprentice(object ob)
{
	return 1
;
}
