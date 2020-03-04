#include <npc.h>
#include "barbarian_base.c"

void create()
{
        set_name( "�g�ɳ��H", ({ "redhair crazy wildman","wildman","man"}) );
        set("long",@long
�@�@�o�O�@�Y���v�����H�A���G�O�o���˪L����~���C�@�L�����ժZ���O�A
���c�����a���ۧA�A���G��A���s�b���۬۷�j���ϷP�C���O�o���H��o����
���`�������A�ӥB���������A�����a�����i�x�C
long
);
        set_race("human");
        set("title","���v");
        set("age", 25);
        set("attitude", "aggressive");
        set_attr("str",30);
        set_skill("blunt",80);                  // �Ϊk
        set_skill("twohanded blunt",60);        // �����Ϊk
        set_skill("parry",50);
        set_attr("strength",20);
        setup();
        set_level(15);
        advance_stat("hp",300);
        do_heal();
        carry_object("/d/obj/woodblunt")->wield();
		carry_object(__DIR__"obj/monster_pants")->wear();
}

