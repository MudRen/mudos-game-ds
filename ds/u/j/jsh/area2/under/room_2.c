#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"�a�U�ӥ�"NOR);
        set("long", @LONG 
��M�̪ťX�{�@�κѺ��C���A���W���U�w�w�a�Ʋ��A�չϻ���
�o�̪��H�A��M�S�̪Ť����F�A�~���A���L���A�@�ߥu�Q���}�o�C
�o�̪������H�n�������Ȱ��Ǫ��C
LONG
        );
        set("exits", ([ /* sizeof() ==  */
  "northeast" : __DIR__"room2",]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/neck-guard" : 1,
]));
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


