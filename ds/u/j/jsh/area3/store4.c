inherit ROOM;

void create()
{
        set("short", "�B�F����");
        set("long", @LONG 
�o�u�O�B�F���̤j�a���{���n�u�l�A�o�̩ҥ��y�X�Ӫ��Z���A�i�H
���O�n�� !�u�c�����_���s��A�s�檺�{�״X�G���ӥ������n���n
���\�F�L�h�A�i���ͷN�n�����o�F�C
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"store2", 
  "north" : __DIR__"store6",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"storeman4" : 1,
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

