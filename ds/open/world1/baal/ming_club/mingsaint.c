inherit ROOM;
void create()
{
 set("short","���иt�a");
 set("long",@LONG
�o�̬O���бХD�B�����t�ϩM�U��D�Q�ױФ��j�ƪ��a��A�t�a
�������q�ߵ۶������t���A���W���F�@�ӡi���j�r�A�U�~�������t��
�ӫG�ۥ|�P�A����ﺡ�F�_�ò��_�A�|�P�ƺ��F�@�Ӥ@�ӥ۸O�A�W��
�誺���O�U�������W���ߪk�A�䤤���@�ӥ۸O�S�O���j�A�W����۩�
�Ф������H�������K�C
LONG
    );
 set("exits",([ "down": __DIR__"fire",
             "up": __DIR__"leaderroom",
    ]));
        set("objects", ([
                __DIR__"box.c" : 1,
        ]));

        set("no_kill",1);
        set("light",1);
 setup();
        set("stroom",1);
}
int valid_leave(object me, string dir)
{
        if( dir=="up" && CLUB_D->check_member("ming",getuid(me))  < 5&&wizardp(me)&&CLUB_D->check_member("sky",getuid(me))<6 )
                return notify_fail("�D���D����i�J���D�M�ζ��C\n");
        return ::valid_leave(me, dir);
}
//edit by -jangshow
//�o�̸Ӧ���board
//have �t�������O(Fire-secret board)
//no describe

