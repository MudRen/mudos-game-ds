inherit NPC;

void create()
{
  set("title","��`����");
  set_name("����", ({ "villager" }) );
  set("gender", "�k��" );
  set("long",@long
�y���������ҭ̡A���ɳ��O�b�~�����A�����]����Ƹs�E�Q�סC
long
);      
  set("age",37+random(5));
  set("level",10);
  set("con",14);
  set("race","human");
  set("exp",3000);  set("chat_chance", 10);
  set("chat_msg", ({
(: command("say �A�n..�w��Ө�ڭ̪y�����C") :),
(: command("say �̪񨺨ǳå�X�{�V�ӶV�W�c�A���̫��h�����r�C") :),
(: command("say �ڭ��Y�دu�O�@�Ӷǩ_�H���Ať���O�h�F�@���æ����@���⪺�a������^�ӡC") :),
(: command("say ���I���l�����ӴN��b���y�L�̨��Ǥp���F�A�i�O�C�����p���İʡA�u�O�H��ߡC") :),
(: command("say ť�����ǳå�O�q����Ӫ��A�]�����D�����򰾰��D�W�ڭ̧��l�A�u�O�h�סC") :),
(: command("say ���s�å�u�O�s�g�L��A���F�����ڭ̮����~�A�٨�B�T��A�u�O�i�c�ܷ��C") :),
}));

  set("chat_chance_combat", 50 );        
  set("chat_msg_combat", ({
(: command("help!") :),
(: command("say �i�c�r..���ۭt�ڭ̮������A���D�A�O���ǳå몺�P��?") :),
}) );
  setup();
  add_money("coin",500);
}

