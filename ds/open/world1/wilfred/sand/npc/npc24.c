#include <ansi.h>
inherit NPC;

void flee();

void create()
{
  set_name("�ɪŮȦ��", ({ "time space traveler","traveler" }) );
  set("gender", "�k��" );
  set("long",@long
�@��_�˲��A���ꪺ�ǤH�A�|�B�i��ۡA�����b�@����C
long
);      
  set("age",25);
  set("level",20);
  set("race","human");
  set("title",HIC"��V�ɪŪ��Ȧ�"NOR);

  set_skill("dodge",80);

  set("chat_chance", 30);
  set("chat_msg", ({
"�ɪŮȦ椣�����|�B�i��A�n���ﲴ�e���F�観���j���쪺�ˤl�C\n",
"�ɪŮȦ�̮��_��äW���F��A�b�Ť��񹺵ۡC\n",
(: command("say �j�N���ؿv���u�O�j�嶯�_�A���@�ضW�M����....") :),
(: command("hmm") :),
(: command("tsk") :),
}));

  set("chat_chance_combat", 80 );        
  set("chat_msg_combat", ({
(: command("help!") :),
(: command("say ���D�j�N���H���o���Z�� !!") :),
(: flee :),
}) );

  setup();
  carry_object(__DIR__"eq/eq6")->wear();
}

void flee()
{
  if(random(2) && this_player()->query("level") < 25) return;
  message_vision(HIW"\n$N��M���X�@�Ӫ����y�A�u��$N����X�{�@�D���_�A$N���i�o���_���ᤣ���F�C\n\n"NOR,this_object());
  message_vision("�A�ݱo�����f�b�A�ݦb��a�b�Χ@�n���o�C\n",this_object());
  destruct(this_object());
}