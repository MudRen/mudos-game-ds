#include <ansi.h>
inherit NPC;

void create()
{
  set_name( "�����s" , ({"paleozoic dinosaur","dinosaur"}) );
  set("long",@LONG
���s�j�ܤ����T�j�ڸs�G�·��s�ȥءB�s�L�ةM���L�ءA���s��@���K
�d�U�~�e�]��ù���^�̬������A�u�������a�y�Q�D�A���ڤF���B���B��
�T�j�ͺA���A�e�̺��Q�a�y���@�����d�U�~���[�A�̫�@�宣�s��
�d���ʸU�~�e�]�հ���^�����C�M�ӧA�o�����D����o�������s�A�O��
��X�{�b�o�䪺�C
LONG
);
  set("race", "beast");
  set("unit","��");
  set("age", 150 );
  set("gender", "����" );
  set("level", 25 + random(3) );
  set("limbs", ({ "�Y��","�ݳ�", "�I��", "���l", "����", "�j�L" }) );
  set("verbs", ({ "bite", "claw" }) );
  set("chat_chance", 20);
  set("chat_msg", ({
     (: random_move :),
     }));
  setup();
	if(random(2) ) carry_object(__DIR__"obj/dinosaur-skin");
	if(random(5) == 1 ) carry_object(__DIR__"obj/dinosaur-bone");
	if(random(5) == 1 ) carry_object(__DIR__"obj/dinosaur-chine");
	if(random(5) == 1 ) carry_object(__DIR__"obj/dinosaur-eye");

}
