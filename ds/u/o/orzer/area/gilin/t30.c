inherit ROOM;
void create()
{
        set("short","���F�˪L����");
        set("long",@LONG
�A��F���F�˪L���̤����F�A�o�̪�����ܭ��A�|�P�j���@�ѪѪ�
���t�褧��A���D�o�̴N�O���Ѵ©M�e�­x�����Գ��A�q�o�˪���
���I���A�K�]�N�i�H���X��ɾԪp���G�P�A�|�P���۩_�ǥռv�ƿ��C
LONG
        );
        set("exits", ([
        "south" : __DIR__"t31",
        "northeast" : __DIR__"t29",
        ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}












