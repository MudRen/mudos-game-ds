inherit ITEM;
void create()
{
        set_name("毀壞的石人",({"bad stone's man","man"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long",@long
這是一個不成人形的石人，石人上滿滿是被人破壞的痕跡。
long
);
        set("unit","俱");
        }
        setup();
}
