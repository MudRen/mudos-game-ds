inherit NPC;
void create()
{
        set_name("X",({ "xcook" }));
        set("long",
                "�L�O�@�쨯�W���檺�p�v�A����o����sX�A�ݨӥL�n�����O�@�몺�p�v\n"
                "�ݥL������⭻���ѥ��N���D�F�C\n"
        ); 
        set("title","�p�v");
        set("gender", "�k��");
        set("race", "�H��");        set("age",40);
        set("level",20);
        set_skill("hammer",30);  
        set("chat_chance",4);
        set("chat_msg",({
  "�Ať���p�v�n�檺�n���n�C\n",
  "�p�v���V�O�����۵�C\n", 
}) );        setup();
        carry_object(__DIR__"wp/flap_pot.c")->wield();
}

