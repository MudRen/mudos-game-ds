//u/c/chiaa/world2/blackly_forest/path2.c

#include <path.h>
inherit ROOM;
void create()
{
        set("short", "�p�|");
        set("long", @LONG
�o�O�@���ᤣ�������p�|,������U�i���L�ƨB���e,
�樫�䶡,�N���O�b��P�𤧶����Żئ樫,���_�褣���B�i�ݨ�@�B�Ŧa,
�p�G���֤F,�����쨺���ƥ�!!
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
     "west"       : __DIR__"road4",        //�L���p��4
     "north"      : __DIR__"causeway1",    //�ۤl��1
     "south"      : __DIR__"road7",        //�L���p��7
     "northwest"  : __DIR__"vacancy1",     //�L���Ŧa1
]));
       
            setup();
replace_program(ROOM);
}
