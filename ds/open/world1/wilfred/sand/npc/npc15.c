inherit NPC;

void create()
{
  set_name("���k", ({ "woman" }) );
  set("gender", "�k��" );
  set("long",@long
�@�쥿�b�~��A�����k�C
long
);      
  set("age",26);
  set("level",5);
  set("race","human");

  set("chat_chance", 20);
  set("chat_msg", ({
"���k���_�⤤�òO�O����A�ݤF�@�U�A½�ӭ��S�I���C�C�������_�ӡC\n",
(: command("say ���ɥi�H�ݨ�Ѿ��ѤH�b���˪L�̪��F�l�O�A�����b�@�Ǥ���C") :),
(: command("say �W�����p�鰽�F�H�a�����]�A�u�O�O�H�ͮ�C") :),
(: command("say �Q�Ѧn�����H�ӵs��C�ˡA�_�ǡA�S���O�h�ȿ��A�Q���O���즳���n���H�h�Ҭ��a�C") :),
}));

  set("chat_chance_combat", 50 );        
  set("chat_msg_combat", ({
(: command("say ���ѤƤ�j�m���k�ڡ��ڪ��հ����l�֨ӱϧڭ����") :),
}) );
  setup();
  add_money("coin",300);
  carry_object(__DIR__"eq/eq1")->wear();
}
