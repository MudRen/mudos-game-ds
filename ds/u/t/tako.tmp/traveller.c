inherit NPC;
void create()
{
        set_name("���H",({ "walk man","man" }));
        set("long","�@�ӥ��b���������H�A�L�]�������A�]���I�W���O��䪺�����C\n");
        set("level", 50);
        set("age",20);
        set("chat_chance", 15);
        set("chat_msg", ({
  "���H���G �� ~ �z�l�@�� Q ~ ~ ~�C\n",
  (: random_move :),
}) );
        setup();
        add_money("coin",150);
        carry_object("/u/t/tako/long sword")->wield();
        carry_object("/u/t/tako/boots")->wear();
}


