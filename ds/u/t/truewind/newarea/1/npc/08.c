#include <ansi.h>
inherit NPC;
void create()
{
  set_name("�Ӥl��", ({ "shen tsiping","Shen","shen","Tsiping","tsiping" }) );
  set("gender", "�k��" );
  set("long",@LONG
�L�@ŧ���b����b�����ۡA�y�W�a�ۤ@���·N�C�@�M���ۤ@�M���㶼
�ۡC�u�ݥL���o�@���A��۴¤ѼӪ���V�A�R�R���o�b�C
LONG
);      
  set("age",25);
  set("level",25);
  set("race","human"); 
  setup();
  carry_object(__DIR__"armor/02")->wear();
}