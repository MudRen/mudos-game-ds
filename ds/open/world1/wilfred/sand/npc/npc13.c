inherit NPC;

void create()
{
  set_name("�ѤH", ({ "old person","person" }) );
  set("gender", "�k��" );
  set("long",@long
���F���~���A�L�v�վv�a�a�A�B���ڶ\�F�C
long
);      
  set("age",80);
  set("level",5);
  set("race","human");

  set("chat_chance", 20);
  set("chat_msg", ({
"�ѤH�|�F�|�ӻH�A���F�@�Ө���C\n",
(: command("say ���A��ӵs��V�ӶV�s���A�o�i����~�n�C") :),
(: command("say ť���Ѿ������Y�n�^�h�����L�v�����F��A���O��{�b�٥��ʨ����C") :),
(: command("say �Y�s�s�����O��ͪ������A�u�Q�h�ݤ@�ݡC") :),
}));

  set("chat_chance_combat", 50 );        
  set("chat_msg_combat", ({
(: command("say �O�ݧڦѤF�A��~�ڥi�O.... �����A�ѤH�a���ܮɧO�ʤ⦨�����H") :),
}) );
  setup();
  add_money("coin",100);
}
