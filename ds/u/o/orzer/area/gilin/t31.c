inherit ROOM;
void create()
{
        set("short","���F�˪L����");
        set("long",@LONG
�A�C�C���¦V�˪L�`�B���h�A�o�̪�����ܭ��A�|�P�j���@�ѪѪ�
���t�褧��A���B�Ǩӽw�w�������n�A�i�O�S�Pı����b�I�ͤH����
�A�쩳�쩳�O����F��b���ʵۡA���𺥺��ର�@�p�C
LONG
        );
        set("exits", ([
        "southwest" : __DIR__"t32",
        "north" : __DIR__"t30",
        ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}













