//u/c/chiaa/world2/blackly_forest/trail2.c

#include <path.h>    
inherit ROOM;

void create()
{
        set("short", "�ծ|");
        set("long", @LONG
�o�O�@���˪L�����ծ|,�|�P�L��Ѥ�,���q�J��,�ɾB���u,
��o���t����,�b�ձަ樫,�N���b�©]����⤣��,�[�W�|�g����
�H�N,�������y���]�~��,�x�l�p���H���ȵL�k�A�樫�F!!
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
    "north"   : __DIR__"causeway2",      //�ۤl��2
    
]));
       
            setup();
replace_program(ROOM);
}

