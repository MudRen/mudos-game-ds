#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("�y���ʤf��"HIG"����"NOR,({"breach shell","shell"}) );
        set_weight(30);
        set("long",@long
���ۤp�ʤf�A�ݰ_�Ӥ��O�o�򪺧����C
long
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","��");
                set("value",0);
        }
        setup();
}

