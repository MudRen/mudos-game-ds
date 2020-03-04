#include <ansi.h>
inherit ITEM;

void init() {
        add_action("do_ignite1","DELETE1");
        add_action("do_ignite2","DELETE2");
}

int do_ignite1(string arg)
{
        int i;
        object *obs;
        obs = filter_array( children("/u/t/tmr/game/2006_c/oldman.c"), (: clonep :) );
        for(i=0;i<sizeof(obs);i++)
                destruct( obs[i] );
        tell_object(this_player(), "ok\n");
        return 1;
}

int do_ignite2(string arg)
{
        int i;
        object *obs;
        obs = filter_array( children("/u/t/tmr/game/2006_c/oldman2.c"), (: clonep :) );
        for(i=0;i<sizeof(obs);i++)
                destruct( obs[i] );

        tell_object(this_player(), "ok\n");
        return 1;
}

void create()
{
        set_name("DELETE�R�Ѭ�",({"first cannon","cannon"}) );
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


