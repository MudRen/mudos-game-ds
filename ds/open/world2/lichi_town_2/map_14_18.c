inherit ROOM;
void create()
{
	set("short", "�D�㩱�d�i");
        set("long", @LONG

  �y��          �z�w�w�w�w�w�w�{            �Ģj
  �����j        �x�u �} �� �� �x          �y����
�������j      �Ģ|�w�w O�w�w�w�}��        �y������
�i�����j      ����    /Y\     ����        �y�����i
�i�����j      �i���áááááâ��i        �y�����i
�i�����áááâ��i�i�i�i�i�i�i�i���ááááâ����i
�i��            ���i�i�i�i�i�i��              ���i
��                                              ��
LONG
);
	set("exits",([
	"east" : __DIR__"map_14_19",
	"north" : __DIR__"map_13_18",
	"west" : __DIR__"map_14_17",
	]));
	set("objects", ([
		__DIR__"../npc/malo_itemboss_17" : 1,
	]));
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
