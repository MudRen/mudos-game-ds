#include <ansi.h>
inherit NPC;
void create()
{
  set_name("����", ({ "hua sun","sun","hua" }) );
  set("gender", "�k��" );
  set("long",@LONG
�o�O�Ӥl�����B�͡A�S�a���L�ӳܰs�Ѵe���C�o����@ŧ���Ū��T�A
�y�ڰt�F�@��u�C�A�ղb�ʤl�y�a�۲H�H�����e�A�Q���i�H���R�C
LONG
);      
  set("age",20);
  set("level",25);
  set("race","human"); 
  setup();
  carry_object(__DIR__"armor/03")->wear();
}
