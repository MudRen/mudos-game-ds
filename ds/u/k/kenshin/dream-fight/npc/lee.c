#include <ansi.h>
#include <path.h>

inherit NPC;

void create()
{
  set_name("�����t", ({ "doctor lee","lee" }) );
  set("gender", "�k��" );
  set("long",@LONG
���򪥤�i�����@��j�ҡC
LONG
);
  set("title","�u"YEL"���o�۪��"NOR"�v"NOR);
  set("age",54);
  set("level",100);
  set("exp",40);
  set("race","human");
set("inquiry",([
  "�ڤ��v�޳�" : "���i�D�A,���I���Ӹ쵸�ڬݬ�..�����w�ڷ|��..XD\n",
  ]));
  set("chat_msg", ({
(: command("say �Q���D��˥h�ڤ��v�޳����H�ӳ�I�I") :),
(: command("say ��DS�u���ڪ��D�I�I") :),
(: command("say �Q���D����,��ask me�I�I") :),
}));

  set("chat_chance_combat", 50 );        
  setup();
  
}

int accept_object(object who, object ob)
{
  if(ob->query("id") != "coin" )
  {
    command("say �������������A�ڷQ���_��");
    return notify_fail("");
  }
  if ( ob->query_amount() < random(30000)+50000 )
  {
    command("say �٬O�����A�p�l�O�p��F.....XD");
    return notify_fail("");
  }
  this_object()->receive_money( ob->query_amount() );
  command("say ��,���F..�ڧi�D�A..���\\��K,����ڹj�����p�d�N�i�H�F!!�C");
  command("say �٦�,�O��L���ڸ�A������,���M�ڷ|�Q�L���F= =|||");
  return 1;
}

