inherit NPC;

void create()
{
        set_name("�D�H",({"taoist"}) );
        set("long",@LONG
�@�ӴH���D�[���D�H�A���۹D�A�A�믫�����a�Q���ɨ��׹D���ͬ��C
�D�H�O�D�[���������~�����D�h�A���g�L�@�w���W�סC
LONG
);
        set("age",40);
        set("race","�H��");
        set("level",20);
        set("attitude", "peaceful");
        set("gender", "�k��" );
        set("title","�H���D");
        set("chat_chance",12);
        set("chat_msg",({
                "�D�H�ˤ��a��A���۩I�C\n",
        }) );

        set_skill("parry",60);
        set_skill("dodge",60);
        set_skill("unarmed",60);
        set_skill("pick-plumblossom",60);
        map_skill("unarmed","pick-plumblossom");
        set_spell("freeze-ball",50);
        set_spell("fall-thunder",50);
        set("chat_chance_combat",30);
        set("chat_msg_combat",({
                (:command("cast freeze-ball"):),
                (:command("cast fall-thunder"):),
        }) );


        setup();
        carry_object(__DIR__"eq/shoe")->wear();
        carry_object("/open/world1/eq/clothes_8")->wear();
        carry_object("/open/world1/wp/woodfist_8")->wield();
         carry_object(__DIR__"obj/water");
           carry_object(__DIR__"obj/water");
           carry_object(__DIR__"obj/water");
           carry_object(__DIR__"obj/water");
           carry_object(__DIR__"obj/water");
}

