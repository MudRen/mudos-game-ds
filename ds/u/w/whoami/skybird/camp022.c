inherit ROOM;

void create()
{
        set("short", "�T�s��");
        set("long", @LONG
�ݨ��礤�h�L���A�������ҩM��W�{�۴H�����M�C�A�A����
�ߤ��t�ġG�p���K�x�A���ǯ��a��L�ġC�A�Q��[�g�w�h���Ѵ�
�x�A�A���ѷn�F�n�Y�C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"camp021",
  "south" : __DIR__"camp023",
]));
        set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

