inherit NPC;
void create()
{
        set_name("��˪��p�c",({ "poor vendor","vendor" }));
        set("long","�@�ӽa����˪��i���H, �ݨӬO�]���o��ͷN�Ӯt�F���t�G�C\n");
        set("level",3);
        set("age",20);
        set("chat_chance", 8);
        set("chat_msg", ({
  "�p�c���G �u�O�I����a....���W�S�u�ѳo�I��, ����~�n�O....�C\n",
  (: random_move :),
}) );
        setup();
        carry_object(__DIR__"eq/junkcloth")->wear();
        carry_object(__DIR__"wp/stick")->wield();
        add_money("coin",200);
}