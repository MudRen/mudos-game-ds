// Room: /u/c/chiaa/hourse/hourse2.c

#include <ansi.h>
inherit ROOM;

void create ()
{
  set("short", "�j�Y���������ɵ���");
  set("long", @LONG
�o�̬O�c��j�Y��������!�̭�������³,�٦��}��!
�٦����v�`�h���w����!
LONG
        );
        set("valid_startroom", 1);
        set("no_magic", 1);
        set("no_die", 1);
  set("exits", ([ /* sizeof() == 1 */
"east" : __DIR__"hourse0",

]));

 setup();
  replace_program(ROOM);
}
