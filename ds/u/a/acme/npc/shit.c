inherit ITEM;
void create()
{
        set_name("狗屎", ({ "shit" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
           set("long","這是一坨奇臭無比的狗屎，你竟會帶在身上。\n");
           set("unit","坨");
           set("value",1);
        }
}
