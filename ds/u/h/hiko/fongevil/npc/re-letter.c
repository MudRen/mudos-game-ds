inherit ITEM;
void create()
{
        set_name("信籤",({"re letter","letter"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long",@long
一張小信籤，上頭寫著：

    「爺極思汝，速速返家。」
long
);
        set("unit","張");
        }
        setup();
}



