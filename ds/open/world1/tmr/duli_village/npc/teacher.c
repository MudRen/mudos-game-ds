#include <npc.h>

inherit F_VILLAGER;

void create()
{
        set_name("�ЮѦѮv", ({"teacher" }) );
        set_race("human");
        set("age", 60);
        set("long", "�@�ӥ��Z���Ѯv�A�b�o�p�����H�оɧ����ȨǤp�����͡C\n");
        setup();
        set_level(5);
        carry_object(__DIR__"obj/medium-book");
        carry_object("/d/obj/shortsword")->wield();
        
}

int accept_fight(object ob)
{
        return 0;
}


