inherit ROOM;

void create()
{
set("short", "�R����");
        set("long", @LONG
�A�����e��O�@�Ƥ@�Ʈ��A�{�b����ԫ��n�B�A��W���۬��⪺
�ᦷ�A�۷����ءC��s�O�o�̪��~���@�j���~�A��s�P�ɤ]�ΨӻP����s
�άO�p���s�զ������W�S�����ơC���B���ɥi�Hť�������̪��͸��n�A���m
���p�D�K�[�@���n�T�C
LONG
        );
        set("exits", ([
     "northeast":__DIR__"al1",
     "west":__DIR__"al13",
     "south":__DIR__"al3",
]));

        set("outdoors","forest");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
