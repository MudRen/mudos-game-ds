#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�ѱ��@���",({"wood guard","guard"}));
 set("long","���e�o�ǰ��j���ު��j�Ӥl�O�Ѥѱ��бЦʿ�@���̤l
�ҥ��L�̳��O�g�L�Ż}�@�@�N�N����u�o�ʯ���, �åB�����D�ѱ���
���~�H�a��,���ѱ��������ϥL�̤��A�ӻ{�ѱ�,�]�i���F�L�̲{�b�o
�ب��H�N�����ߩ�....."
     );
 set("attitude","killer"); 
 set("age",42);
 set("gender","�k��");
 set("level",15);
 set_skill("unarmed",60);
 set("chat_chance_combat",200);
                         (:command,"say ��! �ѱ��Z�O�A�n��? ":),

 setup();
 carry_object(__DIR__"eq/cloth")->wear();
}

