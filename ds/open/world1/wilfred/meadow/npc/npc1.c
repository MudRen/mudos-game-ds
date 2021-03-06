// 有 30 種名稱變化的牛   wilfred@DS
inherit NPC;

void change();
void do_move(object me, object ob, object target);
string font(string str);

void create()
{
  set_name("牯牛",({"cow"}) );
  set("race","beast");
  set("unit","隻");
  set("age",random(4)+1);
  set("level",random(30)+1);
  set("con",query("level")*3/2);
  set("str",query("level")*3/2);
  set("limbs", ({ "頭部","腹部","胸部","牛蹄","尾巴","牛角" }) );
  set("verbs", ({ "bite","claw" }) );
  set("chat_chance",8);
  set("chat_msg", ({
(: random_move :),
}) );

  setup();
}

void init()
{
  add_action("do_pull","pull");
  if(query("new_ob")) return;
  set("new_ob",1);
  change();
}

void change()
{
  int index = query("level");
  string *str_c = ({
" ",
"小","幼","雛","乳白","暗黃","黃","鮮紅","火紅","藍紋","水藍",
"大","金毛","花斑","馱運","常山","漠北","草綠","濟南","峸北","征戰",
"水","泥沼","博士","七星","白長","洪毅","荿芬","子棋","傲沖","凌雲",
// "觴鱨鷕","國揚","成德","向雲","磐石","征東","征西","將軍","穿山","[牛博士特產品種]肉用"
});

string *str_e = ({
" ",
"small","younger","young","white","brown","yellow","red","fire","blue","water-blue",
"big","golden","flower","transmission","mountain","north","green","south","city-north","war",
"water","water-hole","doctor","mild-seven","white-long","hung-yea","chung-fan","wd","uao-chung","cloud",
// "w-k-d-s-f","city-power","chung-dhea","clouder","stone","east","west","leader","mountain-digger","meat"
});

  set_name(str_c[index]+"牯牛",({str_e[index]+" cow","cow"}));
  set("long","這是一隻"+chinese_number(query("level"))+"級的"+query("name")+"。\n");
  return;
}

int do_pull(string str)
{
  object me = this_player(), ob = this_object();
  object env = environment(me), target, rope;
  mapping exit = env->query("exits");

  if(!env) return notify_fail("四處一片黑暗，你無法行動。\n");
  if(!rope = present("rope",me)) return notify_fail("你需要一條繩子來拉牛。\n");
  if(me->is_busy()) return notify_fail("你正在忙.\n");
  if(!str) return notify_fail("你要把牛拉到哪個方向﹖\n");
  if(undefinedp(exit[str])) return notify_fail("你不能把牛拉到這個方向。\n");
  if( !target = find_object(exit[str]) ) return notify_fail("你發現事情不大對了，但又說不上來，最好敢快通知巫師。\n");

  message_vision("$N拿出"+rope->query("name")+"使勁的拉著"+ob->name(1)+"往"+font(str)+"離去。\n",me);
  call_out("do_move",2,me,ob,target);
  return 1;
}

void do_move(object me, object ob, object target)
{
  if(!ob->move(target)) return;
  if(!me->move(target)) return;
  tell_object(me,"你費了九牛二虎之力才將牛拉來這裡，只見你己累得氣喘吁吁，趴在地上了。\n");
  tell_room(target,me->name(1)+"拉著一頭"+ob->name(1)+"來到此地。\n",me);
  me->add_busy(2);
  return;
}

string font(string str)
{
  string msg;
  switch(str)
  {
    case "east"      : msg = "東邊"; break;
    case "west"      : msg = "西邊"; break;
    case "north"     : msg = "北邊"; break;
    case "south"     : msg = "南邊"; break;
    case "northeast" : msg = "東北"; break;
    case "northwest" : msg = "西北"; break;
    case "southeast" : msg = "東南"; break;
    case "southwest" : msg = "西南"; break;
    case "up"        : msg = "上";   break;
    case "down"      : msg = "下";   break;
    case "enter"     : msg = "內";   break;
    case "out"       : msg = "外";   break;
  }
  return msg;
}

