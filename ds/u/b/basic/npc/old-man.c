inherit NPC;
void create()
{
        set_name("�ѤH",({ "man" }) );
        set("long","�@�ӿW�~���ѤH�C\n");
        set("race","�H��");
        set("title","���l������");
        set("age",75);
        set("level",10);
        set("chat_chance",5);
        set("chat_msg",({
               (:command("sing �ڨS�K��ڨS�K��Ф��n�P����"):),
                "�ѤH���n�۹D�G�u�S�H�ʪ����l����v\n",
        }) );

        set_skill("dodge",5);
        set_skill("unarmed",5);
        set_skill("parry",5);

   setup();
add_money("silver",8);
}
