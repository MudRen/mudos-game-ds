inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", WHT"���}"NOR);
  set("light",1);
        set("long", @LONG

    ���}�O�Ӥg�}�A�����Τs�S�C�}�޸̭��D�n�y�H�A�۶Ǳq�e�}
��b���L�Ŵ����ɡA�`�Ӧ��}Ū�Ѿi�ʡA��֩��ӡC

LONG
        );
    set("exits",([
 "out" : __DIR__"room10",
 "northeast" : __DIR__"room12",
 "southeast" : __DIR__"room16",
]));


        set("no_clean_up", 1);
setup();
        replace_program(ROOM);

}
