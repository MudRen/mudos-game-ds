#include "barbarian_base.c"
inherit NPC;

void create()
{
        set_name("���Z�H", ({ "barbarian" }) );
        set("long",@long
�@�Ө��r�ۤW�b���A�ӤU�b����ۥ��~�֦�����ǡA�@�_�ӴN�O�L�ۯ��򶼦媺��l
�A�����@�ƼɤO�Ӧ�{���ҼˡA�ӥL���G�]���h�n�N�����q�A�H
long
);
        set("age", 25);
        setup();
        carry_object("/d/obj/woodblunt")->wield();
	carry_object(__DIR__"obj/monster_pants")->wear();

}

