inherit NPC;

void create()
{
        set_name("�p�D��",({"taoist child","child"}) );
        set("long",@LONG
�L�O�H���D�[���~�����D���A���M�~����p�A���w�g�֦��W�ߪ���O
�C�L�����۱����M�z�D�[��������W�������C
LONG
);
        set("age",8);
        set("race","�H��");
         set("level",1);
        set("attitude", "peaceful");
        set("gender", "�k��" );
        set("title","�H���D");
        set("chat_chance",10);
        set("chat_msg",({
                "�p�D�����Ԧa���۶���W������..\n",
               (:command("sweat"):),
                "�p�D���O�L�Y�ӱ�F�A�@������A�S�~�򰵥L���u�@�F�C\n",
        }) );

        set_skill("unarmed",20);

        setup();
        carry_object(__DIR__"eq/shoe")->wear();
        receive_money(10);
}

