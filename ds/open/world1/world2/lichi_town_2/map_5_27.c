inherit ROOM;
void create()
{
	set("short", "���]�d�i");
        set("long", @LONG
�A�Ө���]���d�i�C�o�ɮ��]�ͷN�Q�������A�a��P�ݿO�ݰ_��
�]�ܰ��šA�L�ǥG�ө����ȫ��y�W�v���ۺ��N�����e�C�d�i���䦳��
�P�l�g��:
	==========================
	�q�Х�	checkin
	�ӫ~�M��	list
	�ʶR�ӫ~	buy <�ӫ~>
	==========================
	
LONG
);
	set("exits",([
	"south" : __DIR__"map_6_27",
	"north" : __DIR__"map_4_27",
	"west" : __DIR__"map_5_26",
	]));
	set("objects", ([
		__DIR__"../npc/malo_inner_12": 1,
	]));
	set("no_fight",1);
        set("valid_startroom", 1);
	set("light",1);
        setup();
}
/*
string query_long(int raw)
{
	string out;
	out=ROOM_D->showmap(this_object());
	out+=query("long");
	return out;
}
*/