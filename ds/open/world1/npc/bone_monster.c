#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�e����", ({ "bone monster","monster" }) );
        set("race","monster");
        set("attitude","aggressive");
        set("level",31);
        set("age",120);
        set("evil",5);
        set("long",@LONG
�����W�U���O���Y�զ����e����A���W�ܵۤ@�󳱴˴˪���
�`�A�S�����y�����}�̳z�X�}�}�H���C
LONG
);
        setup(); 
        carry_object(__DIR__"../eq/ghost_plate")->wear();
        carry_object(__DIR__"../eq/bone_helmet")->wear();
}

