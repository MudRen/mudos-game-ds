inherit ROOM;

void create()
{
        set("short", "�s�}");
        set("long", @LONG
�o�Ӥs�}�u�O�L�񪺥��j�A�ӥB�}�����D�`������A�����O�ѵM���}
�ޡA���A�p�Q����b�}�~�ݨ쪺�u�j�ӡv�G�r�A�@�w�O���H�سy���A�Q
��o�A�N���A���_�@�Ѳ��W�����ġA�Q�n�@���}���O�_�٦��H�C
�̭��٦��@�q���C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"room3",
  "east" : __DIR__"room1",
]));
        set("objects", ([ /* sizeof() == 1 */
          __DIR__"statue" : 1,
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();

}


