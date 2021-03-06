#include <ansi.h>
inherit NPC;

int quest();
void power();

void create()
{
  set_name("武痴", ({ "military" }) );
  set("gender", "男性" );
  set("long",@LONG
他是一位好武成痴的人，三十歲時盡得各家門派武學之精要，遂至黃沙鎮隱居，
因他如此醉心於武學，所以居民們給了他『武痴』的稱號，平常總是管他為武痴
，真實姓名反而無人記得。他平常總是以武會友，豪邁爽快，常常連喝二三十斤
酒而面不改色。
LONG
);      
  set("age",40);
  set("level",43+random(4));
  set("exp",40000+random(3000));
  set("race","human");

  set_skill("unarmed",90);
  set_skill("parry",60);
  set_skill("dodge",70);
  set_skill("bagi_fist",80);
  set_skill("bagi_force",51);
  set_skill("horse-steps",96);
  set_skill("fogseven",40);
  set_skill("moon_force",80);
  set_skill("buddha-force",80);
  set_spell("god-fire",81);
  set("addition/wit",-3);
	set("class1", "神武教");
	set("class2", "神武教");

  set("chat_chance", 30);
  set("chat_msg", ({
"武痴緩緩的走起步法，慢慢的打了一套拳。\n",
(: command("say 武學之道無窮無盡，這世上還有相當多不知名的武學，博覽群家，是為生平之願。") :),
(: quest :),
(: command("exert bagi_fist") :),
(: command("exert fogseven") :),
(: command("exert buddha-force armor") :),
(: command("exert bagi_force power_up") :),
(: command("exert horse-steps twine-power") :),
}));

  set("chat_chance_combat",80);
  set("chat_msg_combat", ({
(: power :),
}) );
  set("talk_reply","如果你與我交談 <say> 會發現意想不到的情報唷！\n");
  setup();
  add_money("coin",5000);
  carry_object(__DIR__"wp/wp1")->wield();
  set("mirror_number",7);
  call_out("re_quest",900);
}

void init()
{
  object me;
 
  ::init();
  if( interactive(me = this_player()) && !is_fighting() )
  {
    remove_call_out("greeting");
    call_out("greeting", 1, me);
  }
  add_action("do_no_ask","ask");
}

void greeting(object me)
{
  if( !me || environment(me) != environment() ) return;
  command("say 這位" +RANK_D->query_respect(me)+ "，想跟我過二招嗎？");
  return;
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
    command("say 哈哈哈！上次那位" +ob->query_temp("pass_quest_who")+ "真有趣，真的去幹了，不錯，很好，很好。");
  else command("say 說起足以讓本人佩服的事，我想想.... 至少要能夠打敗上古生物『點液』，才算合格。");
  return 1;
}

void relay_say(object me, string str)
{
  object ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;

  if(strsrch(str,"武") !=-1)
    command("say 我生平最好武學，你找我問武，真夠眼光，來來，我們論武喝酒，討論討論各家門派武學的心得。");
  if(strsrch(str,"門派") !=-1)
    command("say 放眼當代門派，武學之最為八極門莫屬，我各門派武學皆有涉獵，但八極武學博大精深，豈是他派能及？");
  if(strsrch(str,"八極") !=-1)
  {
    if(strsrch(str,"拳") !=-1)
      command("say 所有基本八極拳招均記載於『八極小架式秘訣』這本書上，只是不知現下流落於何處。");
    else if(strsrch(str,"小架式秘訣") !=-1)
         {
           command("say 這本書不得了啊，裡頭甚至記載了己亡佚的八極拳招呢，如果你能為我找到它，我自當重重酬謝。");
           me->set_temp("get_bagi_book",1);
         }
         else command("say 武學之最為八極門莫屬，我各門派武學皆有涉獵，但八極武學博大精深，又豈是他派能及？");
  }
  if(strsrch(str,"猛虎硬爬山") !=-1)
  {
    ob->add_temp("msg_index",1);
    switch(ob->query_temp("msg_index"))
    {
      case 1 : command("hehe");
               command("say 其實啊.. 猛虎硬爬山並不是八極門最強的絕招呢...");
               break;
      case 2 : command("hehe");
               command("say 吳鐘那老兒留了一手啊 .... 其實他沒有吧奧義全部傳給李書文那小子.. 不說了，來來，喝酒！");
               break;
      default : command("hmm");
                command("say 來來，喝酒。");
                break;
    }
  }
  return;
}

int accept_object(object who, object ob)
{
  object only_check;
  if( ob->query_amount() > 0 )
  {
    message_vision("$N拿出"+chinese_number(ob->query_amount())+"枚"+ob->name(1)+"("+ob->query("id")+")給$n。\n",who,this_object());
    command("say 我不需要"+ob->name(1)+"，你拿回去吧。");
    call_out("no_give_money",1,who,ob,ob->query_amount());
    return 1;
  }
  if(ob->query("id") == "bagi book")
  {
    command("flop");
    command("really");
    if(who->query_temp("get_bagi_book"))
    {
      who->delete_temp("get_bagi_book",1);
      command("say 你真是不簡單，好，我說過要給你重酬，請收下這個吧。");

      only_check = filter_array( children(__DIR__"obj/obj1"), (: clonep :) );
      if(sizeof(only_check) > 0)
      {
        this_object()->receive_money(5000);
        command("give " +who->query("id")+ " coin");
      }
      else call_out("fight_you",1,0);
    }
    else command("say 真感謝你，哈哈哈！！那我就不客氣的收下了。");
    message_vision("$N趕緊將$n收藏起來了，臉上露出非常高興的神情。\n",this_object(),ob),
    destruct(ob);
    return 1;
  }
  if( ob->query("victim_name") == HIM"點液"NOR )
  {
    if(this_object()->query_temp("pass_quest"))
    {
      who->start_busy(8);
      call_out("talk_msg",1,0);
      set_temp("pass_quest_who",who->name(1));
      return 1;
    }
    command("spank "+who->query("id"));
    command("say 果然夠膽識，來來，我送你個東西，咱們交交朋友。");
    destruct(ob);
    new(__DIR__"obj/obj15")->move(this_object());
    command("give " +who->query("id")+ " mirror");
    set_temp("pass_quest",1);
    set_temp("pass_quest_who",who->name(1));
    return 1;
  }
  command("送我東西啊？多謝你了，不過我長久住在此地，倒也不缺什麼，你還是拿回去吧。");
  write("["+this_object()->name(1)+"對"+ob->name(1)+"並不感興趣]\n");
  return notify_fail("");
}


