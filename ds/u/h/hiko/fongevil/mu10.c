inherit ROOM;
void create()
{
        set("short", "�s�D");
        set("long",@LONG
�A�w�g�i�H�ݲM���s�W�������F�A�@��ӥh�ҬO���X�A�ӥB�@��諸
�������h�A��Ӧ��a�O�ø����A�J�ӷPı���M���ǳ��ˡA�O�A���ǥ��ǫe
�i�����Y�A�_�䦳�@�������s�^�A�F�n��h�O�U�s�C
LONG
        );
  
set("exits", ([
  "northup" : __DIR__"zk22",
  "southeast" : __DIR__"mu9",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}
 





