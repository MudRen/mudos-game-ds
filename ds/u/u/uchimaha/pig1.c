#include <ansi.h>
inherit NPC;

int quest();

void create()
{
  set_name("���]", ({ "mirror demon","demon" }) );
  set("gender", "�k��" );
  set("long",@LONG
�o�O�@�ӥ���l�Ʀ����p�]��, �A�i�H���L�����@�Ǥp������!!
LONG
);      
  set("age",10);
  set("level",50);
  set("race","human");

  set("chat_chance", 20);
  set("chat_msg", ({
"���]����������...\n",
(: command("say �z�i�H�ݧڤ@�ǨƱ���...^^") :),
}));
void init()
{
  add_action("do_say","say");
}

int do_say(string str)
{
  if(!str) str = "...";
  if(strsrch(str,"���]�����], �֬Ods�̫Ӫ��H?") !=-1)
    command("say ��M�Owho->query("id")�j�H�z�̦��ө�, �̦����z, �z�����f�p�ʷʦ��e�ìy����, �z���Ӯ��Ѱ�, �z�u�O���ڪ��^��, ��a���ɼ�!!", who);
  if(strsrch(str,"���]�����], �֬Ods�̶ª��H?") !=-1)
    command("say ��M�O�Q���ܶ�(Uchimaha)�j�H�̶�lo...!!");
  if(strsrch(str,"���]�����], �֬Ods�̧n���H?") !=-1)
    command("say �o�٥λ���...��M�O���I(Dkfum)�J����̦ܳhlo...^^");
  }
  return 0;
}
void relay_say(object me, string str)
{
  object ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;
  switch(random(3))
  {
    case 0 : command("say �ݧڽ֬Ods�̫Ӫ��H�a!!");
             break;
    case 1 : command("say �ݧڽ֬Ods�̶ª��H�a!!");
             break;
    case 2 : command("say �ݧڽ֬Ods�̧n���H�a!!");
             break;
  }
  return;
}