int re_quest()
{
  this_object()->delete_temp("pass_quest");
  this_object()->delete_temp("pass_quest_who");
  this_object()->delete_temp("item_give");
  this_object()->delete_temp("item_give_who");
  this_object()->delete_temp("msg_index");
  call_out("re_quest",3600);
  return 1;
}

int talk_msg(int index)
{
  switch(index)
  {
    case 0 : command("spank "+this_player()->query("id"));
             break;
    case 1 : command("say 果然夠膽識，我這裡也沒什麼東西可以給你的，這樣吧，我來助你提升能力。");
             break;
    case 2 : message_vision("$n在$N背後打了一掌，只見$N『哇』的一聲，吐了一口黑血。\n",this_player(),this_object());
             break;
    case 3 : command("say 我打通你的『隱白』『厲兌』二脈，你這口黑血是勞累與長期打殺所累積的『土氣』，現下我己將之逼出，己無大礙。");
             break;
    case 4 : write("\n\t[你覺得血行順暢，在武學造詣方面的造詣又更加進一層。]\n<你的經驗值增加了！>\n\n");
      this_player()->add("exp",(this_player()->query("level") * 500) + (random((this_player()->query("level")*100))+1000));
             break;
    case 5 : command("say 不過.....");
             break;
    case 6 : command("say 這麼作只是暫時的，因為『土氣』是不斷累積的，約在數個時辰之後，你的體內又會堆積相當程度的『土氣』，這也是莫可奈何的事。");
             break;
  }
  if(index < 6) call_out("talk_msg",2,++index);
  return 1;
}

int fight_you(int index)
{
  object me = this_player(), ob = this_object();

  me->start_busy(2);
  switch(index)
  {
    case 0 : command("hmm");
             break;
    case 1 : command("say 不過....");
             break;
    case 2 : command("say 這寶物就這樣平白的送給你，實在太不甘心，來來來，先讓我看看你有沒有實力得到它！！");
             break;
    case 3 : command("say 劃下道兒來吧！！哈哈哈！");
             command("cac");
             write(HIW"[你看此人如此醉心於武學，為人又豪爽，倒也不忍拒絕他的要求]\n"NOR);
             break;
    case 4 : ob->kill_ob(me);
             me->set_temp("give_book_fight",1);
             break;
  }
  if(index < 4) call_out("fight_you",2,++index);
  return 1;
}

void die()
{
  object me;
  if( !me = query_temp("last_damage_from") )
  me = this_player(1);
  if( !me )
  {
    ::die();
    return;
  }
  if(me->query_temp("give_book_fight"))
  {
    new(__DIR__"obj/obj1")->move(this_object());
    me->delete_temp("give_book_fight");
    message_vision(HIW"\n$n哈哈大笑，說道：『不錯，不錯！果然是有實力的，我服了$N啦！』\n\n",me,this_object());
    message_vision(WHT"兩方隨即後跳開一步，相視大笑。\n"NOR,me);
    me->remove_all_killer();
    command("give " +me->query("id")+ " final book");
    command("say 此書珍貴異常，你拿去之後可要善加利用。");
    message_vision(HIY"\n\t說完$N便揚長而去，只聽得風中傳來陣陣歌聲，迴盪在滾滾黃沙平原中。\n\n",this_object());
    destruct(this_object());
  }
  else
  {
   message("world:world1:vision",
HIY"\n\t武痴在死前大笑道： 哈哈哈！" +me->name(1)+ "，真有一手，我服了你啦！！\n\n"NOR,users());

    tell_object(me,HIG"[你得到額外的 4 點聲望！！]\n"NOR);
    me->add("popularity",4);
    ::die();
  }
  return;
}

void power()
{
  switch( random(7) )
  {
    case 0 : command("say 來的好!! 哈哈哈!!");
             break;
    case 1 : command("exert bagi_fist");
             break;
    case 2 : command("exert bagi_fist");
             break;
    case 3 : command("exert bagi_fist");
             break;
    case 4 : command("cast god-fire");
             break;
    case 5 : command("cast god-fire");
             break;
    case 6 : command("exert moon_force moon-arc");
             break;
  }
  return;
}

int receive_damage(string type,int cost)
{
  object ob = this_object(), me = this_player();

  if(ob->is_busy()) ob->add_busy(-10);
  if(!random(6) && ob->is_fighting() && me != ob)
  {
    message_vision(HIG"\n$N使出了自創的當身技，氣運雙臂，以裡十字法將$n的手腕重重交纏！\n\n"NOR,ob,me);
    me->start_busy(1);
    power();
  }

  ::receive_damage(type,cost,me);
  return 0;
}

void no_give_money(object who, object ob, int index)
{
  command("give " +who->query("id")+ " " +index+ " " +ob->query("id"));
}

