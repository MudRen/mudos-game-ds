inherit NPC;

void create()
{
        set_name("�A�ȭ�",({"attendant"}) );
        set("long","�@��D�`��§�������A�ȭ��C\n");
        set("race", "�H��");
        
        set("unit","��");
        set("age",1);
        set("level",15);
        set("str",10);
         set("dex",10);
         set("attitude","heroism");
         set("chat_chance",5);
        set("chat_msg",({
        (:command("bow"):),
        (:command("smile"):),
        }) );

        setup();
        add_money("coin",30);
}
