inherit __DIR__"waterroom";
void create()
{
 set("short","���w��");
set("long",@LONG
�A�@�Ө즹�a�N�ݨ�a�W��÷�l�A�A�@�ݨ�N�ǳưʧ@�F
�A�ߨ�N�n�Ѱ������A�]����b�O�Ӽ��x���F��F�A���A�Ԥ�
��Q���������A�{�b���G�S������i�H����A�F�A�u�O���~��
�M�٫ܺ����C
LONG
    );
set("item_desc", ([
"÷�l" : "�o�O�@���s������W��÷�l..���G�i�H�⥦��(unsling)\n"
 ]));
set("exits",([
"north":__DIR__"fowater_15", 
"east":__DIR__"fowater_19",]));
set("open_room",__DIR__"fowater_19");
set("move_room",__DIR__"fowater_14");
set("can_go","can_go1");
setroom();
setup();
}             











