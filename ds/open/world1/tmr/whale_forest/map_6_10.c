inherit ROOM;
void create()
{
	set("short", "���");
        set("long",@long
    �A�����b�@�y�μ̾�F��������W�A�@�ۤ���W���ƨS�ͭa���ˤl�A
���G�o���`���H�ө����ʡC���U���e�������a�y�L�h�A�����W�X������
���B���I���H���y���ʡC
long
);


	set("exits",([
	"west" : __DIR__"map_6_9",
	"east" : __DIR__"map_6_11",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}

