#include <ansi.h>
#include <path.h>

inherit NPC;

void create()
{
  set_name("�d�۪L", ({ "teacher wu","wu" }) );
  set("gender", "�k��" );
  set("long",@LONG
�@����߻P�֤Ѫ��Ѯv�C
LONG
);
  set("title","�u"RED"����Юv"NOR"�v"NOR);
  set("age",55);
  set("level",100);
  set("exp",40);
  set("race","human");
  set("chat_chance_combat", 50 );        
  setup();
  
}

int accept_object(object who,object ob)
{
        object kaleidoscope;
        kaleidoscope=new(__DIR__"obj/kaleidoscope");

        if(ob->name()!="�\\��K")
        {
                command("say �A��򪾹D�ڭ�n�ʬ\\��K�O!?");    
                return 0;
        }
        else {
                command("say �O���O�ѧ��o�ӳg�����i�D�A��!?"); 
                command("say ��......ť�L�A��������..");
                command("say ���M�ګܥͮ�,���O�٬O�¤F�A���\\��K�F!!"); 
                command("say �J�M�A���򦳤�,�ڴN��o�Ӱe�A�a!!"); 
                kaleidoscope->move(who);
                destruct(ob);
                return 1;
        }

}

