
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIW"�W�s�x�βĤ@����"NOR);
        set ("long", @LONG
�o�̴N�O�Ĥ@�����F�ﭱ�ӨӪ��O���Mħ�i
�˪��çL�A�L�̹�A�r�֪��L���ۡA�A���G�]�P��
���w�֪���^�I�A�J�ӦV�̭���F��A�èS������
�S��o�{�A�èS���Q�������˪��x�e�E�j�C
LONG);  
        
        set("exits", ([
        "west": __DIR__"warrior2",
        "east": __DIR__"dragon9",
         ]) );
        set("objects", ([
        __DIR__"npc/guard" : 2,
        ]) );
        set("outdoors","workroom.c"); 
        setup();
        replace_program(ROOM);
}
