#include <npc.h>
#include "barbarian_base.c"


void create()
{
        set_name("�k���Z�H", ({ "woman barbarian","barbarian" }) );
        set("long",@long
�@�Ӭ��~�֦窺�k���Z�H�A�@�_�ӴN�O�L�ۯ��򶼦媺��l�A�����@
�ƼɤO�Ӧ�{���ҼˡA�ӥL���G�]���h�n�N�����q�A�C
long
);
        set_race("human");
        set("age", 25);
        set("age", 25);
        set("gender","female");
        set_attr("str",30);
        set_skill("blunt",80);                  // �Ϊk
        set_skill("twohanded blunt",60);        // �����Ϊk
        set_skill("parry",50);
        set_skill("dodge",50);
        setup();
        set_level(6);
        carry_object("/d/obj/woodblunt")->wield();
	carry_object(__DIR__"obj/monster-cloth")->wear();
}

