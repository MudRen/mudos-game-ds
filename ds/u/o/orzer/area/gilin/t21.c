inherit ROOM;
void create()
{
        set("short","���F�˪L�F��");
        set("long",@LONG
�A�Ө�F�˪L�������A�o�̦A���e�i���G��[���H�A�]���A���Ӧ�
��k���R���e�i�A�o�S�����D�ӫ���~�n�A�]�u�n�j�O���U���w����
���A�o�̪��D���_�ǨӡC
LONG
        );
        set("exits", ([
  "west" : __DIR__"t22",
  "north" : __DIR__"t19",
   ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}









