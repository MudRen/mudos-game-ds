inherit ITEM;

void create()
{
          set_name("八極小架式密訣",({"bagi book","book","quest-bagi-book"}) );
        set_weight(100);
        set("long",@long
這是一本書皮已泛黃的小冊子，上頭寫著「八極小架式」。
long
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","本");
                set("value",1);
                set("volume",1);
                set("material","paper");
        }
        setup(); 
}
