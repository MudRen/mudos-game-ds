inherit __DIR__"waterroom";
void create()
{
 set("short","���w��");
set("long",@LONG
�A�ݨ�a�W���ۤ@��÷�l�A�A���~�I�L�@�˪������A��
��N���D�n�p��ʧ@�A�]���ܰ������ӵۭ�谵�k�K�Ѷ}�F��
���A�{�b���G�S������i�H����A�F�A�u�O���~�̵M�٫ܺ���
�C
LONG
    );
set("item_desc", ([
"÷�l" : "�o�O�@���s������W��÷�l..���G�i�H�⥦��(unsling)\n"
 ]));
set("exits",([
"north":__DIR__"fowater_11", 
"southwest":__DIR__"fowater_13",]));
set("open_room",__DIR__"fowater_13");
set("move_room",__DIR__"fowater_8");
set("can_go","can_go2");
setroom();
setup();
}             










