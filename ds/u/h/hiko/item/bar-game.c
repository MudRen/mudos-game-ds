//拉霸機v1.0
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("巫師拉BAR機" ,({ "wiz Bar","Bar","bar","b","w"}) );
        set_weight(9000);
        set("no_get",1);
        set("no_sac",1);
        set("value",5);
        set("long", @LONG
你必須先設定拉霸的籌碼(bet)，
然後就可以用這台機器來玩拉霸(bar)了！
LONG );
        set("unit", "台");
        set("bet", 5);
}

void init()
{
        add_action("go_bar", "bar");
        add_action("go_bet", "bet");
        add_action("go_look", "look");
}

int go_bar(string what)
{
  object money,me;
  me=this_player();
  money=present("coin",me);

if(money && money->query_amount() > this_object()->query("bet")) {
if(this_object()->query_temp("bar_now"))
        return notify_fail("機器正在運轉中，請稍待.....\n");
message_vision("$N擺\出一個很酷POSE拉下霸桿，轉輪開始轉動.....\n",this_player());
this_object()->set_temp("bar_now",1);
money->add_amount(-this_object()->query("bet"));
call_out("labar",3,this_object());
        }
else
        return notify_fail("你的錢不夠押下目前的賭注\n");

return 1;
}

int labar(object ob)
{
string pic1,pic2,pic3;
object money,me;
int lucky = random(6);
int lucky2 = random(6);
int lucky3 = random(6);
int luck1,luck2,luck3;

if(lucky == 3 || lucky == 5)
 {  
   if(lucky==lucky3)
     {
      lucky2=lucky;
     }
     else
      {
       if(lucky==lucky2)
        lucky3=lucky;
      }
 } 
  me=this_player();
  money=present("coin",me);
this_object()->delete_temp("bar_now");
if(lucky == 1) {
pic1 = "│┌───┐│
││"HIR"������"NOR"││
││ "HIG"ＦＬ "NOR"││
││"HIR"������"NOR"││
│└───┘│";
luck1 = 7;
} else if(lucky == 2) {
pic1 = "│┌───┐│
││"HIY"▅▅▅"NOR"││
││　"HIY"◢◤"NOR"││
││　"HIY"▉"NOR"　││
│└───┘│";
luck1 = 2;
} else if(lucky == 3) {
pic1 = "│┌───┐│
││"HIG"◢▉◣"NOR"││
││"HIG"▉　▉"NOR"││
││"HIG"◥▉◤"NOR"││
│└───┘│";
luck1 = 3;
} else if(lucky == 4) {
pic1 = "│┌───┐│
││"HIR"������"NOR"││
││"HIY"ＢＡＲ"NOR"││
││"HIR"������"NOR"││
│└───┘│";
luck1 = 4;
} else if(lucky == 5) {
pic1 = "│┌───┐│
││"HIY"　▲　"NOR"││
││"HIY"◥■◤"NOR"││
││ "HIY"◤◥ "NOR"││
│└───┘│";
luck1 = 5;
} else {
pic1 = "│┌───┐│
││"HIC"◢▉◣"NOR"││
││"HIC"▉"HIW"☉"HIC"▉"NOR"││
││"HIC"◥▉◤"NOR"││
│└───┘│";
luck1 = 6;
}

if(lucky2 == 1) {
pic2 = "│┌───┐│
││"HIR"������"NOR"││
││ "HIG"ＦＬ "NOR"││
││"HIR"������"NOR"││
│└───┘│";
luck2 = 7;
} else if(lucky2 == 2) {
pic2 = "│┌───┐│
││"HIY"▅▅▅"NOR"││
││　"HIY"◢◤"NOR"││
││　"HIY"▉"NOR"　││
│└───┘│";
luck2 = 2;
} else if(lucky2 == 3) {
pic2 = "│┌───┐│
││"HIG"◢▉◣"NOR"││
││"HIG"▉　▉"NOR"││
││"HIG"◥▉◤"NOR"││
│└───┘│";
luck2 = 3;
} else if(lucky2 == 4) {
pic2 = "│┌───┐│
││"HIR"������"NOR"││
││"HIY"ＢＡＲ"NOR"││
││"HIR"������"NOR"││
│└───┘│";
luck2 = 4;
} else if(lucky2 == 5) {
pic2 = "│┌───┐│
││"HIY"　▲　"NOR"││
││"HIY"◥■◤"NOR"││
││ "HIY"◤◥ "NOR"││
│└───┘│";
luck2 = 5;
} else {
pic2 = "│┌───┐│
││"HIC"◢▉◣"NOR"││
││"HIC"▉"HIW"☉"HIC"▉"NOR"││
││"HIC"◥▉◤"NOR"││
│└───┘│";
luck2 = 6;
}

if(lucky3 == 1) {
pic3 = "│┌───┐│
││"HIR"������"NOR"││
││ "HIG"ＦＬ "NOR"││
││"HIR"������"NOR"││
│└───┘│";
luck3 = 7;
} else if(lucky3 == 2) {
pic3 = "│┌───┐│
││"HIY"▅▅▅"NOR"││
││　"HIY"◢◤"NOR"││
││　"HIY"▉"NOR"　││
│└───┘│";
luck3 = 2;
} else if(lucky3 == 3) {
pic3 = "│┌───┐│
││"HIG"◢▉◣"NOR"││
││"HIG"▉　▉"NOR"││
││"HIG"◥▉◤"NOR"││
│└───┘│";
luck3 = 3;
} else if(lucky3 == 4) {
pic3 = "│┌───┐│
││"HIR"������"NOR"││
││"HIY"ＢＡＲ"NOR"││
││"HIR"������"NOR"││
│└───┘│";
luck3 = 4;
} else if(lucky3 == 5) {
pic3 = "│┌───┐│
││"HIY"　▲　"NOR"││
││"HIY"◥■◤"NOR"││
││ "HIY"◤◥ "NOR"││
│└───┘│";
luck3 = 5;
} else {
pic3 = "│┌───┐│
││"HIC"◢▉◣"NOR"││
││"HIC"▉"HIW"☉"HIC"▉"NOR"││
││"HIC"◥▉◤"NOR"││
│└───┘│";
luck3 = 6;
}

write("\n┌─────┐\n"+pic1+"\n├─────┤\n"+pic2+"\n├─────┤\n"+pic3+"\n└─────┘\n");

if((luck1 == 7 && luck2 ==7&& luck3 == 7) || (luck1 == 2 && luck2 == 2&& luck3 == 2) || (luck1 == 3 && luck2 ==3&& luck3 == 3) || (luck1 == 4 && luck2==4&& luck3 == 4) || (luck1 == 5 && luck2 ==5&& luck3 == 5) || (luck1 == 6 && luck2 ==6&& luck3 == 6))
        message_vision("恭喜，$P成功\了拉出三連線！....\n",this_player());
else
        message_vision("哎呀~$P沒有成功\，真可惜，再玩一次吧！\n",this_player());
if(luck1 == 7 && luck2 == 7 && luck3 == 7)
money->add_amount(this_object()->query("bet") * 10);
else if(luck1 == 2 && luck2 == 2 && luck3 == 2)
money->add_amount(this_object()->query("bet") * 7);
else if(luck1 == 3 && luck2 == 3 && luck3 == 3)
money->add_amount(this_object()->query("bet") * 5);
else if(luck1 == 4 && luck2 == 4 && luck3 == 4)
money->add_amount(this_object()->query("bet") * 8);
else if(luck1 == 5 && luck2 == 5 && luck3 == 5)
money->add_amount(this_object()->query("bet") * 6);
else if(luck1 == 6 && luck2 == 6 && luck3 == 6)
money->add_amount(this_object()->query("bet") * (random(5) + 5));
}

