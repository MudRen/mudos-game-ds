inherit ROOM;

void create()
{
        set("short", "�s�}");
        set("long", @LONG
�A�U���o�s�}�̭����A�N�Uť���즳�H�b�������y���n���A�]���@��
���n�A���ӬO���~���n���a�A�b���䪺���W�������i�H�ݨ�����A�A����
�۳o����A���t����A�o�̱`�|���D�X�S�C
�̭��٦��@�q���C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room4",
  "northeast" : __DIR__"room2",
]));
        set("objects", ([ /* sizeof() == 1 */
          __DIR__"snake" : 2,
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();

}

