
#include <npc.h>

void create()
{
        set_name("�p����", ({"small toad","toad" }) );
        set_race("beast");
        set("age", 1);
        set_stat_maximum("gin", 10);
        set_stat_maximum("hp", 10);
        set_attr("str",1);
        set_attr("cps",1);
        set_attr("con",1);
        set_attr("dex",1);        
        set("long", "�@���Q���୮���p����A���b�򩤸��Ӹ��h�C\n");
        set("chat_chance", 8);
        set("chat_msg", ({
                "�p������F�L�ӡA�S���F�L�h....\n",
        }) );

        setup();
}

