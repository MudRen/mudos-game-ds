inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", WHT"���Τs�s�U"NOR);
        set("no_fight", 1);
  set("light",1);
        set("long", @LONG

    �@���W�A�`�L�⪺�_�p�U�A�Ѻ񪺻���ˤ��A�����S�X�X�B�¥˥�
��C�������ϩ��O���۫p�����v���¥ˡA�βM�����a�g�A�J�`�辮���S²
����A�A���H���o�������~��䶡���D�H�C�u�~���������w�ߺD�F��ö��
�����ȫȡA�y�M�a���b�a���f�ݵۭ��й������ȤH�C

LONG
        );
    set("exits",([
 "northwest" : __DIR__"room05",
 "eastup" : __DIR__"room07",
 "south" : __DIR__"room08",
]));

        set("objects", ([ 
  __DIR__"mob01" : 1,
]));


        set("no_clean_up", 1);
setup();
        replace_program(ROOM);

}
