inherit ITEM;
void create()
{
    set_name("清寒石綠果", ({ "green fruit","fruit" }) );
    set_weight(10);
    if( clonep() )
       set_default_object(__FILE__);
    else {
      set("long","這是一顆十分堅硬的果實，外面裹著一層綠色的外皮。\n");
       set("unit","顆");
       set("value",1);
    }
     setup();
}
