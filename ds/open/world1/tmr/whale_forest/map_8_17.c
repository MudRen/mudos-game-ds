inherit ROOM;
void create()
{
	set("short", "���");
        set("long", @LONG
    �A�����b�@�y�μ̾�F��������W�A�@�ۤ���W���ƨS�ͭa����
�l�A���G�o���`���H�ө����ʡC
LONG
);
	set("exits",([
	"south" : __DIR__"map_9_17",
	"north" : __DIR__"map_7_17",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

