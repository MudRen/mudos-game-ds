inherit NPC;

void create()
{
  set_name("�p��", ({ "child" }) );
  set("gender", "�k��" );
  set("long",@long
�ѯu�¾몺�p�Ĥl�A���b�@�Ǫ��A�ۡC
long
);      
  set("age",6);
  set("level",5);
  set("race","human");

  set("chat_chance", 20);
  set("chat_msg", ({
"�p�ĥs�D�G �z����\n",
(: command("say �Q�h�J�ڤ����n�䪺�F�z���A���̦��Y�H���T��C") :),
(: command("say �W�@���ڥh��ѹ����A�L���ڬݥL���_����A�O�@���{�{�o�G����l�C�A�W���ټg�F�@�ӡy�[�z�r��C") :),
(: command("say �ڤ]���L�ݧڪ��_���A�N�O�ڦۤv�@������A�A�ݡI�H�H�H�I") :),
}));

  set("chat_chance_combat", 50 );        
  set("chat_msg_combat", ({
 (: command("say �A���ڡ����ڭn��Q���h!") :),
}) );
  setup();
  add_money("coin",100);
  carry_object(__DIR__"eq/eq15")->wear();
}
