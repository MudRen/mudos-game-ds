inherit ROOM;
void create()
{
        set("short", "�y�������y");        
        set("long",@LONG
�o�̬O�w�g�O���y�����ݡA���y�W���ͪ��]������֤F�A���񪺤H
�̤]�S����診��h�F�A�Өƹ�W�o�̪�����o�O�̩y�H�A�ѩ�֤H��
�ϱo�o�̪��ѵM�ˤl�Q�������A�|�P�����ŦU���S��A�Ӯ����n����ŧ
�����H�P��ܥ��R�C
LONG
        );
        set("exits", ([
   "northwest" : __DIR__"se4",
   "north" : __DIR__"se6", 
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}









