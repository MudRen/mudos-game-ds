inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("�P�㳥��ݡ��", ({ "kfo king","king" }) );

        set("gender", "�k��");
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


        create_family("�ݬ���", 0, "��");

        setup();
carry_object("/u/k/king/area/npc/wp/sword.c")->wield();

}

void attempt_apprentice(object me)

{
        command("look " + me->query("id"));
        if( me->can_afford(100) ) {
                command("say �ڤ����q�{�M" + RANK_D->query_respect(me)
+ "�z�٬O�^�h�إЧa�C\n");
                return;
                command("nod");

       command("smile");
command("pat $n");
command("say �����O�D�`���W����A�Τ߾Ƿ|���A���ܦR�𪺳�C");
                command("recruit " + me->query("id"));
        }
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "kfopkman");
}

