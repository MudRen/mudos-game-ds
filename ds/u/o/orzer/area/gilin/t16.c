inherit ROOM;
void create()
{
        set("short","���F�˪L�F��");
        set("long",@LONG
�o�̤w�g�Z����˪L���̪F���A�H��S�����@����z�A�F����G��
�D�p�s��ˤl�A�Ӧ�_�h�O�i�H�~��e�i�A�Pı���G���@�D�H�v�ƹL
���e�A�o�S�ܹ��O��ı�A���A�@�ɦ�����j�C
LONG
        );
        set("exits", ([
  "east" : __DIR__"t25",
  "northwest" : __DIR__"t17",
  "southwest" : __DIR__"t15",]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}











