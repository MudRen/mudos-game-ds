inherit NPC;

void create()
{
        set_name("�ǤH",({ "man" }) );
        set("long",
"�@�ӬݨӽG�z�������H�A�믫�Q���e���A�����ٰ��y�F���n�A�j�h��\n"
"�������o..\n"
        );

        set("race","�H��");
        set("gender","�k��");
          set("chat_chance",10);
        set("chat_msg",({
        (:command("puke"):),
   (:command("get all"): ),
   (:command("wear all"): ),
        }) );
        set("age",30);
        set("level",5);
        set("attitude", "heroism");  

        setup();
}

