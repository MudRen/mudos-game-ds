inherit ROOM;

void create()
{
        set("short", "�T�s��p�g�C");
        set("long", @LONG
�o�̬O�@�Ӥp�g�C�A�Q�n�Ϧb�T�s��̪��x�L�̮��ӷ��{��
���U�����I�a�A��M�]�O�����ήƪ������a�I�C����[�۴X�Ӥ�
�O�f�ت�²��ť�B�a�C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"camp006",
]));
        set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

