inherit NPC;

void create()
{
        set_name("�p�p�v",({"cook"}) );
        set("long","�@��D�`�{�u���檺�p�p�v�C\n");
        set("race", "�H��");
        
        set("unit","��");
        set("age",1);
        set("level",10);
        set("str",5);
         set("dex",5);
         set("attitude","heroism");
         set("chat_chance",5);
        set("chat_msg",({
                "�p�p�v���V�O�����_���\n",
        (:command("say �o���֪��n��~��~~"):),
        (:command("sweat"):),
        }) );

        setup();
        add_money("coin",30);
}
