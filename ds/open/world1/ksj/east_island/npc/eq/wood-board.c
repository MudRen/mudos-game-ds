inherit ITEM;

void create()
{
  set_name("告示牌", ({"wood board","board"}) );
  set("long",@LONG
一個木製的告示牌，上面刻著：

    天狗  村民  以此為界，互不侵犯！

                              秋川

LONG
);
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("no_get",1);
    set("no_drop",1);
    set("no_sac",1);
    set("unit", "塊");
    set("volume",1000);
    set("value",500);
  }
  setup(); 
}
