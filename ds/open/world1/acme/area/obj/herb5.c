inherit ITEM;
void create()
{
    set_name("黯淡沙灰根", ({ "lacking root","root" }) );
    set_weight(10);
    if( clonep() )
       set_default_object(__FILE__);
    else {
       set("long","這是一根佈滿灰沙的千年活靈芝的根。\n");
       set("unit","根");
       set("value",1);
    }
     setup();
}
