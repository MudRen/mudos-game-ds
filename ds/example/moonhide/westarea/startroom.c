#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�o�̬O���ݪ��̧��� , ���U�@�� , ���a�U�� , ���Y�@�� 
, �E��d�� , �u���o�̪��P�� , ��¶������������ , ���د�
�t���i�I�Ǫ��Pı , �p�G�A�b�o�̰��F����[0;7;31m�[7ma[7m�[7m�[0m ,�i��|�D��
����� �C �o�̦��@�L�J�� �C

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"room1",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"statue" : 1,
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

