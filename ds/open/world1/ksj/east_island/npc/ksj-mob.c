inherit NPC;

void create()
{
  set_name("���Ѫ��H�q", ({ "ksj's follower","follower"}));
  set("long",@long
�@�Ӧ~�������ҡA�t�d������Ѫ��u�@�C
long);      
  set("gender", "�k��" );
  set("age",19);
  set("level",10);
  set("race","human");
  set("chat_chance", 10);
  set("chat_msg", ({
      "���Ѫ��H�q���D�G�F��q�w�}����աA�Фj�a�h�h�}�}�C\n",
      "���Ѫ��H�q���D�G�V�L�F�������ʶR�ѵ��]�N���q�W�F�C\n",
      "���Ѫ��H�q���D�G�s��Цb�������� mob ���w���C\n",
     }));
  setup();
  add_money("coin",10+random(10));
}
