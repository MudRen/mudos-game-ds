// big fox bear.c

#include <npc.h>

void create()
{
        set_name("����", ({ "big fox bear","bear" }) );
        set_race("beast");
        set("verbs", ({ "bite", "claw" }) );
        set("age", 12);
        set("long", @long
�b�A���e���O�@�����w�b�a�𮧪��զ⪰���A�@������������إ��k�A
���_�Ӫ��ܡA�j���٤�A���G���Y�C
long
        );
        setup();
          set_attr("str",30);        
          set_attr("cor",30);        
        set_stat_maximum("hp",300);
        set_stat_maximum("gin",300);
        heal_stat("gin",300);
        heal_stat("hp",300);
}


