inherit ITEM;
void create()
{
  set_name("棋盤",({"chessboard"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","一個木製棋盤，棋盤上畫了十三乘十三的方格線。");
    set("value",10);
  }
  setup();
}