inherit NPC;

void create()
{
        set_name("�ѥs�Ƥl",({"old beggar","beggar"}) );
        set("long",@LONG
�@�Ӧ~�ڪ��ѥs�Ƥl�A��ۤ@��ɵۤ���A�ɪ��}�֭m�A�٤����s�y
�@�y�F�_�ӡA�ݨӨ��V���f�C�A�ݵ۬ݵۡA���T�Q�q���W���������B�Ȩ�
���򪺰e���L�C
LONG
);
        set("age",70);
        set("race","�H��");
        set("level",10);
        set("attitude", "peaceful");
        set("gender", "�k��" );
        set("chat_chance",10);
        set("chat_msg",({
        "�ѥs�Ƥl�V�ۤ@�ӯ}�J�A�n�Y�̸��a�۰_�F�q\n",
        }) );

        setup();
        carry_object(__DIR__"obj/travel_bag");
}

int accept_object(object who,object ob)
{
     message_vision("$N���X�F�@"+ob->query("unit")+ob->query("name")+"�e���F�ѥs�Ƥl�C\n",who);
        command("say �y...��..�y�y..����...�C");
        destruct(ob);
        return 1;
}


