#include <ansi.h>
inherit ITEM;
void create()
{
        set_name( "�t�g" ,({"bible book", "book", "bible" ,"_BIBLE_BOOK_"}));
     set_weight(10);
     if( clonep() ) 
               set_default_object(__FILE__);
     else {
                set("long",@LONG
�@���t�g��...��ԣ�n�h�ê��C
LONG
);
            set("unit", "��");             
            set("value",0);
            set("no_give",1);
         }         
        setup();
}

