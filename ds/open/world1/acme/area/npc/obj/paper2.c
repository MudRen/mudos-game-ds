inherit ITEM;
void create()
{
        set_name("紙條",({"paper","paper"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long",@long
一張小小的紙條，上頭寫著：

    「林左七里，天錚遇伏，請即援救。」
long
);
        set("unit","張");
        }
        setup();
}
