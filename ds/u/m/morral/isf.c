inherit ITEM;

void create()
{
  set_name("I'S 最終本(eeman 專用)", ({ "IS COMIC" }));
  set_weight(100);
  if( clonep() )
  set_default_object(__FILE__);
  else {
        set("unit","本");
        set("long",
                 "這是桂正和畫的I'S,因為是EEMAN 專用本,"
                 "所以各位應該猜得到裡面是啥(18禁)\n");
        set("value",10000);
}
}
