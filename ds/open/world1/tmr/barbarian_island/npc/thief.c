#include <npc.h>
#include "barbarian_base.c"

void create()
{
        set_name("�����W���s��", ({ "thief" }) );
        set("long",@long
�b�A���e�O�@�Ӭ�۶¦�B���Y�鸣���k�l�A�@�_�ӴN�O��s�骺��
�l�C�L���C�j�����|�B�i��A���G�b��ߤ���@�ˡC
long
);
        set_race("human");
        set("age", 30);
        set_skill("blade",80);
        set_skill("secondhand dagger",80);
        set_skill("parry",50);
        set_skill("dodge",50);
        setup();
        set_level(15);
        carry_object("/d/obj/blade")->wield();
        carry_object("/d/obj/dagger")->wield("secondhand dagger");
        carry_object("/d/obj/armor")->wear();
        carry_object(__DIR__"obj/battle-axe");
}


