#include <ansi.h>
inherit ITEM;
void create()
{
        set_name( "聖經" ,({"bible book", "book", "bible" ,"_BIBLE_BOOK_"}));
     set_weight(10);
     if( clonep() ) 
               set_default_object(__FILE__);
     else {
                set("long",@LONG
一本聖經啊...有啥好懷疑的。
LONG
);
            set("unit", "本");             
            set("value",0);
            set("no_give",1);
         }         
        setup();
}

