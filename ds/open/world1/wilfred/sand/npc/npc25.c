#include <net/dns.h>
#include <ansi.h>
inherit NPC;

string *teach_msg = ({
"在這裡下子，『並』，以緊壓的方式迫使對方回應。",
"這時如果對方『黏』，我們以『尖』下禺位，防守中同時反擊。",
"剛開始幾手以星位，三三為主，也可以『小跳』，如此一來陣地較堅實。",
"在這裡不要用小馬步飛，應以『大馬步飛』進攻，如果說小馬步飛有九十九手後著，那麼大馬步飛便有一百手。",
"落子以穩，心以靜，眼觀大局，才是致勝之道。",
"棋盤上正中央稱之為『天元』，餘四隅稱作星位。",
"初期不可妄動，要先打好根基，以求中期之優勢盤局。",
"下單官時要找尋劫材，以收取更多小空地為主。",
"對奕時雙方各持黑子，白子，黑方先下，是為『先手』。",
"圍出一塊對手無法侵入之空地，稱為『活』，通常活都擁有二隻眼。",
"角落是兵家必爭之地，不但獲利較大，領地也相當穩固。",
"時常練習，才能使棋藝更進步。",
"今天先教到這裡，記得回去要多練習。",
"若無對手可對奕時，自行佈局，排棋譜，也是讓自己實力增強的方法。",
"這裡，對方右邊防守較空虛，以四六角『掛』，從旁側擊。",
"先休息一下，喝口茶..... 你們自行將我剛才所教的實地演練一遍。",
});

void do_teach();
int quest();

void create()
{
  set_name("本因坊 秀策",({"oniska"}) );
  set("long",@LONG
謎般的美男子，聽說來自遙遠的異國，對圍棋有一股極大的執著及狂
熱，在他的生命裡，圍棋的價值大於一切事物。現在他的棋藝己漸漸邁向
『神乎其技』的境界。
LONG
);
  set("title",HIC"『神乎其技』"NOR);
  set("age",1000);
  set("level",10);
  set("gender","男性");
  set("race","人類");

set("chat_chance",20);
  set("chat_msg",({
(: do_teach :),
(: do_teach :),
(: quest :),
(: do_teach :),
"本因坊 秀策拿起棋筍，慢慢的在棋盤上落了幾顆子。\n",
(: do_teach :),
}) );
  set("talk_reply","如果你與我交談 <say> 會發現意想不到的情報唷！\n");
  setup();
  carry_object(__DIR__"eq/eq5")->wear();
  carry_object(__DIR__"eq/eq11")->wear();
  set("mirror_number",6);
}

void init()
{
  ::init();
  add_action("do_sit","sit");
  add_action("do_no_ask","ask");
  if (this_player()->query_temp("do_sit") ) this_player()->delete_temp("do_sit");
  this_object()->set_heart_beat(1);
}

void do_teach()
{
  object ob = this_object(), *student;
  int i;

  if(ob->is_fighting() ) return;
 
  student = all_inventory(environment(ob));
  if( sizeof(student) < 1 ) return;

  command("say " +teach_msg[random(16)] );

  for(i=0;i<sizeof(student);i++)
  {
    if( userp(student[i]) && student[i]->query_temp("do_sit") )
    {
       if( student[i]->query_temp("netdead") == 1 ) continue;
if(random(4))
       {
         message_vision(CYN"對於老師的一番話，$N似乎若有所悟。\n"NOR,student[i] );
         student[i]->improve_skill("chess",random(3)+1);
       }
    }
  }
  return;
}

int do_sit()
{
  object me;
  me=this_player();
 
  if(me->query_temp("do_sit")) return notify_fail("你已在學圍棋了。\n");
  if (me->is_fighting() ) return notify_fail("你正忙著打架，沒空學圍棋。\n");
  if(me->is_ghost()) return notify_fail("死人不能學圍棋。\n");
  if(me->is_busy() ) return notify_fail("你正忙著，沒有空學圍棋。\n");

  message_vision("$N找了個空位坐下，開始學圍棋了。\n",me);
  me->set_temp("do_sit",1);
  return 1;
}

int do_no_ask()
{
  write("請用 say <交談的方式> 來取得所需情報。\n");
  return 1;
}

int quest()
{
  object ob = this_object();

  if(ob->query_temp("pass_quest"))
    message_vision("$N整理了一下桌面。\n",ob);
  else command("say 上次那個棋盤不曉得放到哪了... 傷腦筋..");
  return 1;
}

void relay_say(object me, string str)
{
  object ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;
  if(strsrch(str,"棋盤") !=-1)
    command("say 就是一個木製棋盤，上面畫著十三乘十三的方格線。");
  if(strsrch(str,"圍棋") !=-1)
    command("say 如果你真的想學圍棋，那麼請坐(sit)吧，我來教你定石的基礎。");
  if(strsrch(str,"本因坊") !=-1)
    command("say 是？我就是本因坊，如果要學圍棋，可以來找我學(sit)。");
  if(strsrch(str,"進藤光") !=-1)
    command("say 他是我的朋友，笨笨的很可愛。");
  if(strsrch(str,"定石") !=-1)
    command("say 所謂的定石就是圍棋落子的基礎技巧，圍棋的戰術變化皆由定石而來，天機老人目前也有跟我學定石，他蠻喜歡對奕的，你可以找他下棋。");
  return;
}

int accept_object(object who, object ob)
{
  if( ob->query_amount() > 0 )
  {
    message_vision("$N拿出"+chinese_number(ob->query_amount())+"枚"+ob->name(1)+"("+ob->query("id")+")給$n。\n",who,this_object());
    command("say 給我"+ob->name(1)+"啊？我不缺錢，你拿回去吧。");
    call_out("no_give_money",1,who,ob,ob->query_amount());
    return 1;
  }
  if(ob->query("id") != "chessboard" )
  {
    command("say 這是什麼東西..... ?");
    write("["+this_object()->name(1)+"對"+ob->name(1)+"並不感興趣]\n");
    return notify_fail("");
  }
  if(this_object()->query_temp("pass_quest"))
  {
    command("say 真是太謝謝你了，不過我的棋盤己經找回來了，你還是留著自己用吧。");
    return notify_fail("");
  }
  command("say 太好了，真是謝謝你，我送你這個當報酬吧");
  destruct(ob);
  new(__DIR__"obj/obj15")->move(this_object());
  command("give " +who->query("id")+ " mirror");
  this_object()->set_temp("pass_quest",1);
  call_out("re_quest",900);
  return 1;
}

int re_quest()
{
  this_object()->delete_temp("pass_quest");
  return 1;
}

void no_give_money(object who, object ob, int index)
{
  command("give " +who->query("id")+ " " +index+ " " +ob->query("id"));
}
