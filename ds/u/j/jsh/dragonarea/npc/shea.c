inherit NPC;
void create()
{
        set_name("�Y�s�h",({ "panlon shea","shea","panlon" }));
        set("long","�Y�s���̸̥~�~���i�H�ݪ��ͪ��C\n");
        set("level", 10);
        set("age",10+random(20));
        set("chat_chance", 10);
        set("chat_msg", ({
  "�Y�s�h�o�X�ǩǪ��n���G tsk tsk tsk�C\n",
  (: random_move :), 

}) );
        setup();
        
}

