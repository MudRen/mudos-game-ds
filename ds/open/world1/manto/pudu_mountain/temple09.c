inherit ROOM;

void create()
{
        set("short", "�Q�L");
        set("long", @LONG
�N�檺�H���ɼƳQ�_�ݪ��ѩ��ҩڡA���B�Q�L���O������M�C�L����
�ʡA�C�Q�n�̡A�o�]ť����Q�ܤ��n�C�Q�L�����N�S�����A�M�ئӦ�A��
���ߡB�I�B�ճ��y�M�۱o�A���W�����A�Ʀ��٦����b�b�L�����R�A���A�_
���A�ήi�ۦp�A�o�O�ݤ]���ݧA�@���C
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"temple08",
  "east" : __DIR__"temple11",
]));
        set("outdoors","land");
        set("no_clean_up", 0);
        set("light",1);
        setup();
}
