#include <path.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set ("short", HIC"���"HIW"�K��"NOR);
        set ("long", @LONG
�A�Ө�@���p�p����ǡA�̭���صۦU�ؤ��P���ᦷ
�A���𺡬աA�O�A���m���ɡA�d�d���ѡA��s�{���A�y��
���Y���w�ֻP���֪��Pı�C���ɡA�@�}�y�����q�n�q�A�e
�誺�p�ж����ǨӡA�A�Ԥ����F�L�h...
LONG);   
        set("light",1);
        set("exits", ([
        "south": __DIR__"flower_road1",
        "north": __DIR__"flower_room2",
                  ]) );
       
        setup();
        replace_program(ROOM);
}


