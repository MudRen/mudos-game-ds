// 2006/12/14

#include <ansi.h>
inherit __DIR__"cannon_base.c";

int do_wehre();

void create()
{
        set_name("�үŨR�Ѭ�",({"first cannon","cannon"}) );
        set("long",@long
�ڤۤC�좱�������t�ϸ`���ʡ��y���t�ϦѤH�����ŨR�Ѭ��C
�A�i�H�ϥ�ignite�����O���I�U�o�g�R�Ѭ��C
long
);
        set_weight(10);
        set("unit","��");
         set("value",1000);
        set("min",10);
        set("max",20);
        setup();
}

