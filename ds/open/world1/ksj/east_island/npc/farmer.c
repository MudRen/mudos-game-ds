inherit NPC;

void create()
{
  set_name("�A��",({"farmer"}) );
  set("long",@long
�@������ѹꪺ�A�H�A���b�и̤u�@�C
long);      
  set("age",33);
  set("level",13+random(2));
  set("race","�H��");
  set("attitude", "peaceful");
  set("unarmed",20);
  set("chat_chance",5);
  set("chat_msg",({
      "�A���ۦb����Ӥߦa��z�Цa�C\n",
      "�A�Ұ��F�U�ӡA�β�l�W����y���F�����C\n",
       }) );
  set_skill("unarmed",20);
  setup();                
  add_money("coin",100);
}
