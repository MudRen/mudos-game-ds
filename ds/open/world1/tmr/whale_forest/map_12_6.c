inherit ROOM;
void create()
{
	set("short", "���");
        set("long", @LONG
    �A�����b�@�y�μ̾�F��������W�A�@�ۤ���W���ƨS�ͭa���ˤl�A
���G�o���`���H�ө����ʡC���U���e�������a�y�L�h�A�����W�X������
���B���I���H���y���ʡC�L���j�Ӥ@�}�M�x�x�����C
LONG
);
	set("exits",([
	"south" : __DIR__"map_13_6",
	"north" : __DIR__"map_11_6",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

