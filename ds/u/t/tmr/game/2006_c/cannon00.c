// 2006/12/14

#include <ansi.h>
inherit __DIR__"cannon_base.c";

int do_wehre();

void create()
{
        set_name(HIY"�w�ڼu�D"HIR"���u"NOR,({"ballistic cannon","cannon"}) );
        set("long",@long
�ڤۤC�좱�������t�ϸ`���ʡ��y���t�ϦѤH���w�ڼu�D���u�C
�A�i�H�ϥ�ignite�����O���I�U�o�g�R�Ѭ��C
long
);
        set_weight(10);
        set("unit","��");
        set("value", 100000);
          set("min", 100);
          set("max", 120);

        setup();
}

