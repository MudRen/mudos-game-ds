// 開戰 & 戰爭結束的 room
// 好多牛... @@  哞哞哞     wilfred@DS

#include <ansi.h>

int is_war();
void start_war(object me);

inherit ROOM;
void create()
{
  set ("short", "柵欄");
  set ("long", @LONG
這裡是一塊約數丈見方的空地，周圍用簡單的柵欄圍了起來，在
入口處有塊小小的牌子，上面寫著：『牛博士』，在空地的正中
央立著一根柱子，約一個人高，似乎有什麼特別的用途。
LONG
);
  set("exits", ([
  "south" : __DIR__"room27",
]));
  set("item_desc", ([
  "柱子" : "這是一根約二人合抱般粗的木頭柱子，矗立在柵欄中間，可以用來綁住牛(lock_up)\n",
]));
  set("no_clean_up", 0);
  setup();
}

void init()
{
  add_action("do_lock_up","lock_up");
}

int do_lock_up()
{
   object *inv = all_inventory(this_object()) ;
  int i, index = 0;

  if(this_player()->is_busy()) return notify_fail("你正在忙.\n");
  if( query("is_war") ) 
        return notify_fail("仔細一看，這根柱子己經被某巨力撞成兩截了，搖搖欲墜，還是不要用比較好。\n");

  for(i=0;i<sizeof(inv);i++)
    if(base_name(inv[i]) == __DIR__"npc/npc1")
    {
      inv[i]->set("chat_chance",30);
      inv[i]->set("chat_msg", ({
"牯牛很不安的搖頭晃腦，將腳下沙子踢得四處飛濺。\n",
(: command("cow") :),
}) );
      index++;
    }

  if(index) message_vision(HIC"$N將牛牢牢的栓在柱子上。\n"NOR,this_player());
    else return notify_fail("這裡沒有牛。\n");

   if(index > 4) // 由15隻降為5隻即會開cow war by tmr 2007/01/24
  {
    for(i=0;i<sizeof(inv);i++)
            if(base_name(inv[i]) == __DIR__"npc/npc1")
            destruct(inv[i]);
    set("is_war",1);
    message_vision(HIW"『哞∼∼∼！！！！！』$N身旁的一隻牯牛突然發狂般的跳了起來，一頭撞在柱子上！！\n"+
                   "\t巨大的柱子猶如脆弱的筷子般一碰就斷！！其餘牯牛一得自由，紛紛趁機逃出了柵欄！\n"NOR,this_player());
   call_out("start_war",3,this_player());
  }

  this_player()->add_busy(2);
  return 1;
}

int is_war()
{
        object cow;
        while( objectp(cow=find_living("cow_war")) )
        {
                if( !environment(cow) )
                {
                        destruct(cow);
                        cow = 0;
                }
                break;
        }
        return objectp(cow);
}

void start_war(object me)
{
  /*
     -------------------------
     征東牯牛   x 10
     征西牯牛   x 10
     征南牯牛   x 10
     征北牯牛   x 10
     大黃牯牛   x 10
     野戰牯牛   x 10
     瘋狂牯牛   x 10  // 有特攻
     -------------------------
               +) 70 隻
  */

    int i,j;
   object master;
  if(!me) return;

  for(i=0;i<10;i++)
  {
    for(j=3;j<10;j++)
      new(__DIR__"npc/npc"+j)->move(__DIR__"room"+(4+random(25)));
  }
  message("world:world1:vision",
  HIG"\n\t【漠北急報】"HIY+me->name(1)+"不慎讓大批牯牛衝出柵欄！引起其餘牯牛響應！\n\n"+
  HIY"\t\t牯牛草原被大量發狂之牯牛佔據，混亂不堪！\n\n"NOR,users() );

  if( objectp(master = find_living("cow_master")) )
    master->command("tchat* why");

  call_out("end_war", 300);
  return;
}

void end_war()
{
  if( is_war() )  {
    call_out("end_war", 10);
    return;
  }
  delete("is_war");
  message("world:world1:vision",
    YEL"\n\t【漠北消息】"HIM"幸得各路好手之助，牯牛草原混亂場面己獲得控制。\n\n"NOR,users() );
  return;
}
