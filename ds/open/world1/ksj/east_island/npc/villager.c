inherit NPC;

void create()
{
  set_name("����", ({ "villager" }) );
  set("gender", "�k��" );
  set("long",@long
�@�촶�q�������A���b���Ǩ��ۡC
long
);      
  set("age",20+random(20));
  set("level",7+random(3));
  set("race","human");
  set("chat_chance", 8);
  set("chat_msg", ({
     (: command("say �o��B�ͧA�n�C") :),
     (: command("say ���ѤѮ𤣿����C") :),
     (: command("say �����|�u�Q�h��j�����Ѩ��ѡC") :),
     (: command("say �h�~�p��t���ݡA�٬O�y�����p���l���C") :),
     }));
  setup();
  add_money("coin",100+random(100));
}
