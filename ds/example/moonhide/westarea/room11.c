inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�o�̬ݰ_�ӬO�@������ , �s�j�L�� , ���O���������ݪ��� , ����
������ , ���@�ӥW�� , ���O�@�������� , ���F�o�� ,�N�S���䥦����
���S�x�F�C
�o�̬ݤ��X�Ӧ�������C
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"room12",
  "southwest" : __DIR__"room10",
]));
        set("light",1);
        setup();
        replace_program(ROOM);
}

