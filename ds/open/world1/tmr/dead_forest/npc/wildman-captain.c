#include <npc.h>
#include "barbarian_base.c"

void create()
{
        set_name( "���H�Y��", ({ "redhair captain","captain","wildman","man"}) );
        set("long",@long
    ���H�Y�ت����D�`�����j�A���Y�����v���õL���A���ɦa�����A�o��
��ӡA���G�H�ɳ��|�����A�����C
long
);
        set_race("human");
        set("title","���v");
        set("age", 25);
        set_attr("str",30);
        set_skill("whip" , 80);                  // �@�k
        set_skill("parry",80);
        set_skill("dodge",50);
        setup();
        set_level(15);
        advance_stat("hp",500);
        do_heal();
        carry_object("/d/obj/whip")->wield();
		carry_object(__DIR__"obj/monster_pants")->wear();
		carry_object(__DIR__"obj/bone-earring")->wear();
}

