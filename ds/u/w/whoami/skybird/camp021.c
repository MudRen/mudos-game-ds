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
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"camp020",
  "south" : __DIR__"camp022",
  "west" : __DIR__"camp017",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"mob/camp_guard" : random(2)+1,
  ]));
        set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

