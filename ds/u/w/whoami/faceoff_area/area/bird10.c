#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"��|"NOR);

 set("long",@LONG
�A��X�F�Ǥ�, �o�{�o�̦��\�h���ѱ��̤l�b���۽m�߷s��
�i���k�ΤP�k, �t�~���@�Ǥѱ��̤l�h�b�@�ǩΪw���άƦܦb�@
�ǥ��, �o�̯u���۷��M�H�ܩ󰣤F�ܻy�n�H�ί��n�M�a����
�I���n�H�~�S����L���n��,
LONG
    );
 set("exits",([ "northwest":__DIR__"bird12",
                "south":__DIR__"bird9",
                "north":__DIR__"bird11",
    ]));
 set("objects", ([__DIR__"npc/bird_apprentice" : 3+random(3),
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}

