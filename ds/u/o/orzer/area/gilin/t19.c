inherit ROOM;
void create()
{
        set("short","���F�˪L�F��");
        set("long",@LONG
�A�b�o�̷Pı�Q�n�۷Pı��[�j�P�A�]�]����[���߱��B�ʡA�o��
�U�h�Aı�o���ӧ��A�o�S�����D�ӫ���~�n�A�]�u�n�j�O���U���w��
�����A�˪L�����H�����H���ӵΪA�C
LONG
        );
        set("exits", ([
  "northeast" : __DIR__"t18",
  "south" : __DIR__"t21",
  "southeast" : __DIR__"t20",]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}








