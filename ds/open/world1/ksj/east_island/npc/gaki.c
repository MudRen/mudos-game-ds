#include <ansi.h>
inherit NPC;

void create()
{
  set_name("�j��",({"gaki"}) );
  set("long",@LONG
�ѩ�e�@�y�U���o�^�Ӳ_���j���D�C�����L�ڤӤp�ӵL�k�i���A�Ӥj
�j���{�l�O�]����i���զӿ��Ȱ_�Ӫ��C�j���̺������P�A�����O��
���L�k�i���A�����O�Y�i�h�S�|�R�X�Ӫ��A�]���M�Y�G�ת��C
LONG
);
  set("race", "���~");    
  set("unit","��");
  set("age",47);
  set("level",20+random(4));
  set("limbs", ({ "�Y��","����","�ⳡ","�}��"}) ); 
  set("verbs", ({ "bite","claw" }) );     
  set("chat_chance", 5);
  set("chat_msg", ({
      "�j����F��d�g�A�@�f���ۤ@�f�Y�ۡC\n",
      "�j���w�w�a�b�a�W���ʡA�@���Y���ள�쪺�Ҧ��F��C\n",
      "�j�����A���W���q�A�S�X���������C\n",
     }));                                
  setup();
  add_money("coin",100+random(200));
}
