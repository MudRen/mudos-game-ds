#define VER 2    // 設定版本, 2 是孟村傳奇
inherit ITEM;
void create()
{
  set_name("[孟村傳奇]單卡補充包",({"card bag v2","bag","v2"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit","包");
    set("long","這裡面有一張隨機放入的單卡！   打開請用(open bag)");
    set("value",500);
  }
  setup();
}

void init()
{ add_action("do_open","open"); }

int do_open(string str)
{
  int index, i;
  if(str != "bag") return 0;

  i = 1;
  while(i)
  {
    index = random(30)+1;
    if(index == 30 && this_player()->query("card-only/"+VER)) continue;
    if(random((index / 2)+(index / 3 )+2)) continue;
    if(index == 30) this_player()->add("card-only/"+VER,1);
    i = 0;
  }

  new(__DIR__+VER+"/card"+index)->move(this_player());

  message_vision("$N打開一包$n。\n",this_player(),this_object());
  destruct(this_object());
  return 1;
}
