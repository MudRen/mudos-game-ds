inherit NPC;
void create()
{
        set_name("���H",({ "traveller" }));
        set("long","�@�ӥ��b���������H�A�L�]�������A�]���I�W���O��䪺�����C\n");
        set("level", 1);
        set("age",20);
        set("chat_chance", 15);
        set("chat_msg", ({
  "���H���G �����٦��n�X�Ѫ����{�n���C \n",  (: random_move :),
}) );
        setup();
        add_money("coin",150);
        carry_object("/u/t/tako/clothes")->wear(); 
        }






