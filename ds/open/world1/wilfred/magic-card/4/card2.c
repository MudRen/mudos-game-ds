inherit __DIR__"std_card.c";
void create()
{
  set("short","坎德人");
  set("pow", ({1,1,3,2}) );
  set("lv",1);
  set("ver",4);
  set("ver_n","龍槍系列");
  set("num",2);
  set("long",@LONG
克萊恩上好奇心最強的種族, 走過他們身邊時, 記得抓緊自己的皮包
, 不然它就會自己『掉』到坎德人手中, 而且他們還只是好心幫你保
管而已...
LONG
);
  setup();
}