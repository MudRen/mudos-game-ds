#include <ansi.h>
#include <path.h>

inherit NPC;

void create()
{
  set_name("李梅川", ({ "doctor lee","lee" }) );
  set("gender", "男性" );
  set("long",@LONG
江湖炙手可熱的一位大夫。
LONG
);
  set("title","「"YEL"奶油桂花手"NOR"」"NOR);
  set("age",54);
  set("level",100);
  set("exp",40);
  set("race","human");
set("inquiry",([
  "夢幻競技場" : "不告訴你,拿點錢來賄絡我看看..說不定我會講..XD\n",
  ]));
  set("chat_msg", ({
(: command("say 想知道怎樣去夢幻競技場的人來喔！！") :),
(: command("say 全DS只有我知道！！") :),
(: command("say 想知道的話,請ask me！！") :),
}));

  set("chat_chance_combat", 50 );        
  setup();
  
}

int accept_object(object who, object ob)
{
  if(ob->query("id") != "coin" )
  {
    command("say 不夠不夠不夠，我想不起來");
    return notify_fail("");
  }
  if ( ob->query_amount() < random(30000)+50000 )
  {
    command("say 還是不夠，小子別小氣了.....XD");
    return notify_fail("");
  }
  this_object()->receive_money( ob->query_amount() );
  command("say 嗯,夠了..我告訴你..找到枯\樹枝,給住我隔壁的小吳就可以了!!。");
  command("say 還有,別跟他說我跟你講的喔,不然我會被他殺了= =|||");
  return 1;
}

