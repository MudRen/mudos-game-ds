inherit ITEM;
void create()
{
    set_name("龍鬚碧藍花", ({ "dragon flower","flower" }) );
    set_weight(10);
    if( clonep() )
       set_default_object(__FILE__);
    else {
       set("long","這朵怪花有著許\多長長的鬚，在花瓣上白裡透藍，十分好看。\n");
       set("unit","朵");
       set("value",1);
    }
     setup();
}
