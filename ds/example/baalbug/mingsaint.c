inherit ROOM;
void create()
{
 set("short","���иt�a");

 set("long",@LONG
�o�̬O���бХD�B�����t�ϩM�U��D�Q�ױФ��j�ƪ��a��A�t�a��
�����q�ߵ۶������t���A���W���F�@�ӡi���j�r�A�U�~�������t��
�ӫG�ۥ|�P�A����ﺡ�F�_�ò��_�A�|�P�ƺ��F�@�Ӥ@�ӥ۸O�A�W
���誺���O�U�������W���ߪk�A�䤤���@�ӥ۸O�S�O���j�A�W����
�۩��Ф������H�������K�C
LONG
    );
 set("exits",([ "test":"/open/world1/tmr/area/hotel",
    ]));
        set("no_kill",1);
        set("light",1);
 setup();
  call_other("/obj/board/ming_fire_secret_b" , "???");
        set("stroom",1);
}
//�o�̸Ӧ���board
//have �t�������O(Fire-secret board)
//no describe
