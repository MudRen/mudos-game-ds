inherit ROOM;
void create()
{
        set("short", "�y������f");        
        set("long",@LONG
�y��������f�èS�Q�������Q���j�A�]�S�ݨ�\�h�j��A�y������
�����Ҿa���O�ҿת��g��M�ޥ��A�ҥH�èS���Q���̾a���㪺�ߺD�A��
�@��a�ۦn�ʯ઺�j��A�o���F�Ѯ����S�ʪ����Ҥ��P�A�L�̲`���p��
�b���W�Q�ͬ����@�����ѡC
LONG
        );
        set("exits", ([
  "north" : __DIR__"po6-1",
  "south" : __DIR__"po5"
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}




int valid_leave(object me, string dir)
{
      if( dir=="north" && !userp(me) )
                return notify_fail("���̥u�����a�~��i�h�C\n");
        return ::valid_leave(me, dir);
}






