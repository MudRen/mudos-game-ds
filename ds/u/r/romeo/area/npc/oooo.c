inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("星∼野∼殘∼紅", ({ "kfo king","king" }) );

        set("gender", "男性");
        set("age", 19);
        set("attitude", "peaceful");

        set("level",60);

        set("combat_exp", 100000);
        set("score", 200000);

        set("env/wimpy", 50);

        set("chat_chance", 30);
        set_skill("sword", 200);
        set_skill("force", 100);
        set_skill("parry", 60);
        set_skill("dodge", 100);
        set_skill("hungchen-sword",100);
        set_skill("mirage-steps",100);
map_skill("dodge", "mirage-steps");
map_skill("sword", "hungchen-sword");

set("chat_chance_combat",80);
        set("chat_msg_combat", ({
                    (:command("exert mirage-steps"):),
       }) );


        create_family("殘紅門", 0, "神");

        setup();
carry_object("/u/k/king/area/npc/wp/sword.c")->wield();

}

void attempt_apprentice(object me)

{
        command("look " + me->query("id"));
        if( me->can_afford(100) ) {
                command("say 我不收叛徒﹐" + RANK_D->query_respect(me)
+ "您還是回去種田吧。\n");
                return;
                command("nod");

       command("smile");
command("pat $n");
command("say 本門是非常辛苦的喔，用心學會讓你揚眉吐氣的喔。");
                command("recruit " + me->query("id"));
        }
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "kfopkman");
}

