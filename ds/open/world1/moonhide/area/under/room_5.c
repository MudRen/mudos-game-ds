#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"�a�U�ӥ�"NOR);
        set("long", @LONG
���ǬO�̫�ⶡ�K�Ǥ��@�A���a���O�x�l�A�x�l�̭��˪����O�C
��A��өw�����|���H���F��U�ӡC �o�̪��Ŷ��e�s�\�h,�|�P���@ 
�ǻZ�ΡA�˻V,�窫.. �����A�𨤤W��L�L�z�X����A��ӬO�Ӯ��Y
�j���q���աA����x�����Ӧb�𨤪��@�Ӥj�ˬ֡A�֤����ʤ����W��
�Ӫ��C�W�������j�p���@���G�� �C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"room5",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/finger-guard" : 1, 
 __DIR__"npc/obj/fire-fruit" : 1, 
])); 
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        //replace_program(ROOM);
}

