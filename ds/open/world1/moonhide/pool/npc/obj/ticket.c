#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("�g�粼",({"exp ticket","ticket"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�i");
                set("long",
               "�g�粼�A�i�H��ﴫ�������g��ȡC\n");
             }
        set_weight(100);     
        set("no_give",1);
        setup();
} 

