#include <npc.h>
#include "barbarian_base.c"

void create()
{
        set_name( "�����R�R�����H", ({ "redhair wildman","wildman","man"}) );
        set("long",@long
�@�@�o�O�@�Y���v�����H�A���G�O�o���˪L����~���C�@�L�����ժZ���O�A
���c�����a���ۧA�A���G��A���s�b���۬۷�j���ϷP�C�A�٪`�N��L�����g
�N�a�S�X�L���A�����b�۷Q�ۤ���C
long
);
        set_race("human");
        set("title","���v");
        set("age", 25);
        set_attr("str",30);
        set_skill("blunt",80);                  // �Ϊk
        set_skill("twohanded blunt",60);        // �����Ϊk

        set_skill("parry",50);
        setup();
        set_level(10);
        carry_object("/d/obj/woodblunt")->wield();
        carry_object(__DIR__"obj/monster_pants")->wear();
        // ��������
        carry_object(__DIR__"obj/fire-eye");
}

