#include <ansi.h>
inherit NPC;

void create()
{
  set_name( HIR"���ݼ��s"NOR , ({"paleozoic dragon","dragon"}) );
  set("long",@LONG
���s�j�ܤ����T�j�ڸs�G�·��s�ȥءB�s�L�ةM���L�ءA���s��@���K
�d�U�~�e�]��ù���^�̬������A�u�������a�y�Q�D�A���ڤF���B���B��
�T�j�ͺA���A�e�̺��Q�a�y���@�����d�U�~���[�A�̫�@�宣�s��
�d���ʸU�~�e�]�հ���^�����C�M�ӧA�o�����D����o�����ݼ��s�A�O
���X�{�b�o�䪺�C
LONG
);
  set("race", "beast");
  set("unit","��");
  set("age", 150 );
  set("gender", "����" );
  set("level", 35 );
  set("limbs", ({ "�Y��","�ݳ�", "�I��", "���l", "����", "�j�L" }) );
  set("verbs", ({ "bite", "claw" }) );
  set("chat_chance", 20);
  set("chat_msg", ({
     (: random_move :),
     }));
  setup();
  set_temp("apply/armor",100);
  set_temp("apply/shield",100);
  set_temp("apply/damage",200);
        carry_object(__DIR__"obj/dinosaur-skin");
        carry_object(__DIR__"obj/dinosaur-bone");
        carry_object(__DIR__"obj/dinosaur-chine");
        carry_object(__DIR__"obj/dinosaur-eye");
     if( random(100) < 30) carry_object(__DIR__"obj/trump_leg"); // �t�����}
}

