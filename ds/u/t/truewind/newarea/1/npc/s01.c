inherit NPC;
void create()
{
  set_name("���a����", ({ "young servant","servant" }) );
  set("gender", "�k��" );
  set("long",@LONG
�L�O�����Шӥ����|�l�p�k�ġA�@�y�x�֪��ˤl�A���H�H���C
LONG
);      
  set("age",15);
  set("level",5);
  set("race","human");
   set("chat_chance", 20);
  set("chat_msg", ({
"���a�������ۦa�W���U��...�K��...�K��...�C\n",
(: command("say �������A�d�U���i�H�h�n(move)����I") :),
(: command("say �n�𪺸ܡA�|���n�a����I") :),
}));
  setup();
}



