#include <ansi.h>
inherit NPC;
void create()
{
  set_name("���]����", ({ "Gon-sun madam","madam" }) );
  set("gender", "�k��" );
  set("long",@LONG
�����\�_��D��ܡA�۩ۤ�A���H�H�����q�ۧA�C
���]�����O�K���Ӫ��j�ޮa�A�۱q�e���K�����`�����}��A�K���ӴN��
�����@�H�`��j�p�ưȡC
LONG
);      
  set("age",45);
  set("level",30);
  set("race","human");    
  setup();
  carry_object(__DIR__"wp/wp01")->wield();
}