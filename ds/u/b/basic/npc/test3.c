inherit NPC;
void create()
{
        set_name("���H",({ "traveller","���H" }));
        set("long","�@�ӥ��b���������H�A�L�]�������A�]���I�W���O��䪺�����C\n")
;
        set("level", 1);
        set("age",20);
        set("chat_chance", 8);
      
        setup();
        add_money("coin",1500000);
       carry_object("/u/b/basic/eq/sun")->wield();
}
