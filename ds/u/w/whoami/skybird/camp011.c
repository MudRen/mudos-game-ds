inherit ROOM;

void create()
{
        set("short", "�T�s��x�k�B");
        set("long", @LONG
�e�����Ŧa�W���۴X�[�����A���O���H�x���X���ɨϥΪ��G
�ѦD��C�������䦳�ܦh�@�H�h������[�A�W����񴳴��A���O
�@���ǤH�Ϊ��C
LONG);
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"camp012",
]));
        set("light",1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

