inherit NPC;

void create()
{
  set_name("���", ({ "villager" }) );
  set("gender", "�k��" );
  set("long",@long
���F���~���A���ɳ��w��F�~�̻E�b�@�_��ѡC
long
);      
  set("age",30);
  set("level",7);
  set("con",8);
  set("race","human");

  set("chat_chance", 10);
  set("chat_msg", ({
(: command("say �A�n�I�w��Ө���F��C") :),
(: command("say ť���Ѿ��ѤH�̪�n�^��Y�s�s�C�A�i�O�n���n���K����~���A�ܩ�䤤�Ӹ`�A�ڴN���M���F�C") :),
(: command("say �Ѿ��ѤH���K����W���b���F�D�W�˥�F�A�H���F�n�X���A�{�U�����y������C") :),
(: command("say ���I���C�C�L�ѤH�a��ť�O�u�O�V�ѶV����F�A�C����L�����`�o�j�ۤj�s�@�f�A�u�O�H��ߡC") :),
(: command("say ť�����Ӳ���Ӫ����]�{�q���b�ФH�U��ѭC�A�ڤ]�n���ڪ��Ĥl�ǡA�ǳ�Ѫ��p�Ĥ��|���a�C") :),
(: command("say ���F�����s�����̪�u�O�s�g�L��A���F�d�����T�~�A�٨�ɿ��m�����A�u�O�i�c�ܷ��C") :),
}));

  set("chat_chance_combat", 50 );        
  set("chat_msg_combat", ({
(: command("help!") :),
(: command("say ���D�A�N�O���F�����H�ܡH�A�~���y�h�����q�A�j���ǩR��...") :),
}) );
  setup();
  add_money("coin",200);
}
