inherit ROOM;
void create()
{
	set("short", "�d�i");
        set("long", @LONG
�o�̬O�Ȧ檺�����d�i�C�A�ݨ��d�i�᭱���\�h���w�A�o�̪��ٳ�
�D�`���Y�A�|�B�����q���ʵ��A�H�T�O�����̪��]���w���C
	===============================
	�l�B�d��	<balance> 
	�s��		<deposit ���B> 
	����		<withdraw ���B>
	===============================
LONG
);
	set("exits",([
	"east" : __DIR__"map_16_23",
	"south" : __DIR__"map_17_22",
	"north" : __DIR__"map_15_22",
	]));
	set("objects",([
		__DIR__"../npc/malo_banker_15": 1,
	]));
	set("no_fight",1);
	set("no_kill",1);
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
