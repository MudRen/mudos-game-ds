
inherit ITEM;

void create()
{
	set_name("金牌",({"sky plate","plate"}) );
	set("long","一面純金打造的金牌，上頭用黑漆題道：「賞善罰惡-傲過」。\n");
      set_weight(500);
	if(clonep() )
		set_default_object(__FILE__);
  else
   {
          set("value",0);
         set("unit","面");   //luky
	}
	setup();
}