int go_bet(string what)
{
if(!what)
        return notify_fail("你可以下注的金額：5 coin,10 coin,50 coin,100 coin\n");
if(what != "5" && what != "10" && what != "50" && what != "100")
        return notify_fail("你可以下注的金額：5 coin,10 coin,50 coin,100 coin\n");
if(what == "5")
this_object()->set("bet",5);
else if(what == "10")
this_object()->set("bet",10);
else if(what == "50")
this_object()->set("bet",50);
else if(what == "100")
this_object()->set("bet",100);
write("OK！你將下注金額設定為 "HIY+what+NOR" 古幣\n");
return 1;
}

int go_look(string what)
{
if(id(what)) {
write("
一台大家都耳熟能詳的拉霸機器，
上面閃爍著五彩繽紛的霓虹燈，十分炫眼，
拉霸機上貼著一張說明(note)，你可以看看。

目前拉霸機的賭注是每次 "+HIY+this_object()->query("bet")+NOR+" 個銅幣
");
return 1;
} else if(what == "note") {
write("
玩法：
你必須先設定拉霸的籌碼(bet)，
然後就可以用這台機器來玩拉霸(bar)了！

各種圖案的分數：
┌───┐    ┌───┐    ┌───┐ 
│"HIR"������"NOR"│    │"HIY"▅▅▅"NOR"│    │"HIG"◢▉◣"NOR"│
│ "HIG"ＦＬ "NOR"│    │　"HIY"◢◤"NOR"│    │"HIG"▉　▉"NOR"│
│"HIR"������"NOR"│    │　"HIY"▉"NOR"　│    │"HIG"◥▉◤"NOR"│
└───┘    └───┘    └───┘
   ＦＬ           ７           Coin
  賭注 *10      賭注 * 7      賭注 * 5

┌───┐    ┌───┐    ┌───┐ 
│"HIR"������"NOR"│    │"HIY"　▲　"NOR"│    │"HIC"◢▉◣"NOR"│
│"HIY"ＢＡＲ"NOR"│    │"HIY"◥■◤"NOR"│    │"HIC"▉"HIW"☉"HIC"▉"NOR"│
│"HIR"������"NOR"│    │ "HIY"◤◥ "NOR"│    │"HIC"◥▉◤"NOR"│
└───┘    └───┘    └───┘
  ＢＡＲ        幸運星        神秘之眼
  賭注 * 8      賭注 * 6      不一定
\n");
return 1;
} else
return 0;
}




