inherit ROOM;
void create()
{
	set("short", "���㩱�d�i");
        set("long", @LONG

  �y��          �z�w�w�w�w�w�w�{            �Ģj
  �����j        �x  ��    ��  �x          �y����
�������j      �Ģ|�w�w O�w�w�w�}��        �y������
�i�����j      ����    /Y\     ����        �y�����i
�i�����j      �i���áááááâ��i        �y�����i
�i�����áááâ��i�i�i�i�i�i�i�i���ááááâ����i
�i��            ���i�i�i�i�i�i��              ���i
��                                              ��
LONG
);
	set("exits",([
	"east" : __DIR__"map_7_13",
	"south" : __DIR__"map_8_12",
	"north" : __DIR__"map_6_12",
	]));
	set("objects", ([
		__DIR__"../npc/malo_eqboss_18":1,
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
