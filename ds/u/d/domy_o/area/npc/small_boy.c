inherit NPC;

void create()
{
        set_name("�p�k��",({"boy"}) );
        set("long","�@��ѯu�i�R���p�k�ġA���b�ʳf���q�W�î̡C\n");
        set("race", "�H��");
           
        set("unit","��");
        set("age",1);
        set("level",1);
        set("str",1);
         set("dex",-1);
         set("attitude","heroism");
         set("chat_chance",3);
        set("chat_msg",({
                "�p�k�Ĥѯu�����F�_��\n",
        }) );

        setup();
        add_money("coin",30);
}
