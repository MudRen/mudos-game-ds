#include <ansi.h>
inherit NPC;
void normal_ai();

void create()
{
  set_name("�K���j�D�D�D��",({"Yamata-no-orochi's body","body"}) );
  set("long",@LONG
�K�Y�K���A���j���ߦ��p�K�y�s�p�P�K�Ӥs���@�몺���Ƥj�D���W��
���B�̡A������K�y�s���B�s���A�����w�ۨ���C�A�{�b�Ҭݨ쪺��
���O�K���j�D���D���C
LONG
);
  set("race", "���~");    
  set("unit","��");
  set("age",2000);
  set("attitude", "peaceful");
  set("level",70);
  set("limbs", ({ "�I��","����"}) ); 
  set("verbs", ({ "crash"}) );     
  set("chat_chance", 50);
  set("chat_msg",({
     (: normal_ai() :),
     }) );        
  setup();
}