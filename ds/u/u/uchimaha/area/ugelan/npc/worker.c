inherit NPC;
void create()
{
        set_name("�X�Y�u�H",({ "worker" }) );
        set("long","�@��b�X�Y�u�@���u�H�C\n");
        set("race","�H��");
        set("age",43);
        set("level",15);
        set("attitude","friendly");
        set_skill("dodge",30);
        set_skill("unarmed",50);
        set_skill("parry",20);
        set("chat_chance",10);
        set("chat_msg", ({"�X�Y�u�H�[�ܹD�G�j��[��l�E\n",
                          "�X�Y�u�H�V�O���⺮�f�h�U��E\n",
                          (:command("sweat"):),
                        }));
   setup();
   carry_object(__DIR__"eq/pants.c")->wear();
   add_money("silver",6);           
}

