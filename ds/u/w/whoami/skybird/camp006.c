inherit ROOM;

void create()
{
        set("short", "�T�s������");
        set("long", @LONG
�׫ع�l���ɭԡA¶�۹�l�@�P���F��T�V�`������A�M��
�ެu����J�A�T�s��J���a�ժ��u�աA�S���@���e�ڼġA�O�@�y
�ᬰ���n�����S�C�i���]����l�Ӱ�T�A�ҥH�ح��n�u���x���j
�h���O�B�L�C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"camp005",
  "south" : __DIR__"camp007",
]));
        set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

