inherit ROOM;
void create()
{
        set("short", "�y�����f");
        set("long",@LONG
�A�{�b���b�y���������f�A�γ\�A�|ı�o�o�ӧ����Q�����R�S���W
�S���B�A���L�o�o�O�y�������l�ޤH���B�A�b�@�W�n��ӥͬ���p���g
�N���a��w�g�ܤ֤F�A�]���]���\�h���H������~�󦹡A�]���`�`����
�����a���ǪZ�L���J���۵��j����A�Ӧ��M�W�v���H�]��ö�����A�ӦA
���e�K�O�y�������F�C
LONG
        );
  
  set("objects", 
([__DIR__ "npc/aw-fout" : 1,
    ]));
  set("exits", ([
  "north" : __DIR__"po1.c",
  "south" : __DIR__"po.c",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}

 int valid_leave(object me, string dir)
{
      if( dir=="south" && !userp(me) )
                return notify_fail("���̥u�����a�~��i�h�C\n");
        return ::valid_leave(me, dir);
}



