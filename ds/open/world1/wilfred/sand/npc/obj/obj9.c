// 最主要是其 long 的變化以及可以重複使用   wilfred@DS

inherit ITEM;
void create()
{
  set_name("旅行水袋",({"traveler sack","sack"}));
  set_weight(500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("basic_long","這是沙漠旅行者的必需品，水袋以牛皮縫製而成，十分耐用。\n使用方法: drink sack\n");
    set("value",300);
  }
  set("no_put",1);
  setup();

  set("fill_water",5);
}

void init()
{
  add_action("do_drink","drink");
  set("value",0);
}

int do_drink(string str)
{
  object ob = this_object(), me = this_player();
  if(!str || str != "sack") return 0;
  if(me->query("level") > 25) return notify_fail("此旅行水袋僅供等級二十五之內的玩家使用\n");
  if(ob->query("fill_water") == 1) return notify_fail("水袋裡己經沒有水了喔！\n");
  if(me->query("hp") >= me->query("max_hp")) return notify_fail("你的肚皮快撐破了！\n");
  if(me->query("hp") < 5) return notify_fail("你傷重之下，再也無力喝水了！\n");

  ob->add("fill_water",-1);
  me->add("hp", random(15)+15 );
  me->start_busy(2);
  if( ob->query("fill_water") > 1 )
    message_vision("$N拿起水袋喝了幾口。\n",me);
  else message_vision("$N將水袋裡最後幾口水喝光。\n",me);
  return 1;
}

string long()
{
  int index = this_object()->query("fill_water");
  string msg = this_object()->query("basic_long");

  if(index == 5) return msg + "\n這水袋是全滿的。\n";
  if(index > 4)   return msg + "\n這水袋約七分滿。\n";
  if(index > 3)   return msg + "\n這水袋約半滿。\n";
  if(index > 2)   return msg + "\n這水袋快見底了。\n";
  return msg + "\n這水袋是空的。\n";
}

