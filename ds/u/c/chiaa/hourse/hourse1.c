// Room: /u/c/chiaa/hourse/hourse1.c

#include <ansi.h>
inherit ROOM;

void create ()
{
  set("short", "�j�Y�����o�b��");
  set("long", @LONG
���ɭԦb�j�Y����Ū�ѫǥθ��L��!�N�|�Q��o�̨ӵo�o�b!
���j���𮧤@�U�U,�]��z�@�U���!�A�~��V�O!
LONG
        );
        set("valid_startroom", 1);
        set("no_magic", 1);
        set("no_die", 1);
  set("exits", ([ /* sizeof() == 1 */
"out" : __DIR__"hourse0",

]));


 setup();
  replace_program(ROOM);
}
